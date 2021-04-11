/* optparse.cc */

#include <alpm.h>
#include <cctype>
#include <cstdlib>
#include <string>
#include <vector>
#include <string.h>
#include <fstream>

#include "option.h"
#include "database.h"
#include "configure.h"
#include "optparse.h"

struct pair {
    string key;
    string value;
};

/* remove <space> at the head and tail of string */
static string __strip_space(string str)
{
    if(str.size()==0 || (str[0] == ' ' && str[str.size()-1] == ' ')) return str;
    auto lp = str.find_first_not_of(' ');
    auto rp = str.find_last_not_of(' ');
    return str.substr(lp, rp-lp+1);
}

/* remove comment */
static string __strip_comment(string str)
{
    auto comment = str.find_first_of('#');
    if ( comment != str.npos){
       str = str.substr(0,comment); 
    }
    str = __strip_space(str);
    return str;
}

/* splict string with '=' */
static pair* __split_line(string str, char splitor)
{
    auto index = str.find_first_of(splitor);
    pair* p = new pair();
    if( index == str.npos){
        p->key = __strip_space(str);
        return p;
    }
    else {
        p->key = __strip_space(str.substr(0,index));
        p->value = __strip_space(str.substr(index+1));
    }
    return p;
}

static void __parse_db_server(DataBase* db, string url)
{
    db->add_server(url);
}

/* read file to get database servers */
static void __parse_db_include(DataBase* db, string file_path)
{
    std::ifstream fs(file_path);
    if (!fs.is_open()){
        LOG << "[W] optparse: cann't open file: " << file_path ;
        return ;
    }
    string buf;
    while (getline(fs, buf)){
        buf = __strip_comment(buf);
        __parse_db_server(db, buf);
    }
    fs.close();
}

static void __parse_db_siglevel(DataBase* db, alpm_siglevel_t sig)
{
    db->set_siglevel(sig);
}

static void __parse_db(DataBase* db, string str)
{
    pair* p = __split_line(str, '=');
    if(p->key == "Server"){
        __parse_db_server(db, p->value);
    }
    else if(p->key == "Include"){
        __parse_db_include(db, p->value);
    }
    else if(p->key == "SigLevel"){
        // use default siglevel
        __parse_db_siglevel(db, ALPM_SIG_USE_DEFAULT);
    }
    delete p;
}


static Option* __parse_options(string str)
{
    pair* p = __split_line(str, '=');
    Option* opt = nullptr;
    if (p->key == "RootDir"){
        opt = new RootDirOpt(p->value);
    }
    else if (p->key == "DBPath"){
        opt = new DBPathOpt(p->value);
    }
    else if (p->key == "CacheDir"){
        opt = new CacheDirsOpt(p->value);
    }
    else if (p->key == "LogFile"){
        opt = new LogFileOpt(p->value);
    }
    else if(p->key == "GPGDir") {
        opt = new GPGDirOpt(p->value);
    }
    else if (p->key == "HookDir"){
        opt = new HookDirsOpt(p->value);
    }
    else if (p->key == "HoldPkg"){
        opt = new HookDirsOpt(p->value);
    }
    else if (p->key == "Architecture") {
        opt = new ArchOpt(p->value);
    }
    else if(p->key == "IgnorePkg"){
        opt = new IgnorePkgsOpt(p->value);
    }
    else if(p->key == "IgnoreGroup"){
        opt = new IgnoreGrpOpt(p->value);
    }
    else if(p->key == "NoUpgrade"){
        opt = new NoUpgradesOpt(p->value);
    }
    else if(p->key == "NoExtract"){
        opt = new NoExtractsOpt(p->value);
    }
    delete p;
    return opt;
}
static Option* __parse_sentence(DataBase* db, string str)
{
    if ( db != nullptr){
        __parse_db(db,str);
        return nullptr;
    }
    else {
        return __parse_options(str);
    }
}

OptionPtr OptParser::parse_sentence(string sentence) {

  sentence = __strip_comment(sentence);

  auto lp = sentence.find_first_of('[');
  auto rp = sentence.find_last_of(']');
  // switch state
  if (lp != sentence.npos && rp != sentence.npos) {
    DataBase *_temp = db_;
    db_ = nullptr;
    string _str = sentence.substr(lp + 1, rp - lp - 1);
    if (_str == "options") {
      state_ = State::OPTIONS;
    } else {
      // database
      DataBase *db = new DataBase(_str);
      db_ = db;
      state_ = State::DATABASE;
    }
    OptionPtr db;
    db.reset(db_);
    return db;
  }
  if (state_ != State::INITIALIZE) {
    OptionPtr db;
    db.reset(__parse_sentence(db_, sentence));
    return db;
  }
  return OptionPtr();
}

vector<OptionPtr> OptParser::parse_file(string file) {
  std::ifstream fs(file);
  if (!fs.is_open()) {
    LOG << "[W] optparse: open file error: " << file;
    return vector<OptionPtr>();
  }
  string buf;
  vector<OptionPtr> vec;
  while (getline(fs, buf)) {
    OptionPtr opt = parse_sentence(buf);
    if (opt)
      vec.push_back(opt);
  }

  // ensure the last database option was returned
  buf = "[options]";
  OptionPtr opt = parse_sentence(buf);
  if (opt)
    vec.push_back(opt);
  return vec;
}
