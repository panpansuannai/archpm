/* database.cc */

#include <alpm.h>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

#include "database.h"
#include "package.h"

Package::PackagePtr DataBase::get_pkg_by_name(string name) {
  alpm_pkg_t *pkg = alpm_db_get_pkg(db_, name.c_str());
  return std::make_shared<Package>(Package(pkg));
}
Package::PackagePtr DataBase::get_pkg_by_str(string str) {
  return get_pkg_by_name(str);
}
vector<Package::PackagePtr> DataBase::search_by_str(string str) {
  // TODO
  // return nullptr;
}

Package::PackagePtr DataBase::get_grp_by_name(string str) {
  // TODO
  // return Package();
  alpm_group_t *grp = alpm_db_get_group(db_, str.c_str());
  return std::make_shared<Package>(Package(grp));
}
bool DataBase::update() {
  int ret = alpm_db_update(1, db_);
  if (ret) {
    LOG << "[W] DataBase: update database error!" << name_;
    return false;
  }
  return true;
}

static string __replace_string(string str, string from, string to) {
  int index = 0;
  if ((index = str.find(from)) != str.npos) {
    string new_str = str.substr(0, index);
    new_str += to;
    new_str += str.substr(index + from.size());
    return new_str;
  } else
    return str;
}

static string __replace_server_url(string server, string dbname) {
  string new_str = __replace_string(server, REP_ARCH, DEF_ARCH);
  new_str = __replace_string(new_str, REP_REPO, dbname);
  return new_str;
}

bool DataBase::do_opt(alpm_handle_t *handle) {
  db_ = alpm_register_syncdb(handle, name_.c_str(), siglevel_);
  if (!db_) {
    LOG << "[W] DataBase: register database error :" << name_;
    valid_ = false;
  }
  valid_ = true;

  // Add servers
  for (size_t i = 0; i < servers_.size(); ++i) {
    string &_s = servers_[i];
    _s = __replace_string(_s, REP_ARCH, alpm_option_get_arch(handle));
    _s = __replace_string(_s, REP_REPO, name_);
    alpm_db_add_server(db_, _s.c_str());
  }
  return true;
}
std::vector<Package::PackagePtr> DataBase::get_all_packages() {
  alpm_list_t *pkg_list = alpm_db_get_pkgcache(db_);
  std::vector<Package::PackagePtr> vec;
  for (; pkg_list; pkg_list = alpm_list_next(pkg_list)) {
    alpm_pkg_t *pkg = (alpm_pkg_t *)pkg_list->data;
    Package::PackagePtr package = std::make_shared<Package>(pkg);
    vec.push_back(package);
  }
  return vec;
}
DataBase::DataBase(string name) : name_(name) {
  valid_ = false;
  db_ = nullptr;
}
DataBase::~DataBase() {}
