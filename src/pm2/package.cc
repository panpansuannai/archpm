/* package.cc */

#include <string.h>

#include "package.h"
#include "log.h"

string Package::get_note_from_fs()
{
    string ret;
    string note_path = DEF_NOTEPATH;
    note_path = note_path + this->name_;
    std::ifstream fs;
    fs.open(note_path,std::ofstream::in);
    if(!fs.is_open()){
        return ret;
    }
    fs >> ret;
    fs.close();
    return ret;
}
bool Package::set_note(string note)
{
    string note_path = DEF_NOTEPATH;
    note_path = note_path + this->name_;
    std::ofstream fs;
    fs.open(note_path,std::ofstream::out|std::ofstream::trunc);
    if(!fs.is_open()){
        LOG << "[W] Package: set note error: " << name_;
        return false;
    }
    fs << note << std::endl;
    fs.close();
    return true;
}
Package::Package(alpm_pkg_t* pkg):pkg_(pkg)
{
    valid_ = false;
    is_grp_= false;
    name_ = alpm_pkg_get_name(pkg);
    desc_ = alpm_pkg_get_desc(pkg);
    version_ = alpm_pkg_get_version(pkg);
    url_ = alpm_pkg_get_url(pkg);
    build_date_ = alpm_pkg_get_builddate(pkg);

}
Package::Package(alpm_group_t* group)
{
    valid_ = false;
    is_grp_ = true;
    name_ = group->name;
    grp_ = group->packages;
}
/*
Package::Package(Package& pkg)
{
    name_ = pkg.get_name();
    desc_ = pkg.get_desc();
    version_ = pkg.get_ver();
    url_ = pkg.get_Url();
    build_date_ = pkg.get_build_date();
    note_ = pkg.get_note();
    is_grp_ = pkg.is_group();
    valid_ = pkg.valid();
    if(is_grp_){
        grp_ = pkg.grp_;
    }
    else 
        pkg_ = pkg.pkg_;
}
*/
Package::Package()
{
    valid_ = false;
    is_grp_ = false;
}
