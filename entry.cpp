#include "entry.h"
#include "dialog.h"
#include "ui_entry.h"
#include "pkg_info.h"
#include "pm/interface.h"

#include <alpm.h>
#include <cstring>

entry::entry(alpm_pkg_t* pkg,operation* opera) :
    package(pkg),op(opera),
    ui(new Ui::entry)
{
        ui->setupUi(this);
        const char* db_name = alpm_db_get_name(alpm_pkg_get_db(package));

        ui->pkg_name->setText(alpm_pkg_get_name(package));
        ui->pkg_desc->setText(alpm_pkg_get_desc(package));
        ui->db->setText(db_name);
        ui->version->setText(alpm_pkg_get_version(package));

        if(op->check_installed(package)&&op->check_higher_version(package)){
            ui->install->setEnabled(false);
        }
        if(!op->match_db(alpm_pkg_get_db(package),LOCAL)){
                ui->remove->setEnabled(false);
        }

        /* click the pkg entry */
        connect(ui->info,SIGNAL(clicked()),this,SLOT(show_pkg_info()));
        connect(ui->remove,SIGNAL(clicked()),this,SLOT(remove_pkg()));
        connect(ui->install,SIGNAL(clicked()),this,SLOT(install_pkg()));

}

void entry::show_pkg_info()
{
        pkg_info* info = new pkg_info(this,this);
        info->show();
}

void entry::install_pkg()
{
        if(!op->check_installed(package)||!op->check_higher_version(package)){
                int ret;
                alpm_list_t* deps = op->get_pkg_unresolve_depend(package);
                alpm_list_t* list = deps;
                dialog dl("CONTINUE TO INSTALL?",list,"Dependence:\n");
                ret =  dl.exec();
                if(ret){
                        list = alpm_list_add(list,package);
                        alpm_list_t* i;
                        for(i=list;i;i=alpm_list_next(i)){
                                alpm_pkg_t* p = (alpm_pkg_t*)i->data;
                                ret = op->to_change_pkg(p,PKG_INSTALL);
                                if(ret!=PKG_OK){
                                        switch(ret){
                                                case PKG_UPGRADE:
                                                        dialog(0,"Can't upgrade ",alpm_pkg_get_name(p)).exec();
                                                        return ;
                                                        break;
                                                case PKG_INSTALL:
                                                        dialog(0,"Can't install ",alpm_pkg_get_name(p)).exec();
                                                        return;
                                                                break;
                                                case PKG_REMOVE:
                                                        dialog(0,"Can't remove ",alpm_pkg_get_name(p)).exec();
                                                        return;
                                                        break;
                                        }
                            }
                            break;
                    }

                            ret = op->install_list(list);
                            if(ret){
                                    dialog(0,"Some error happends.",alpm_strerror(alpm_errno(op->conf->handle))).exec();
                                    return ;
                            }
                            alpm_list_t* succeed;
#ifdef INSTALL_WITH_PACMAN
                            /* copy the name of the packages in list */
                            alpm_list_t* tar_name = copy_pkgs_name(list);

                            /* reload handle to reload local database */
                            op->reload_handle();
                            succeed  = op->check_installed(tar_name);
                            
                            /* free the memory */
                            free_list_char(tar_name);
                            emit sig_install_pkg();
#else
                            succeed = op->check_installed(list);
                            op->mark_as_dep(deps);
#endif
                            dialog("ACTION: packages installed have been listed at below",succeed).exec();
                    }
                }
        else {
            dialog(0,"Packaged have been installed!").exec();
            return;
        }
}
void entry::remove_pkg()
{
        if(op->check_installed(package)){
                int ret;
                /* check depend */
                alpm_list_t* require = op->get_pkg_require(package);
                if(require){
                        ret = dialog("Some packages depend on this.",require,"Continue?").exec();
                        if(!ret)return;
                }
                else {
                        dialog dl(0,"CONTINUE TO REMOVE?");
                        ret = dl.exec();
                        if(!ret)return;
                }
                ret = op->to_change_pkg(package,PKG_REMOVE);
                if(ret!=PKG_OK){
                        switch(ret){
                                case PKG_UPGRADE:
                                        dialog(0,"Can't upgrade ",alpm_pkg_get_name(package)).exec();
                                        return;
                                case PKG_INSTALL:
                                        dialog(0,"Can't install ",alpm_pkg_get_name(package)).exec();
                                        return;
                                case PKG_REMOVE:
                                        dialog(0,"Can't remove ",alpm_pkg_get_name(package)).exec();
                                        return;
                        }

                }
                ret=op->remove(package);
                if(ret){
                        dialog(0,"Remove failed",alpm_strerror(alpm_errno(op->conf->handle))).exec();
                        return;
                }
                else {
                        emit sig_remove_pkg(this);
                }
        }
        else {
                dialog(0,"The package haven't been installed").exec();
        }
}
entry::~entry()
{
        delete ui;
}
