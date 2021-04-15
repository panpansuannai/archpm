#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>

#include <memory>

#include "monitor.h"
#include "pm2/configure.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class mainwindow;
}
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
  Q_OBJECT

public:
  mainwindow(QWidget *parent = nullptr);
  ~mainwindow();
public slots:
  /* when the search button clicked */
  void slot_search();
  /* get the installed pkgs */
  void slot_get_installed();
  /* database update */
  void slot_database_update();
  /* config */
  void slot_configure();
  /* orphans */
  void slot_get_orphans();
  /* system update */
  void slot_sysupdate();
  /* about infomation */
  void slot_about();
  /* rm database lock file */
  void slot_fixlock();
  /* check dependencies */
  void slot_get_depend();
  /* cleanup the display */
  void slot_clean_result();
  /* when click install all */
  void slot_install_page();
  /* when click remove all */
  void slot_remove_page();

private:
  std::unique_ptr<Configure> config_;
  std::vector<std::shared_ptr<DataBase>> databases_;
  QLabel *msg_;
  std::shared_ptr<Monitor> monitor_;
  Ui::mainwindow *ui;
};
#endif // MAINWINDOW_H
