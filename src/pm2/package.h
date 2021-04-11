#pragma once

#include <alpm.h>
#include <alpm_list.h>

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "configure.h"
#include "log.h"

using std::string;

class DataBase;

class Package {
private:
  string name_;
  string desc_;
  string version_;
  string url_;
  string build_date_;
  string note_;
  std::shared_ptr<DataBase> belong_db_;
  bool is_grp_;
  bool valid_;
  union {
    alpm_pkg_t *pkg_;
    alpm_list_t *grp_;
  };

public:
  Package(alpm_pkg_t *);
  Package(alpm_group_t *);
  Package();

  string get_name() { return name_; }
  string get_desc() { return desc_; }
  string get_ver() { return version_; }
  string get_Url() { return url_; }
  string get_build_date() { return build_date_; }
  bool is_group() { return is_grp_; }
  bool valid() { return valid_; }

  /* package notes */
  string get_note() { return note_; }
  string get_note_from_fs();
  bool set_note(string);

  /* compare version */
  bool operator<(Package &p) { return ver_cmp(p); }

  bool ver_cmp(Package &p) { return ver_cmp(*this, p); }
  bool ver_cmp(Package &a, Package &b) {
    if (a.is_group() || b.is_group())
      return false;
    if (!a.valid() || !b.valid())
      return false;
    int ret = alpm_pkg_vercmp(a.get_ver().c_str(), b.get_ver().c_str());
    if (ret)
      return true;
    else
      return false;
  }

  void database_tag(std::shared_ptr<DataBase> db) { belong_db_ = db; }

  std::shared_ptr<DataBase> get_db() { return belong_db_; }

public:
  using PackagePtr = std::shared_ptr<Package>;
};
