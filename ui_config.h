/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_config
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_39;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *conffile;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_29;
    QLabel *label_28;
    QLineEdit *dbpath;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_30;
    QLabel *label_29;
    QLineEdit *arch;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_28;
    QLabel *label_27;
    QLineEdit *logfile;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_31;
    QLabel *label_30;
    QLineEdit *hookdir;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_25;
    QLabel *label_24;
    QLineEdit *cachedir;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_24;
    QLabel *label_23;
    QLineEdit *gpgdir;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_26;
    QLabel *label_25;
    QLineEdit *noupgrade;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *noextract;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_32;
    QLabel *label_31;
    QLineEdit *ignorepkgs;
    QWidget *widget_16;
    QVBoxLayout *verticalLayout_38;
    QLabel *label_37;
    QLineEdit *ignoregrps;
    QWidget *widget_15;
    QVBoxLayout *verticalLayout_37;
    QLabel *label_36;
    QLineEdit *holdpkgs;
    QWidget *widget_14;
    QVBoxLayout *verticalLayout_36;
    QLabel *label_35;
    QLineEdit *timedb;
    QWidget *widget_13;
    QVBoxLayout *verticalLayout_35;
    QLabel *label_34;
    QLineEdit *timepkg;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_33;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_34;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *config)
    {
        if (config->objectName().isEmpty())
            config->setObjectName(QString::fromUtf8("config"));
        config->resize(805, 526);
        config->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(config);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(config);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 767, 1411));
        verticalLayout_39 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_39->setObjectName(QString::fromUtf8("verticalLayout_39"));
        widget_5 = new QWidget(scrollAreaWidgetContents);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_3 = new QVBoxLayout(widget_5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        conffile = new QLineEdit(widget_5);
        conffile->setObjectName(QString::fromUtf8("conffile"));

        verticalLayout_3->addWidget(conffile);


        verticalLayout_39->addWidget(widget_5);

        widget_7 = new QWidget(scrollAreaWidgetContents);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy);
        verticalLayout_29 = new QVBoxLayout(widget_7);
        verticalLayout_29->setObjectName(QString::fromUtf8("verticalLayout_29"));
        label_28 = new QLabel(widget_7);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        sizePolicy.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy);

        verticalLayout_29->addWidget(label_28);

        dbpath = new QLineEdit(widget_7);
        dbpath->setObjectName(QString::fromUtf8("dbpath"));

        verticalLayout_29->addWidget(dbpath);


        verticalLayout_39->addWidget(widget_7);

        widget_8 = new QWidget(scrollAreaWidgetContents);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        sizePolicy.setHeightForWidth(widget_8->sizePolicy().hasHeightForWidth());
        widget_8->setSizePolicy(sizePolicy);
        verticalLayout_30 = new QVBoxLayout(widget_8);
        verticalLayout_30->setObjectName(QString::fromUtf8("verticalLayout_30"));
        label_29 = new QLabel(widget_8);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);

        verticalLayout_30->addWidget(label_29);

        arch = new QLineEdit(widget_8);
        arch->setObjectName(QString::fromUtf8("arch"));

        verticalLayout_30->addWidget(arch);


        verticalLayout_39->addWidget(widget_8);

        widget_6 = new QWidget(scrollAreaWidgetContents);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        sizePolicy.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy);
        verticalLayout_28 = new QVBoxLayout(widget_6);
        verticalLayout_28->setObjectName(QString::fromUtf8("verticalLayout_28"));
        label_27 = new QLabel(widget_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        sizePolicy.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy);

        verticalLayout_28->addWidget(label_27);

        logfile = new QLineEdit(widget_6);
        logfile->setObjectName(QString::fromUtf8("logfile"));

        verticalLayout_28->addWidget(logfile);


        verticalLayout_39->addWidget(widget_6);

        widget_9 = new QWidget(scrollAreaWidgetContents);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        sizePolicy.setHeightForWidth(widget_9->sizePolicy().hasHeightForWidth());
        widget_9->setSizePolicy(sizePolicy);
        verticalLayout_31 = new QVBoxLayout(widget_9);
        verticalLayout_31->setObjectName(QString::fromUtf8("verticalLayout_31"));
        label_30 = new QLabel(widget_9);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        sizePolicy.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy);

        verticalLayout_31->addWidget(label_30);

        hookdir = new QLineEdit(widget_9);
        hookdir->setObjectName(QString::fromUtf8("hookdir"));

        verticalLayout_31->addWidget(hookdir);


        verticalLayout_39->addWidget(widget_9);

        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        verticalLayout_25 = new QVBoxLayout(widget_3);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        label_24 = new QLabel(widget_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);

        verticalLayout_25->addWidget(label_24);

        cachedir = new QLineEdit(widget_3);
        cachedir->setObjectName(QString::fromUtf8("cachedir"));

        verticalLayout_25->addWidget(cachedir);


        verticalLayout_39->addWidget(widget_3);

        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout_24 = new QVBoxLayout(widget_2);
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        label_23 = new QLabel(widget_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);

        verticalLayout_24->addWidget(label_23);

        gpgdir = new QLineEdit(widget_2);
        gpgdir->setObjectName(QString::fromUtf8("gpgdir"));

        verticalLayout_24->addWidget(gpgdir);


        verticalLayout_39->addWidget(widget_2);

        widget_4 = new QWidget(scrollAreaWidgetContents);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);
        verticalLayout_26 = new QVBoxLayout(widget_4);
        verticalLayout_26->setObjectName(QString::fromUtf8("verticalLayout_26"));
        label_25 = new QLabel(widget_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        sizePolicy.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy);

        verticalLayout_26->addWidget(label_25);

        noupgrade = new QLineEdit(widget_4);
        noupgrade->setObjectName(QString::fromUtf8("noupgrade"));

        verticalLayout_26->addWidget(noupgrade);


        verticalLayout_39->addWidget(widget_4);

        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label);

        noextract = new QLineEdit(widget);
        noextract->setObjectName(QString::fromUtf8("noextract"));

        verticalLayout_2->addWidget(noextract);


        verticalLayout_39->addWidget(widget);

        widget_10 = new QWidget(scrollAreaWidgetContents);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        sizePolicy.setHeightForWidth(widget_10->sizePolicy().hasHeightForWidth());
        widget_10->setSizePolicy(sizePolicy);
        verticalLayout_32 = new QVBoxLayout(widget_10);
        verticalLayout_32->setObjectName(QString::fromUtf8("verticalLayout_32"));
        label_31 = new QLabel(widget_10);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        sizePolicy.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy);

        verticalLayout_32->addWidget(label_31);

        ignorepkgs = new QLineEdit(widget_10);
        ignorepkgs->setObjectName(QString::fromUtf8("ignorepkgs"));

        verticalLayout_32->addWidget(ignorepkgs);


        verticalLayout_39->addWidget(widget_10);

        widget_16 = new QWidget(scrollAreaWidgetContents);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));
        sizePolicy.setHeightForWidth(widget_16->sizePolicy().hasHeightForWidth());
        widget_16->setSizePolicy(sizePolicy);
        verticalLayout_38 = new QVBoxLayout(widget_16);
        verticalLayout_38->setObjectName(QString::fromUtf8("verticalLayout_38"));
        label_37 = new QLabel(widget_16);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        sizePolicy.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy);

        verticalLayout_38->addWidget(label_37);

        ignoregrps = new QLineEdit(widget_16);
        ignoregrps->setObjectName(QString::fromUtf8("ignoregrps"));

        verticalLayout_38->addWidget(ignoregrps);


        verticalLayout_39->addWidget(widget_16);

        widget_15 = new QWidget(scrollAreaWidgetContents);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        sizePolicy.setHeightForWidth(widget_15->sizePolicy().hasHeightForWidth());
        widget_15->setSizePolicy(sizePolicy);
        verticalLayout_37 = new QVBoxLayout(widget_15);
        verticalLayout_37->setObjectName(QString::fromUtf8("verticalLayout_37"));
        label_36 = new QLabel(widget_15);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        sizePolicy.setHeightForWidth(label_36->sizePolicy().hasHeightForWidth());
        label_36->setSizePolicy(sizePolicy);

        verticalLayout_37->addWidget(label_36);

        holdpkgs = new QLineEdit(widget_15);
        holdpkgs->setObjectName(QString::fromUtf8("holdpkgs"));

        verticalLayout_37->addWidget(holdpkgs);


        verticalLayout_39->addWidget(widget_15);

        widget_14 = new QWidget(scrollAreaWidgetContents);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        sizePolicy.setHeightForWidth(widget_14->sizePolicy().hasHeightForWidth());
        widget_14->setSizePolicy(sizePolicy);
        verticalLayout_36 = new QVBoxLayout(widget_14);
        verticalLayout_36->setObjectName(QString::fromUtf8("verticalLayout_36"));
        label_35 = new QLabel(widget_14);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        sizePolicy.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy);

        verticalLayout_36->addWidget(label_35);

        timedb = new QLineEdit(widget_14);
        timedb->setObjectName(QString::fromUtf8("timedb"));

        verticalLayout_36->addWidget(timedb);


        verticalLayout_39->addWidget(widget_14);

        widget_13 = new QWidget(scrollAreaWidgetContents);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        sizePolicy.setHeightForWidth(widget_13->sizePolicy().hasHeightForWidth());
        widget_13->setSizePolicy(sizePolicy);
        verticalLayout_35 = new QVBoxLayout(widget_13);
        verticalLayout_35->setObjectName(QString::fromUtf8("verticalLayout_35"));
        label_34 = new QLabel(widget_13);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        sizePolicy.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy);

        verticalLayout_35->addWidget(label_34);

        timepkg = new QLineEdit(widget_13);
        timepkg->setObjectName(QString::fromUtf8("timepkg"));

        verticalLayout_35->addWidget(timepkg);


        verticalLayout_39->addWidget(widget_13);

        widget_11 = new QWidget(scrollAreaWidgetContents);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        sizePolicy.setHeightForWidth(widget_11->sizePolicy().hasHeightForWidth());
        widget_11->setSizePolicy(sizePolicy);
        verticalLayout_33 = new QVBoxLayout(widget_11);
        verticalLayout_33->setObjectName(QString::fromUtf8("verticalLayout_33"));

        verticalLayout_39->addWidget(widget_11);

        widget_12 = new QWidget(scrollAreaWidgetContents);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        sizePolicy.setHeightForWidth(widget_12->sizePolicy().hasHeightForWidth());
        widget_12->setSizePolicy(sizePolicy);
        verticalLayout_34 = new QVBoxLayout(widget_12);
        verticalLayout_34->setObjectName(QString::fromUtf8("verticalLayout_34"));

        verticalLayout_39->addWidget(widget_12);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        buttonBox = new QDialogButtonBox(config);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(config);
        QObject::connect(buttonBox, SIGNAL(accepted()), config, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), config, SLOT(reject()));

        QMetaObject::connectSlotsByName(config);
    } // setupUi

    void retranslateUi(QDialog *config)
    {
        config->setWindowTitle(QCoreApplication::translate("config", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("config", "Configure File", nullptr));
        label_28->setText(QCoreApplication::translate("config", "Database Path", nullptr));
        label_29->setText(QCoreApplication::translate("config", "Architecture", nullptr));
        label_27->setText(QCoreApplication::translate("config", "Log File", nullptr));
        label_30->setText(QCoreApplication::translate("config", "Hook Directory", nullptr));
        label_24->setText(QCoreApplication::translate("config", "Cache Directory", nullptr));
        label_23->setText(QCoreApplication::translate("config", "GPG Directory", nullptr));
        label_25->setText(QCoreApplication::translate("config", "No Upgrade", nullptr));
        label->setText(QCoreApplication::translate("config", "No Extract", nullptr));
        label_31->setText(QCoreApplication::translate("config", "Ignored Packages", nullptr));
        label_37->setText(QCoreApplication::translate("config", "Ignored Groups", nullptr));
        label_36->setText(QCoreApplication::translate("config", "Hold Packages", nullptr));
        label_35->setText(QCoreApplication::translate("config", "Download Timeout(Database)", nullptr));
        label_34->setText(QCoreApplication::translate("config", "Download Timeout(Package)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class config: public Ui_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
