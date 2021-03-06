#include "mainwindow.h"
#include "ui/ui_mainwindow.h"
#include "config.h"
#include "dialog.h"

#include "pm/interface.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainwindow)
{
        ui->setupUi(this);
        msg = new QLabel();
        msg->setAlignment(Qt::AlignRight);
        msg->setText("Welcome. .");
        ui->statusBar->addWidget(msg);
        op = new operation();
        dis = new display(ui->entries_display,op,ui->pagecnt,msg);

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
        connect(ui->next,SIGNAL(clicked()),dis,SLOT(slot_next_page()));
        connect(ui->prev,SIGNAL(clicked()),dis,SLOT(slot_prev_page()));
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

void mainwindow::set_s_db()
{
        int selected = ui->boxTreename->currentIndex();
        switch (selected) {
            case 0:
                this->selected_db = ALL;
                break;
            case 1:
                this->selected_db = CORE;
                break;
            case 2:
                this->selected_db = COMMUNITY;
                break;
            case 3:
                this->selected_db = EXTRA;
                break;
            case 4:
                this->selected_db = LOCAL;
                break;
        };
}

mainwindow::~mainwindow()
{
        delete ui;
        delete this->dis;
        if(op){
            delete this->op;
        }
}

/*--------------------SLOT FUNCTION-------------------*/
void mainwindow::slot_main_db_update()
{
        msg->setText("Updating data base");
        alpm_list_t* update = op->database_update(0);
        QString content;
        for(;update;update = alpm_list_next(update)){
                content += QString(alpm_db_get_name((alpm_db_t*)update->data)) + '\n';
        }
        dialog(0,"Database updated!",content).exec();
}
/* display the installed packages */
void mainwindow::slot_main_installed()
{
        alpm_list_t* list = op->get_installed_pkgs();
        char m[1024];
        sprintf(m,"Hit %d packages.",(int)alpm_list_count(list));
        msg->setText(m);
        dis->cleanup();
        dis->add_entries(list); 
}
/* search button clicked, do the search action */
void mainwindow::slot_main_search()
{
        set_s_db();
        char *name = strdup(ui->editorSearch->text().toLatin1().data());
        alpm_list_t* pkgs = nullptr;
        int ind = ui->method->currentIndex();
        switch(ind){
                case 0:
                        pkgs = op->get_pkgs_by_regex(name,selected_db);
                        break;
                case 1:
                        pkgs = op->get_pkgs_by_KMP(name,selected_db);
                        break;
                case 2:
                        pkgs = op->get_pkgs_by_Trie(name,selected_db);
                        break;
                default:
                        break;
        }
        free(name);

        char m[1024];
        sprintf(m,"Hit %d packages.",(int)alpm_list_count(pkgs));
        msg->setText(m);

        dis->cleanup();
        dis->add_entries(pkgs);

}
void mainwindow::slot_main_configure()
{
        config *conf = new config(this,op->conf);
        conf->exec();
}
void mainwindow::slot_main_orphans()
{
        alpm_list_t* orphans = op->get_orphans();

        char m[1024];
        sprintf(m,"Hit %d packages.",(int)alpm_list_count(orphans));
        msg->setText(m);

        dis->cleanup();
        dis->add_entries(orphans);
}
void mainwindow::slot_main_sysupdate()
{
        msg->setText("Updating data base . . . ");
        op->database_update(0);
        msg->setText("Query data base . . .");
        alpm_list_t* pkgs = op->get_pkgs_sysupdate();

        char m[1024];
        sprintf(m,"Hit %d packages.",(int)alpm_list_count(pkgs));
        msg->setText(m);

        dis->cleanup();
        dis->add_entries(pkgs);

}
void mainwindow::slot_main_about()
{
        dialog *dl = new dialog(0,"EMAIL:panpansuannai<panpansuannai@outlook.com>");
        dl->show();
}
void mainwindow::slot_main_fixlck()
{
        clean_up();
}
void mainwindow::slot_main_depend()
{
        alpm_list_t* missdeps = op->get_missdeps();

        char m[1024];
        sprintf(m,"Check miss dependencies: Hit %d packages.",(int)alpm_list_count(missdeps));
        msg->setText(m);

        dis->cleanup();
        dis->add_entries(missdeps);
        
}
void mainwindow::slot_main_cleandis()
{
        dis->cleanup();
}

void mainwindow::slot_main_insall()
{
        int ok = dialog(0,"Are you sure to do this?").exec();
        if(!ok)return;
        alpm_list_t* ins = dis->install_page();
        dialog("The list of installed packages is below.",ins).exec();
}
void mainwindow::slot_main_rmall()
{
        int ok = dialog(0,"Are you sure to do this?").exec();
        if(!ok)return;
        alpm_list_t* re = dis->remove_page();
        dialog("The list of removed packages is below.",re).exec();
}
