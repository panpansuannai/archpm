#include <QScrollArea>
#include "dialog.h"
#include "ui_dialog.h"

#include "pm/interface.h"

dialog::dialog(QString title, alpm_list_t* list,QString add,QWidget *parent) :
        QDialog(parent),
        ui(new Ui::dialog)
{
        ui->setupUi(this);
        ui->title->setText(title);

        QScrollArea* area = new QScrollArea();
        area->setSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred));
        ui->layout->addWidget(area);


        desc = new QLabel(this);
        QSizePolicy policy(QSizePolicy::Preferred,QSizePolicy::Preferred);
        desc->setSizePolicy(policy);
        desc->setAlignment(Qt::AlignCenter|Qt::AlignTop);

        QString content;
        if(add!=nullptr)content += add+"\n";

        alpm_list_t* pkg;
        for(pkg = list;pkg;pkg = alpm_list_next(pkg)){
                content += QString(alpm_pkg_get_name(\
                                       (alpm_pkg_t*)pkg->data));
                content +=  '\n';
        }

        desc->setText(content);
        area->setWidget(desc);
}

dialog::dialog(int block,QString title,QString content,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog)
{
        ui->setupUi(this);
        connect(this,SIGNAL(sig_close()),this,SLOT(close()));

        ui->title->setText(title);
        if(content!=nullptr){
                QScrollArea* area = new QScrollArea();
                area->setSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred));
                ui->layout->addWidget(area);

                desc = new QLabel(this);
                QSizePolicy policy(QSizePolicy::Fixed,QSizePolicy::Preferred);
                desc->setSizePolicy(policy);

                desc->setAlignment(Qt::AlignTop|Qt::AlignLeft);
                desc->setText(content);
                area->setWidget(desc);
        }
        if(block){
                this->setDisabled(true);
         }
}
void dialog::slot_close()
{
        this->~dialog();
}

dialog::~dialog()
{
        delete ui;
}
