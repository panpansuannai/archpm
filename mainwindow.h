#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "display.h"

#include "pm/interface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow
{
        Q_OBJECT

public:
        operation* op;
        display* dis;
        QLabel *msg;

        void set_s_db();

        mainwindow(QWidget *parent = nullptr);
        ~mainwindow();
public slots:
        /* when the search button clicked */
        void slot_main_search();
        /* get the installed pkgs */
        void slot_main_installed();
        /* database update */
        void slot_main_db_update();
        /* config */
        void slot_main_configure();
        /* orphans */
        void slot_main_orphans();
        /* system update */
        void slot_main_sysupdate();
        /* about infomation */
        void slot_main_about();
        /* rm database lock file */
        void slot_main_fixlck();
        /* check dependencies */
        void slot_main_depend();
        /* cleanup the display */
        void slot_main_cleandis();
        /* when click install all */
        void slot_main_insall();
        /* when click remove all */
        void slot_main_rmall();
        /* cleanup the packages cache directory */
        void slot_main_clean_cachedirs();
private:
        Ui::mainwindow *ui;
        int selected_db = ALL;
};
#endif // MAINWINDOW_H
