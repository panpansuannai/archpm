#include "config.h"
#include "ui/ui_config.h"
#include "dialog.h"
#include "pm/interface.h"

config::config(QWidget *parent,conf_t* _conf) :
    QDialog(parent),
    ui(new Ui::config)
{
        conf = _conf;
        ui->setupUi(this);

        /* display current configure */
        if(conf->dbpath)
            ui->dbpath->setText(QString(conf->dbpath));
        if(conf->logfile)
            ui->arch->setText(QString(conf->arch));
        if(conf->logfile)
            ui->logfile->setText((QString(conf->logfile)));
        if(conf->hookdir)
            ui->hookdir->setText(QString(conf->hookdir));
        if(conf->gpgdir)
            ui->gpgdir->setText(QString(conf->gpgdir));
        if(conf->conffile)
            ui->conffile->setText(QString(conf->conffile));

        ui->timedb->setText(QString(timeout_db));
        ui->timepkg->setText(QString(timeout_pkg));

        list_config(ui->cachedir,conf->cachedirs);
        list_config(ui->noextract,conf->noextracts);
        list_config(ui->noupgrade,conf->noupgrades);
        list_config(ui->ignorepkgs,conf->ignorepkgs);
        list_config(ui->ignoregrps,conf->ignoregrps);
        list_config(ui->holdpkgs,conf->holdpkgs);
}
void config::list_config(QLineEdit* line,alpm_list_t *list)
{
        QString text;
        alpm_list_t* i;
        for(i=list;i;i=alpm_list_next(i)){
                text += QString((char*)i->data) + ' ';
        }
        line->setText(text);
}
void config::accept()
{
        char* value;
        alpm_list_t* vlist;
        value = strdup(ui->dbpath->text().toLatin1().data());
        conf->conf_set_dbpath(value);
        value = strdup(ui->logfile->text().toLatin1().data());
        conf->conf_set_logfile(value);
        value = strdup(ui->arch->text().toLatin1().data());
        conf->conf_set_arch(value);
        value = strdup(ui->hookdir->text().toLatin1().data());
        conf->conf_set_hookdir(value);
        value = strdup(ui->hookdir->text().toLatin1().data());
        conf->conf_set_gpgdir(value);
        value = strdup(ui->conffile->text().toLatin1().data());
        if(strncmp(value,conf->conffile,strlen(value))!=0){
                char* oldconf = conf->conffile;
                conf->conffile = value;
                if(conf->conf_parsefile(conf->conffile)){
                        dialog(0,"configure file invalid!").exec();
                        conf->conffile = oldconf;
                        free(value);
                }
                else{
                        conf->conf_set_option();
                        conf->conf_set_handle();
                }
        }

        vlist = string_to_list(ui->cachedir->text().toLatin1().data());
        conf->conf_set_cachedirs(vlist);
        vlist = string_to_list(ui->noextract->text().toLatin1().data());
        conf->conf_set_noextracts(vlist);
        vlist = string_to_list(ui->noupgrade->text().toLatin1().data());
        conf->conf_set_noupgrades(vlist);
        vlist = string_to_list(ui->ignorepkgs->text().toLatin1().data());
        conf->conf_set_ignorepkgs(vlist);
        vlist = string_to_list(ui->ignoregrps->text().toLatin1().data());
        conf->conf_set_ignoregrps(vlist);
        vlist = string_to_list(ui->holdpkgs->text().toLatin1().data());
        conf->conf_set_holdpkgs(vlist);

        free(timeout_db);
        timeout_db = strdup(ui->timedb->text().toLatin1().data());
        free(timeout_pkg);
        timeout_pkg = strdup(ui->timepkg->text().toLatin1().data());
        conf->conf_set_handle();
        close();
}
config::~config()
{
        delete ui;
}
