/********************************************************************************
** Form generated from reading UI file 'entry.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTRY_H
#define UI_ENTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_entry
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *pkg_widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *pkg_name;
    QLabel *db;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *pkg_desc;
    QLabel *version;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QPushButton *remove;
    QPushButton *install;
    QPushButton *info;

    void setupUi(QWidget *entry)
    {
        if (entry->objectName().isEmpty())
            entry->setObjectName(QString::fromUtf8("entry"));
        entry->resize(437, 210);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(entry->sizePolicy().hasHeightForWidth());
        entry->setSizePolicy(sizePolicy);
        entry->setBaseSize(QSize(0, 0));
        entry->setCursor(QCursor(Qt::ArrowCursor));
        verticalLayout = new QVBoxLayout(entry);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(entry);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(3);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pkg_widget = new QWidget(frame);
        pkg_widget->setObjectName(QString::fromUtf8("pkg_widget"));
        sizePolicy.setHeightForWidth(pkg_widget->sizePolicy().hasHeightForWidth());
        pkg_widget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(pkg_widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        pkg_name = new QLabel(pkg_widget);
        pkg_name->setObjectName(QString::fromUtf8("pkg_name"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pkg_name->sizePolicy().hasHeightForWidth());
        pkg_name->setSizePolicy(sizePolicy2);
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Sans Thai UI"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        pkg_name->setFont(font);
        pkg_name->setTextFormat(Qt::RichText);
        pkg_name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pkg_name->setWordWrap(true);
        pkg_name->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_7->addWidget(pkg_name, 0, Qt::AlignHCenter);

        db = new QLabel(pkg_widget);
        db->setObjectName(QString::fromUtf8("db"));
        sizePolicy2.setHeightForWidth(db->sizePolicy().hasHeightForWidth());
        db->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Source Code Pro Light"));
        font1.setPointSize(10);
        db->setFont(font1);
        db->setFrameShadow(QFrame::Raised);
        db->setLineWidth(2);

        verticalLayout_7->addWidget(db, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        widget_2 = new QWidget(pkg_widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy2.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy2);
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));

        horizontalLayout_2->addWidget(widget_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pkg_desc = new QLabel(pkg_widget);
        pkg_desc->setObjectName(QString::fromUtf8("pkg_desc"));
        pkg_desc->setEnabled(true);
        sizePolicy2.setHeightForWidth(pkg_desc->sizePolicy().hasHeightForWidth());
        pkg_desc->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Noto Sans Thai UI"));
        font2.setItalic(false);
        pkg_desc->setFont(font2);
        pkg_desc->setFrameShape(QFrame::NoFrame);
        pkg_desc->setFrameShadow(QFrame::Plain);
        pkg_desc->setTextFormat(Qt::RichText);
        pkg_desc->setScaledContents(false);
        pkg_desc->setAlignment(Qt::AlignCenter);
        pkg_desc->setWordWrap(true);

        verticalLayout_4->addWidget(pkg_desc, 0, Qt::AlignHCenter);

        version = new QLabel(pkg_widget);
        version->setObjectName(QString::fromUtf8("version"));
        sizePolicy2.setHeightForWidth(version->sizePolicy().hasHeightForWidth());
        version->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Source Code Pro"));
        version->setFont(font3);
        version->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(version, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget = new QWidget(pkg_widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Noto Sans Thai"));
        widget->setFont(font4);
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        remove = new QPushButton(widget);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(remove->sizePolicy().hasHeightForWidth());
        remove->setSizePolicy(sizePolicy3);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Noto Sans Thai UI"));
        remove->setFont(font5);

        verticalLayout_6->addWidget(remove);

        install = new QPushButton(widget);
        install->setObjectName(QString::fromUtf8("install"));
        sizePolicy.setHeightForWidth(install->sizePolicy().hasHeightForWidth());
        install->setSizePolicy(sizePolicy);
        install->setFont(font5);

        verticalLayout_6->addWidget(install);

        info = new QPushButton(widget);
        info->setObjectName(QString::fromUtf8("info"));
        sizePolicy.setHeightForWidth(info->sizePolicy().hasHeightForWidth());
        info->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setFamily(QString::fromUtf8("Noto Sans"));
        font6.setPointSize(10);
        font6.setItalic(true);
        font6.setKerning(true);
        info->setFont(font6);
        info->setIconSize(QSize(10, 10));
        info->setAutoDefault(false);
        info->setFlat(false);

        verticalLayout_6->addWidget(info);


        horizontalLayout_2->addWidget(widget);


        verticalLayout_2->addWidget(pkg_widget);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addWidget(frame);


        retranslateUi(entry);

        info->setDefault(true);


        QMetaObject::connectSlotsByName(entry);
    } // setupUi

    void retranslateUi(QWidget *entry)
    {
        entry->setWindowTitle(QCoreApplication::translate("entry", "Form", nullptr));
        pkg_name->setText(QCoreApplication::translate("entry", "pkg", nullptr));
        db->setText(QCoreApplication::translate("entry", "database", nullptr));
        pkg_desc->setText(QCoreApplication::translate("entry", "pkg", nullptr));
        version->setText(QCoreApplication::translate("entry", "version", nullptr));
        remove->setText(QCoreApplication::translate("entry", "remove", nullptr));
        install->setText(QCoreApplication::translate("entry", "install", nullptr));
        info->setText(QCoreApplication::translate("entry", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class entry: public Ui_entry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRY_H
