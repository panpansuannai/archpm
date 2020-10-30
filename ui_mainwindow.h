/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QAction *actionInstallation;
    QAction *actionRemove_Package;
    QAction *actionSoftware_Source;
    QAction *actionFixlck;
    QAction *actionAbout_Author;
    QAction *actionAbout_Author_2;
    QAction *actionUser_Guider;
    QAction *actionInstall_from_file;
    QAction *actionCleandis;
    QAction *actionConfigure;
    QAction *actionDatabase_Update;
    QAction *action;
    QAction *actionClean_cache;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QComboBox *pagecnt;
    QPushButton *next;
    QPushButton *prev;
    QPushButton *insall;
    QPushButton *rmall;
    QSpacerItem *verticalSpacer_2;
    QPushButton *installed;
    QPushButton *orphans;
    QPushButton *updates;
    QPushButton *depend;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QComboBox *method;
    QComboBox *boxTreename;
    QLineEdit *editorSearch;
    QPushButton *buttonSearch;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *entries_display;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuSetting;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName(QString::fromUtf8("mainwindow"));
        mainwindow->setEnabled(true);
        mainwindow->resize(1049, 678);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainwindow->sizePolicy().hasHeightForWidth());
        mainwindow->setSizePolicy(sizePolicy);
        mainwindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        mainwindow->setTabShape(QTabWidget::Triangular);
        actionInstallation = new QAction(mainwindow);
        actionInstallation->setObjectName(QString::fromUtf8("actionInstallation"));
        actionRemove_Package = new QAction(mainwindow);
        actionRemove_Package->setObjectName(QString::fromUtf8("actionRemove_Package"));
        actionSoftware_Source = new QAction(mainwindow);
        actionSoftware_Source->setObjectName(QString::fromUtf8("actionSoftware_Source"));
        actionFixlck = new QAction(mainwindow);
        actionFixlck->setObjectName(QString::fromUtf8("actionFixlck"));
        actionAbout_Author = new QAction(mainwindow);
        actionAbout_Author->setObjectName(QString::fromUtf8("actionAbout_Author"));
        actionAbout_Author_2 = new QAction(mainwindow);
        actionAbout_Author_2->setObjectName(QString::fromUtf8("actionAbout_Author_2"));
        actionUser_Guider = new QAction(mainwindow);
        actionUser_Guider->setObjectName(QString::fromUtf8("actionUser_Guider"));
        actionInstall_from_file = new QAction(mainwindow);
        actionInstall_from_file->setObjectName(QString::fromUtf8("actionInstall_from_file"));
        actionCleandis = new QAction(mainwindow);
        actionCleandis->setObjectName(QString::fromUtf8("actionCleandis"));
        actionConfigure = new QAction(mainwindow);
        actionConfigure->setObjectName(QString::fromUtf8("actionConfigure"));
        actionDatabase_Update = new QAction(mainwindow);
        actionDatabase_Update->setObjectName(QString::fromUtf8("actionDatabase_Update"));
        action = new QAction(mainwindow);
        action->setObjectName(QString::fromUtf8("action"));
        actionClean_cache = new QAction(mainwindow);
        actionClean_cache->setObjectName(QString::fromUtf8("actionClean_cache"));
        centralwidget = new QWidget(mainwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pagecnt = new QComboBox(widget);
        pagecnt->addItem(QString());
        pagecnt->addItem(QString());
        pagecnt->addItem(QString());
        pagecnt->addItem(QString());
        pagecnt->setObjectName(QString::fromUtf8("pagecnt"));

        verticalLayout->addWidget(pagecnt);

        next = new QPushButton(widget);
        next->setObjectName(QString::fromUtf8("next"));
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Sans Thai"));
        font.setPointSize(12);
        next->setFont(font);

        verticalLayout->addWidget(next);

        prev = new QPushButton(widget);
        prev->setObjectName(QString::fromUtf8("prev"));
        prev->setFont(font);

        verticalLayout->addWidget(prev);

        insall = new QPushButton(widget);
        insall->setObjectName(QString::fromUtf8("insall"));
        insall->setFont(font);

        verticalLayout->addWidget(insall);

        rmall = new QPushButton(widget);
        rmall->setObjectName(QString::fromUtf8("rmall"));
        rmall->setFont(font);

        verticalLayout->addWidget(rmall);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        installed = new QPushButton(widget);
        installed->setObjectName(QString::fromUtf8("installed"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Noto Sans Thai UI"));
        font1.setPointSize(12);
        installed->setFont(font1);

        verticalLayout->addWidget(installed);

        orphans = new QPushButton(widget);
        orphans->setObjectName(QString::fromUtf8("orphans"));
        orphans->setFont(font1);

        verticalLayout->addWidget(orphans);

        updates = new QPushButton(widget);
        updates->setObjectName(QString::fromUtf8("updates"));
        updates->setFont(font1);

        verticalLayout->addWidget(updates);

        depend = new QPushButton(widget);
        depend->setObjectName(QString::fromUtf8("depend"));
        depend->setFont(font1);

        verticalLayout->addWidget(depend);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        method = new QComboBox(widget_3);
        method->addItem(QString());
        method->addItem(QString());
        method->addItem(QString());
        method->setObjectName(QString::fromUtf8("method"));

        horizontalLayout->addWidget(method);

        boxTreename = new QComboBox(widget_3);
        boxTreename->addItem(QString());
        boxTreename->addItem(QString());
        boxTreename->addItem(QString());
        boxTreename->addItem(QString());
        boxTreename->addItem(QString());
        boxTreename->setObjectName(QString::fromUtf8("boxTreename"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Noto Sans Thai UI"));
        boxTreename->setFont(font2);

        horizontalLayout->addWidget(boxTreename);

        editorSearch = new QLineEdit(widget_3);
        editorSearch->setObjectName(QString::fromUtf8("editorSearch"));

        horizontalLayout->addWidget(editorSearch);

        buttonSearch = new QPushButton(widget_3);
        buttonSearch->setObjectName(QString::fromUtf8("buttonSearch"));
        buttonSearch->setFont(font2);

        horizontalLayout->addWidget(buttonSearch);


        verticalLayout_3->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(widget_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setFrameShape(QFrame::Panel);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setLineWidth(3);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setEnabled(true);
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 866, 22));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy3);
        scrollAreaWidgetContents->setAutoFillBackground(true);
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        entries_display = new QVBoxLayout();
        entries_display->setObjectName(QString::fromUtf8("entries_display"));
        entries_display->setSizeConstraint(QLayout::SetNoConstraint);

        verticalLayout_5->addLayout(entries_display);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        verticalLayout_3->addWidget(widget_4);


        horizontalLayout_2->addWidget(widget_2);

        mainwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1049, 35));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        mainwindow->setMenuBar(menubar);
        statusBar = new QStatusBar(mainwindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy4);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Noto Sans Thai UI"));
        font3.setPointSize(12);
        font3.setItalic(true);
        statusBar->setFont(font3);
        statusBar->setSizeGripEnabled(false);
        mainwindow->setStatusBar(statusBar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuSetting->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuMenu->addAction(actionDatabase_Update);
        menuMenu->addSeparator();
        menuMenu->addAction(actionFixlck);
        menuMenu->addSeparator();
        menuMenu->addAction(actionCleandis);
        menuSetting->addSeparator();
        menuSetting->addAction(actionConfigure);
        menuHelp->addAction(actionAbout_Author);

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindow)
    {
        mainwindow->setWindowTitle(QCoreApplication::translate("mainwindow", "archpm", nullptr));
        actionInstallation->setText(QCoreApplication::translate("mainwindow", "Installed Packages", nullptr));
        actionRemove_Package->setText(QCoreApplication::translate("mainwindow", "Remove Packages", nullptr));
        actionSoftware_Source->setText(QCoreApplication::translate("mainwindow", "Software Source", nullptr));
        actionFixlck->setText(QCoreApplication::translate("mainwindow", "Fix DBLock", nullptr));
        actionAbout_Author->setText(QCoreApplication::translate("mainwindow", "About Archpm", nullptr));
        actionAbout_Author_2->setText(QCoreApplication::translate("mainwindow", "About Author", nullptr));
        actionUser_Guider->setText(QCoreApplication::translate("mainwindow", "User Guider", nullptr));
        actionInstall_from_file->setText(QCoreApplication::translate("mainwindow", "Lauch Terminal", nullptr));
        actionCleandis->setText(QCoreApplication::translate("mainwindow", "Clean Display", nullptr));
        actionConfigure->setText(QCoreApplication::translate("mainwindow", "Configure", nullptr));
        actionDatabase_Update->setText(QCoreApplication::translate("mainwindow", "Database Update", nullptr));
        action->setText(QCoreApplication::translate("mainwindow", "Back Up", nullptr));
        actionClean_cache->setText(QCoreApplication::translate("mainwindow", "Clean Cache", nullptr));
        pagecnt->setItemText(0, QCoreApplication::translate("mainwindow", "16", nullptr));
        pagecnt->setItemText(1, QCoreApplication::translate("mainwindow", "32", nullptr));
        pagecnt->setItemText(2, QCoreApplication::translate("mainwindow", "64", nullptr));
        pagecnt->setItemText(3, QCoreApplication::translate("mainwindow", "128", nullptr));

        next->setText(QCoreApplication::translate("mainwindow", "Next", nullptr));
        prev->setText(QCoreApplication::translate("mainwindow", "Previous", nullptr));
        insall->setText(QCoreApplication::translate("mainwindow", "InsAll", nullptr));
        rmall->setText(QCoreApplication::translate("mainwindow", "RmAll", nullptr));
        installed->setText(QCoreApplication::translate("mainwindow", "Installed", nullptr));
        orphans->setText(QCoreApplication::translate("mainwindow", "Orphans", nullptr));
        updates->setText(QCoreApplication::translate("mainwindow", "Updates", nullptr));
        depend->setText(QCoreApplication::translate("mainwindow", "Depend", nullptr));
        method->setItemText(0, QCoreApplication::translate("mainwindow", "Internal Regex", nullptr));
        method->setItemText(1, QCoreApplication::translate("mainwindow", "KMP", nullptr));
        method->setItemText(2, QCoreApplication::translate("mainwindow", "Trie", nullptr));

        boxTreename->setItemText(0, QCoreApplication::translate("mainwindow", "All", nullptr));
        boxTreename->setItemText(1, QCoreApplication::translate("mainwindow", "core", nullptr));
        boxTreename->setItemText(2, QCoreApplication::translate("mainwindow", "community", nullptr));
        boxTreename->setItemText(3, QCoreApplication::translate("mainwindow", "extra", nullptr));
        boxTreename->setItemText(4, QCoreApplication::translate("mainwindow", "local", nullptr));

        buttonSearch->setText(QCoreApplication::translate("mainwindow", "Search", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("mainwindow", "Menu", nullptr));
        menuSetting->setTitle(QCoreApplication::translate("mainwindow", "Setting", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("mainwindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
