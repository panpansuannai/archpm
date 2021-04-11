#pragma once
#include <QWidget>

#include "pm2/package.h"

namespace Ui {
class pkgentry;
}

class PkgEntry : public QWidget {
  Q_OBJECT
public:
  explicit PkgEntry(Package::PackagePtr);
  ~PkgEntry();
signals:
  void sig_remove_pkg();
  void sig_install_pkg();
public slots:
  void show_pkg_info();
  void install_pkg();
  void remove_pkg();

private:
  Ui::pkgentry* ui;
};

