#include <memory>

#include "mainwindow.h"
#include "ui/ui_mainwindow.h"
#include "config.h"
#include "dialog.h"
#include "monitor.h"

#include "pm2/configure.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::mainwindow), msg(new QLabel())
{
        ui->setupUi(this);
        msg->setAlignment(Qt::AlignRight);
        msg->setText("Welcome. .");
        ui->statusBar->addWidget(msg);
        monitor_ = std::make_shared<Monitor>(ui->entries_display, ui->pagecnt, msg);

        /* combine return key and search button */
        ui->buttonSearch->setShortcut(Qt::Key_Enter);
        ui->buttonSearch->setShortcut(Qt::Key_Return);
        //ui->next->setShortcut(Qt::Key_Right);
        //ui->prev->setShortcut(Qt::Key_Left);
        ui->installed->setShortcut(Qt::Key_I);
        ui->orphans->setShortcut(Qt::Key_O);
        ui->updates->setShortcut(Qt::Key_U);
        ui->depend->setShortcut(Qt::Key_D);
        ui->next->setShortcut(Qt::Key_L);
        ui->prev->setShortcut(Qt::Key_H);

        /* connect menu button */
        connect(ui->actionDatabase_Update,SIGNAL(triggered()),this,SLOT(slot_main_db_update()));
        connect(ui->actionFixlck,SIGNAL(triggered()),this,SLOT(slot_main_fixlck()));
        connect(ui->actionConfigure,SIGNAL(triggered()),this,SLOT(slot_main_configure()));
        connect(ui->actionCleandis,SIGNAL(triggered()),this,SLOT(slot_main_cleandis()));
        connect(ui->next,SIGNAL(clicked()),this,SLOT(next_page()));
        connect(ui->prev,SIGNAL(clicked()),this,SLOT(prev_page()));
        connect(ui->insall,SIGNAL(clicked()),this,SLOT(slot_main_insall()));
        connect(ui->rmall,SIGNAL(clicked()),this,SLOT(slot_main_rmall()));
        /* when the search button clicked */
        connect(ui->buttonSearch,SIGNAL(clicked()),this,SLOT(slot_main_search()));
        /* display the pkgs installed */
        connect(ui->installed,SIGNAL(clicked()),this,SLOT(slot_main_installed()));
        /* display the orphans */
        connect(ui->orphans,SIGNAL(clicked()),this,SLOT(slot_main_orphans()));
        /* system update */
        connect(ui->updates,SIGNAL(clicked()),this,SLOT(slot_main_sysupdate()));
        /* display some infomatino */
        connect(ui->actionAbout_Author,SIGNAL(triggered()),this,SLOT(slot_main_about()));
        connect(ui->depend,SIGNAL(clicked()),this,SLOT(slot_main_depend()));

}

void mainwindow::set_s_db(){

}

mainwindow::~mainwindow()
{
        delete ui;
}

/*--------------------SLOT FUNCTION-------------------*/
void mainwindow::slot_main_db_update()
{
}
/* display the installed packages */
void mainwindow::slot_main_installed()
{
}
/* search button clicked, do the search action */
void mainwindow::slot_main_search()
{
}
void mainwindow::slot_main_configure()
{
}
void mainwindow::slot_main_orphans()
{
}
void mainwindow::slot_main_sysupdate()
{
}
void mainwindow::slot_main_about()
{
}
void mainwindow::slot_main_fixlck()
{
}
void mainwindow::slot_main_depend()
{
        
}
void mainwindow::slot_main_cleandis()
{
}

void mainwindow::slot_main_insall()
{
}
void mainwindow::slot_main_rmall()
{
}
