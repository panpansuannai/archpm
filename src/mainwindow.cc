#include <memory>

#include "mainwindow.h"
#include "ui/ui_mainwindow.h"
#include "config.h"
#include "dialog.h"
#include "monitor.h"

#include "pm2/configure.h"
#include "pm2/database.h"
#include "pm2/optparse.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::mainwindow), msg_(new QLabel()),config_(std::make_unique<Configure>())
{
        ui->setupUi(this);
        msg_->setAlignment(Qt::AlignRight);
        msg_->setText("Welcome . . .");
        ui->statusBar->addWidget(msg_);
        
        monitor_ = std::make_shared<Monitor>(ui->entries_display, ui->pagecnt, msg_);
  
        OptParser optparser;
        auto vec = optparser.parse_file(string(DEF_CONFIG_FILE));
        for ( auto option_ptr : vec ) {
            if (option_ptr) {
              config_->setup_opt(option_ptr);
            }
            if (option_ptr->get_id() == OPTID_DB) {
              databases_.push_back(std::dynamic_pointer_cast<DataBase>(option_ptr));
            }
        }
        DataBase::DataBasePtr local = std::make_shared<DataBase>("local");
        config_->setup_opt(local);
        databases_.push_back(local);

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
        connect(ui->actionDatabase_Update,SIGNAL(triggered()),this,SLOT(slot_database_update()));
        connect(ui->actionFixlck,SIGNAL(triggered()),this,SLOT(slot_fixlock()));
        connect(ui->actionConfigure,SIGNAL(triggered()),this,SLOT(slot_configure()));
        connect(ui->actionCleandis,SIGNAL(triggered()),this,SLOT(slot_clean_result()));
        connect(ui->next,SIGNAL(clicked()),this,SLOT(slot_next_page()));
        connect(ui->prev,SIGNAL(clicked()),this,SLOT(slot_prev_page()));
        connect(ui->insall,SIGNAL(clicked()),this,SLOT(slot_installl_page()));
        connect(ui->rmall,SIGNAL(clicked()),this,SLOT(slot_remove_page()));

        /* when the search button clicked */
        connect(ui->buttonSearch,SIGNAL(clicked()),this,SLOT(slot_search()));
        /* display the pkgs installed */
        connect(ui->installed,SIGNAL(clicked()),this,SLOT(slot_get_installed()));
        /* display the orphans */
        connect(ui->orphans,SIGNAL(clicked()),this,SLOT(slot_get_orphans()));
        /* system update */
        connect(ui->updates,SIGNAL(clicked()),this,SLOT(slot_sysupdate()));
        /* display some infomatino */
        connect(ui->actionAbout_Author,SIGNAL(triggered()),this,SLOT(slot_about()));
        connect(ui->depend,SIGNAL(clicked()),this,SLOT(slot_get_depend()));

}

mainwindow::~mainwindow()
{
        delete ui;
}

/*--------------------SLOT FUNCTION-------------------*/
void mainwindow::slot_database_update()
{
}
/* display the installed packages */
void mainwindow::slot_get_installed() {
  DataBase::DataBasePtr local_db;
  for (auto db : databases_){
    if(db->get_name() == "local"){
      local_db = db;
      break;
    }
  }
  if(local_db == nullptr) return;
  std::vector<Package::PackagePtr> packages = local_db->get_all_packages();
  for(auto package : packages){
    monitor_->push_queue(package);
  }
  monitor_->next_page();
}
/* search button clicked, do the search action */
void mainwindow::slot_search()
{
}
void mainwindow::slot_configure()
{
}
void mainwindow::slot_get_orphans()
{
}
void mainwindow::slot_sysupdate()
{
}
void mainwindow::slot_about()
{
}
void mainwindow::slot_fixlock()
{
}
void mainwindow::slot_get_depend()
{
        
}
void mainwindow::slot_clean_result()
{
}

void mainwindow::slot_install_page()
{
}
void mainwindow::slot_remove_page()
{
}
