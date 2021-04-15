/* database.h */

#pragma once

#include <alpm.h>
#include <alpm_list.h>

#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

#include "log.h"
#include "option.h"
#include "package.h"

using std::string;
using std::vector;

#define OPTID_DB 0x2000
/*  DataBase */
class DataBase : public Option {
public:
  using DataBasePtr = std::shared_ptr<DataBase>;
  using PackagePtr = Package::PackagePtr;

private:
  /* can only be called by OptParse */

  /* members */
  bool valid_; // mark true if do_opt() called
  string name_;
  alpm_db_t *db_;
  std::vector<Package::PackagePtr> pkgs_;
  std::vector<Package::PackagePtr> grps_;
  std::vector<string> servers_;
  alpm_siglevel_t siglevel_;

  DataBase(const DataBase &) = delete;
  DataBase operator=(const DataBase &) = delete;

public:
  friend class OptParser;
  DataBase(string name);
  ~DataBase();
  virtual bool do_opt(alpm_handle_t *handle) override final;
  virtual int get_id() override { return OPTID_DB; }

  /* get package by name */
  string get_name() { return name_; }
  PackagePtr get_pkg_by_name(string);
  PackagePtr get_pkg_by_str(string);
  PackagePtr get_grp_by_name(string);
  std::vector<PackagePtr> search_by_str(string);
  std::vector<PackagePtr> get_all_packages();

  /* Sync database */
  bool update();

  void set_siglevel(alpm_siglevel_t sig) { siglevel_ = sig; }
  void add_server(string url) { servers_.push_back(url); }
};
