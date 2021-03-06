#include <QDateTime>
#include "pkg_info.h"
#include "ui/ui_pkg_info.h"
#include "dialog.h"
#include "pkg_note.h"

#include "pm/interface.h"

#include <alpm.h>

#define FILE_NUM 3000

pkg_info::pkg_info(entry* e,QWidget *parent) :
    QDialog(parent),ent(e),
    ui(new Ui::pkg_info)
{
        ui->setupUi(this);
        this->setWindowTitle(QString(alpm_pkg_get_name(ent->package)));

        /* connect */
        connect(ui->install,SIGNAL(clicked()),this,SLOT(slot_install()));
        connect(ui->remove,SIGNAL(clicked()),this,SLOT(slot_remove()));
        connect(ui->detail,SIGNAL(clicked()),this,SLOT(slot_detail()));
        connect(ui->depend,SIGNAL(clicked()),this,SLOT(slot_depend()));
        connect(ui->files,SIGNAL(clicked()),this,SLOT(slot_files()));
        connect(ui->check_deps,SIGNAL(clicked()),this,SLOT(slot_c_deps()));
        connect(ui->check_files,SIGNAL(clicked()),this,SLOT(slot_c_files()));
        connect(ui->add_note,SIGNAL(clicked()),this,SLOT(slot_add_note()));

        ui->install->setShortcut(Qt::Key_I);
        ui->remove->setShortcut(Qt::Key_R);
        ui->add_note->setShortcut(Qt::Key_A);
        ui->depend->setShortcut(Qt::Key_D);
        ui->files->setShortcut(Qt::Key_F);
        ui->check_files->setShortcut(Qt::Key_K);
        ui->check_deps->setShortcut(Qt::Key_J);
        ui->detail->setShortcut(Qt::Key_T);

        ui->name->setText(alpm_pkg_get_name(ent->package));
        ui->desc->setText(alpm_pkg_get_desc(ent->package));

        if(ent->op->check_installed(ent->package)&&\
                ent->op->check_higher_version(ent->package)){
                ui->install->setEnabled(false);
                ui->files->setVisible(true);
                ui->check_deps->setVisible(true);
                ui->check_files->setVisible(true);
        }

        if(!ent->op->match_db(alpm_pkg_get_db(ent->package),LOCAL)){
                ui->remove->setEnabled(false);
                ui->files->setVisible(false);
                ui->check_deps->setVisible(false);
                ui->check_files->setVisible(false);
        }

        ui->scrollAreaWidgetContents->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
        emit ui->detail->clicked();
}
void pkg_info::add_file_name(QString& text,alpm_list_t* list)
{
        alpm_list_t* i;
        for(i=list;i;i=alpm_list_next(i)){
                text += QString((char*)i->data) + "\n";
        }
}
void pkg_info::add_depend_name(QLayout *layout,alpm_list_t* list)
{
        QString text;
        alpm_depend_t* dep;
        alpm_list_t* i;
        for(i=list;i;i=alpm_list_next(i)){
                dep = (alpm_depend_t*)i->data;
                text += "<a href='";
                text += QString(dep->name);
                text += "'>";
                text += QString(dep->name);
                if(ent->op->get_localpkg(dep->name))text+="(installed)";
                text += "</a>";
                QLabel *tmp = new QLabel();
                tmp->setText(text);
                layout->addWidget(tmp);
                connect(tmp,SIGNAL(linkActivated(QString)),this,SLOT(slot_newinfo(QString)));
                text.clear();
        }
        return ;
}
void pkg_info::add_pkg_name(QLayout* layout,alpm_list_t* list)
{
        QString text;
        alpm_list_t* i;
        for(i=list;i;i=alpm_list_next(i)){
                alpm_pkg_t* p = (alpm_pkg_t*)i->data;
                text += "<a href='";
                text += QString(alpm_pkg_get_name(p));
                text += "'>";
                text += QString(alpm_pkg_get_name(p));
                text+="(installed)";
                text += "</a>";
                QLabel *tmp = new QLabel();
                tmp->setText(text);
                connect(tmp,SIGNAL(linkActivated(QString)),this,SLOT(slot_newinfo(QString)));
                layout->addWidget(tmp);
                text.clear();
        }
        return;
}

pkg_info::~pkg_info()
{
        delete ui;
        for(entry* i: this->extent){
                delete i;
        }

}

/*---------------SLOT FUNCTION---------------*/
void pkg_info::slot_install()
{
        this->close();
        emit ent->install_pkg();
}
void pkg_info::slot_remove()
{
        emit ent->remove_pkg();
}
void pkg_info::slot_detail()
{
        QString text;
        text += "URL:\t" + QString(alpm_pkg_get_url(ent->package))+"\n\n";
        text += "Repository:\t" + QString(alpm_db_get_name(alpm_pkg_get_db(ent->package))) + "\n";
        text += "Packager:\t" + QString(alpm_pkg_get_packager(ent->package)) + "\n";

        QDateTime time;
        time = QDateTime::fromTime_t(alpm_pkg_get_builddate(ent->package));

        text += "Build date:\t" + time.toString() + "\n";

        if(ent->op->check_installed(ent->package)){
                time = QDateTime::fromTime_t(alpm_pkg_get_installdate(ent->package));
                text += "Install date:\t" + time.toString() + "\n";

                text += "Install reason:\t";
                if(alpm_pkg_get_reason(ent->package)==ALPM_PKG_REASON_DEPEND){
                        text += "As a dependence\n";
                }
                else {
                        text += "Explicit\n";
                }
                char *m  = get_size(alpm_pkg_get_isize(ent->package));
                text += "Install size:\t" + QString(m) + "\n";
                free(m);
        }
        else {
                char* n  = get_size(alpm_pkg_get_size(ent->package));
                text += "Size:\t\t" + QString(n) + "\n";
                free(n);
        }
        text += '\n';
        char* note = ent->op->get_pkg_note(ent->package);
        if(note){
                text += "Note:\n";
                text += QString(note);
                text += "\n";
                free(note);
        }
        QLabel *cont = new QLabel();
        cont->setAlignment(Qt::AlignTop);
        cont->setText(text);
        ui->scrollArea->setWidget(cont);

}
void pkg_info::slot_depend()
{

        QWidget *content = new QWidget();
        content->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
        QLayout *layout = new QVBoxLayout;
        content->setLayout(layout);
        ui->scrollArea->setWidget(content);

        QString text;
        text += "Depends on:";
        QLabel *depend = new QLabel();
        depend->setText(text);
        layout->addWidget(depend);
        text.clear();

        alpm_list_t* list = ent->op->get_pkg_depend(ent->package);
        add_depend_name(layout,list);

        text += "\nRequired By:";
        QLabel *require = new QLabel();
        require->setText(text);
        layout->addWidget(require);
        text.clear();

        list = ent->op->get_pkg_require(ent->package);
        add_pkg_name(layout,list);


        text += "\nOption Depends:";
        QLabel *optdep = new QLabel();
        optdep->setText(text);
        layout->addWidget(optdep);
        text.clear();

        list = ent->op->get_pkg_optdepend(ent->package);
        add_depend_name(layout,list);

        text += "\nConflicts with:";
        QLabel *conflict = new QLabel();
        conflict->setText(text);
        layout->addWidget(conflict);
        text.clear();

        list = alpm_pkg_get_conflicts(ent->package);
        add_depend_name(layout,list);

}
void pkg_info::slot_files()
{
        QString text;
        alpm_list_t* files = ent->op->get_pkg_files(ent->package);
        add_file_name(text,files);
        text += "\n";
        QLabel *cont = new QLabel();
        cont->setText(text);
        ui->scrollArea->setWidget(cont);
        
        free_list_char(files);
}
void pkg_info::slot_c_files()
{
        alpm_list_t* missfiles = ent->op->get_pkg_missfiles(ent->package);
        QString text;
        add_file_name(text,missfiles);
        dialog(0,"Miss files are listed at below.",text).exec();
        free_list_char(missfiles);
        return;
}
void pkg_info::slot_c_deps()
{
        alpm_list_t* missdeps = ent->op->get_pkg_unresolve_depend(ent->package);
        QString title = "Miss dependencies are listed at below.";
        if(missdeps)title += QString("\nFIX THEM NOW?");
        int ret = dialog(title,missdeps).exec();
        if(ret&&missdeps){
                ret = ent->op->install_list(missdeps);
                if(!ret){
                        missdeps= ent->op->check_installed(missdeps);
                        dialog("FIXED:",missdeps).exec();
                }
                else{
                        dialog(0,"Error",alpm_strerror(alpm_errno(ent->op->conf->handle))).exec();
                }
        }
}
void pkg_info::slot_add_note()
{
        char* content = ent->op->get_pkg_note(ent->package);
        QString text(content);
        if(content)free(content);
        pkg_note *note = new pkg_note(&text,this);
        note->exec();
        ent->op->set_pkg_note(ent->package,text.toLatin1().data());
        slot_detail();

}
void pkg_info::slot_newinfo(QString pkgName)
{
        entry* newEntry;
        if(ent->op->get_localpkg((char*)pkgName.toLatin1().data())){
                alpm_pkg_t* p = ent->op->get_localpkg(pkgName.toLatin1().data());
                newEntry = new entry(p,ent->op);
        }
        else{
                alpm_pkg_t* p = ent->op->find_dbs_pkg(\
                            alpm_get_syncdbs(ent->op->conf->handle),\
                            pkgName.toLatin1().data());
                newEntry = new entry(p,ent->op);
        }
        pkg_info *pinfo  = new pkg_info(newEntry);
        pinfo->show();
        extent.push_back(newEntry);

}

