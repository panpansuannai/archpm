#include "config.h"
#include "ui/ui_config.h"
#include "dialog.h"

Config::Config(std::shared_ptr<Configure> config, QWidget *parent) :
    QDialog(parent), ui(new Ui::config), config_(config)
{
        ui->setupUi(this);

        /* display current configure */
        ui->dbpath->setText(QString(config_->get_database_path().c_str()));
        ui->arch->setText(QString(config_->get_architecture().c_str()));
        ui->logfile->setText((QString(config_->get_log_file().c_str())));
        ui->hookdir->setText(QString(config_->get_hook_directory().c_str()));
        ui->gpgdir->setText(QString(config_->get_gpg_directory().c_str()));
        ui->conffile->setText(QString(config_->get_configure_file().c_str()));
        ui->conffile->setText(QString(config_->get_cache_directory().c_str()));
        ui->conffile->setText(QString(config_->get_no_extracts().c_str()));
        ui->conffile->setText(QString(config_->get_no_upgrades().c_str()));
        ui->conffile->setText(QString(config_->get_ignore_packages().c_str()));
        ui->conffile->setText(QString(config_->get_ignore_groups().c_str()));
        ui->conffile->setText(QString(config_->get_hold_packages().c_str()));

}
void Config::accept() {

}
Config::~Config()
{
        delete ui;
}
