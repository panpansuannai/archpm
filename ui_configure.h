/********************************************************************************
** Form generated from reading UI file 'configure.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURE_H
#define UI_CONFIGURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configure
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_22;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *dbpath;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_12;
    QLineEdit *cachedir;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLineEdit *logfile;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QLineEdit *hookdir;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QLineEdit *holdpkg;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QLineEdit *arch;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QLineEdit *ignorepkgs;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_8;
    QLineEdit *noupgrade;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_10;
    QLineEdit *noextract;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *configure)
    {
        if (configure->objectName().isEmpty())
            configure->setObjectName(QString::fromUtf8("configure"));
        configure->resize(853, 542);
        verticalLayout = new QVBoxLayout(configure);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(configure);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -398, 815, 918));
        verticalLayout_22 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(label);

        dbpath = new QLineEdit(widget);
        dbpath->setObjectName(QString::fromUtf8("dbpath"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dbpath->sizePolicy().hasHeightForWidth());
        dbpath->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(dbpath);


        verticalLayout_22->addWidget(widget);

        widget_7 = new QWidget(scrollAreaWidgetContents);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy3);
        verticalLayout_2 = new QVBoxLayout(widget_7);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_12 = new QLabel(widget_7);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(label_12);

        cachedir = new QLineEdit(widget_7);
        cachedir->setObjectName(QString::fromUtf8("cachedir"));
        sizePolicy2.setHeightForWidth(cachedir->sizePolicy().hasHeightForWidth());
        cachedir->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(cachedir);


        verticalLayout_22->addWidget(widget_7);

        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(label_2);

        logfile = new QLineEdit(widget_2);
        logfile->setObjectName(QString::fromUtf8("logfile"));

        verticalLayout_4->addWidget(logfile);


        verticalLayout_22->addWidget(widget_2);

        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(widget_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(label_3);

        hookdir = new QLineEdit(widget_3);
        hookdir->setObjectName(QString::fromUtf8("hookdir"));

        verticalLayout_5->addWidget(hookdir);


        verticalLayout_22->addWidget(widget_3);

        widget_4 = new QWidget(scrollAreaWidgetContents);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(label_4);

        holdpkg = new QLineEdit(widget_4);
        holdpkg->setObjectName(QString::fromUtf8("holdpkg"));

        verticalLayout_6->addWidget(holdpkg);


        verticalLayout_22->addWidget(widget_4);

        widget_5 = new QWidget(scrollAreaWidgetContents);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        verticalLayout_7 = new QVBoxLayout(widget_5);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(label_5);

        arch = new QLineEdit(widget_5);
        arch->setObjectName(QString::fromUtf8("arch"));

        verticalLayout_7->addWidget(arch);


        verticalLayout_22->addWidget(widget_5);

        widget_6 = new QWidget(scrollAreaWidgetContents);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        sizePolicy.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy);
        verticalLayout_8 = new QVBoxLayout(widget_6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        verticalLayout_8->addWidget(label_6);

        ignorepkgs = new QLineEdit(widget_6);
        ignorepkgs->setObjectName(QString::fromUtf8("ignorepkgs"));

        verticalLayout_8->addWidget(ignorepkgs);


        verticalLayout_22->addWidget(widget_6);

        widget_8 = new QWidget(scrollAreaWidgetContents);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        sizePolicy.setHeightForWidth(widget_8->sizePolicy().hasHeightForWidth());
        widget_8->setSizePolicy(sizePolicy);
        verticalLayout_10 = new QVBoxLayout(widget_8);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_8 = new QLabel(widget_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        verticalLayout_10->addWidget(label_8);

        noupgrade = new QLineEdit(widget_8);
        noupgrade->setObjectName(QString::fromUtf8("noupgrade"));

        verticalLayout_10->addWidget(noupgrade);


        verticalLayout_22->addWidget(widget_8);

        widget_10 = new QWidget(scrollAreaWidgetContents);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        sizePolicy.setHeightForWidth(widget_10->sizePolicy().hasHeightForWidth());
        widget_10->setSizePolicy(sizePolicy);
        verticalLayout_12 = new QVBoxLayout(widget_10);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_10 = new QLabel(widget_10);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        verticalLayout_12->addWidget(label_10);

        noextract = new QLineEdit(widget_10);
        noextract->setObjectName(QString::fromUtf8("noextract"));

        verticalLayout_12->addWidget(noextract);

        buttonBox = new QDialogButtonBox(widget_10);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_12->addWidget(buttonBox);


        verticalLayout_22->addWidget(widget_10);

        scrollArea->setWidget(scrollAreaWidgetContents);
        widget->raise();
        widget_2->raise();
        widget_3->raise();
        widget_4->raise();
        widget_5->raise();
        widget_6->raise();
        widget_8->raise();
        widget_10->raise();
        widget_7->raise();

        verticalLayout->addWidget(scrollArea);


        retranslateUi(configure);

        QMetaObject::connectSlotsByName(configure);
    } // setupUi

    void retranslateUi(QWidget *configure)
    {
        configure->setWindowTitle(QCoreApplication::translate("configure", "Configure", nullptr));
        label->setText(QCoreApplication::translate("configure", "database path", nullptr));
        label_12->setText(QCoreApplication::translate("configure", "cache directory", nullptr));
        label_2->setText(QCoreApplication::translate("configure", "log file", nullptr));
        label_3->setText(QCoreApplication::translate("configure", "hook directory", nullptr));
        label_4->setText(QCoreApplication::translate("configure", "hold packages", nullptr));
        label_5->setText(QCoreApplication::translate("configure", "architecture", nullptr));
        label_6->setText(QCoreApplication::translate("configure", "ignore packages", nullptr));
        label_8->setText(QCoreApplication::translate("configure", "don't upgrade", nullptr));
        label_10->setText(QCoreApplication::translate("configure", "don't extract", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configure: public Ui_configure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURE_H
