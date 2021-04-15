#include "pkg_entry.h"
#include "dialog.h"
#include "pkg_info.h"
#include "pm2/database.h"
#include "ui/ui_pkgentry.h"

#include <alpm.h>
#include <cstring>
#include <string>

using std::string;

PkgEntry::PkgEntry(Package::PackagePtr package) : ui(new Ui::pkgentry) {
  ui->setupUi(this);

  string db_name = package->get_db()->get_name();
  ui->db->setText(QString(db_name.c_str()));

  ui->pkg_name->setText(QString(package->get_name().c_str()));
  ui->pkg_desc->setText(QString(package->get_desc().c_str()));
  ui->version->setText(QString(package->get_ver().c_str()));

  /* click the pkg entry */
  connect(ui->info, SIGNAL(clicked()), this, SLOT(show_pkg_info()));
  connect(ui->remove, SIGNAL(clicked()), this, SLOT(remove_pkg()));
  connect(ui->install, SIGNAL(clicked()), this, SLOT(install_pkg()));
}

void PkgEntry::show_pkg_info() {}

void PkgEntry::install_pkg() {}
void PkgEntry::remove_pkg() {}
PkgEntry::~PkgEntry() { delete ui; }
