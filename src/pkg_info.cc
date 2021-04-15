#include <QDateTime>

#include "dialog.h"
#include "pkg_info.h"
#include "pkg_note.h"
#include "ui/ui_pkginfo.h"

#include "pm2/package.h"

#include <alpm.h>
#include <string>

#define FILE_NUM 3000

PkgInfo::PkgInfo(Package::PackagePtr pkg, QWidget *parent)
    : package_(pkg), ui(new Ui::pkginfo) {
  ui->setupUi(this);
  this->setWindowTitle(QString(package_->get_name().c_str()));

  /* connect */
  connect(ui->install, SIGNAL(clicked()), this, SLOT(slot_install()));
  connect(ui->remove, SIGNAL(clicked()), this, SLOT(slot_remove()));
  connect(ui->detail, SIGNAL(clicked()), this, SLOT(slot_detail()));
  connect(ui->depend, SIGNAL(clicked()), this, SLOT(slot_depend()));
  connect(ui->files, SIGNAL(clicked()), this, SLOT(slot_files()));
  connect(ui->check_deps, SIGNAL(clicked()), this, SLOT(slot_c_deps()));
  connect(ui->check_files, SIGNAL(clicked()), this, SLOT(slot_c_files()));
  connect(ui->add_note, SIGNAL(clicked()), this, SLOT(slot_add_note()));

  ui->install->setShortcut(Qt::Key_I);
  ui->remove->setShortcut(Qt::Key_R);
  ui->add_note->setShortcut(Qt::Key_A);
  ui->depend->setShortcut(Qt::Key_D);
  ui->files->setShortcut(Qt::Key_F);
  ui->check_files->setShortcut(Qt::Key_K);
  ui->check_deps->setShortcut(Qt::Key_J);
  ui->detail->setShortcut(Qt::Key_T);

  ui->name->setText(QString(package_->get_name().c_str()));
  ui->desc->setText(QString(package_->get_desc().c_str()));

  ui->scrollAreaWidgetContents->setSizePolicy(QSizePolicy::Preferred,
                                              QSizePolicy::Fixed);
  emit ui->detail->clicked();
}
void PkgInfo::add_file_name(QString &text, alpm_list_t *list) {
  alpm_list_t *i;
  for (i = list; i; i = alpm_list_next(i)) {
    text += QString((char *)i->data) + "\n";
  }
}
void PkgInfo::add_depend_name(QLayout *layout, alpm_list_t *list) {
  QString text;
  alpm_depend_t *dep;
  alpm_list_t *i;
  for (i = list; i; i = alpm_list_next(i)) {
    dep = (alpm_depend_t *)i->data;
    text += "<a href='";
    text += QString(dep->name);
    text += "'>";
    text += QString(dep->name);
    text += "</a>";
    QLabel *tmp = new QLabel();
    tmp->setText(text);
    layout->addWidget(tmp);
    connect(tmp, SIGNAL(linkActivated(QString)), this,
            SLOT(slot_newinfo(QString)));
    text.clear();
  }
  return;
}
void PkgInfo::add_pkg_name(QLayout *layout, alpm_list_t *list) {
  QString text;
  alpm_list_t *i;
  for (i = list; i; i = alpm_list_next(i)) {
    alpm_pkg_t *p = (alpm_pkg_t *)i->data;
    text += "<a href='";
    text += QString(alpm_pkg_get_name(p));
    text += "'>";
    text += QString(alpm_pkg_get_name(p));
    text += "(installed)";
    text += "</a>";
    QLabel *tmp = new QLabel();
    tmp->setText(text);
    connect(tmp, SIGNAL(linkActivated(QString)), this,
            SLOT(slot_newinfo(QString)));
    layout->addWidget(tmp);
    text.clear();
  }
  return;
}

PkgInfo::~PkgInfo() { delete ui; }

/*---------------SLOT FUNCTION---------------*/
void PkgInfo::slot_install() { this->close(); }
void PkgInfo::slot_remove() {}
void PkgInfo::slot_detail() {}
void PkgInfo::slot_depend() {}
void PkgInfo::slot_files() {}
void PkgInfo::slot_c_files() {}
void PkgInfo::slot_c_deps() {}
void PkgInfo::slot_add_note() {}
void PkgInfo::slot_newinfo(QString pkgName) {}
