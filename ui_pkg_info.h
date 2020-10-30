/********************************************************************************
** Form generated from reading UI file 'pkg_info.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PKG_INFO_H
#define UI_PKG_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pkg_info
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *detail;
    QPushButton *depend;
    QPushButton *files;
    QSpacerItem *verticalSpacer;
    QPushButton *add_note;
    QPushButton *check_deps;
    QPushButton *check_files;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *name;
    QLabel *desc;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *install;
    QPushButton *remove;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *pkg_info)
    {
        if (pkg_info->objectName().isEmpty())
            pkg_info->setObjectName(QString::fromUtf8("pkg_info"));
        pkg_info->resize(900, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pkg_info->sizePolicy().hasHeightForWidth());
        pkg_info->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(pkg_info);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(pkg_info);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        detail = new QPushButton(widget);
        detail->setObjectName(QString::fromUtf8("detail"));
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Sans Thai UI"));
        font.setPointSize(12);
        detail->setFont(font);

        verticalLayout_2->addWidget(detail);

        depend = new QPushButton(widget);
        depend->setObjectName(QString::fromUtf8("depend"));
        depend->setFont(font);

        verticalLayout_2->addWidget(depend);

        files = new QPushButton(widget);
        files->setObjectName(QString::fromUtf8("files"));
        files->setFont(font);

        verticalLayout_2->addWidget(files);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        add_note = new QPushButton(widget);
        add_note->setObjectName(QString::fromUtf8("add_note"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Noto Sans Thai UI"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        add_note->setFont(font1);

        verticalLayout_2->addWidget(add_note);

        check_deps = new QPushButton(widget);
        check_deps->setObjectName(QString::fromUtf8("check_deps"));
        check_deps->setFont(font);

        verticalLayout_2->addWidget(check_deps);

        check_files = new QPushButton(widget);
        check_files->setObjectName(QString::fromUtf8("check_files"));
        check_files->setFont(font);

        verticalLayout_2->addWidget(check_files);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(widget);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy2);
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Sunken);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widget_4 = new QWidget(frame_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Noto Sans Sinhala UI"));
        font2.setUnderline(false);
        widget_4->setFont(font2);
        widget_4->setMouseTracking(false);
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        name = new QLabel(widget_4);
        name->setObjectName(QString::fromUtf8("name"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Noto Kufi Arabic"));
        font3.setBold(true);
        font3.setUnderline(false);
        font3.setWeight(75);
        name->setFont(font3);

        verticalLayout_6->addWidget(name);

        desc = new QLabel(widget_4);
        desc->setObjectName(QString::fromUtf8("desc"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Noto Sans Thin"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setUnderline(false);
        font4.setWeight(50);
        desc->setFont(font4);
        desc->setTextFormat(Qt::AutoText);
        desc->setWordWrap(true);

        verticalLayout_6->addWidget(desc);


        horizontalLayout_3->addWidget(widget_4);

        widget_5 = new QWidget(frame_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        sizePolicy1.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy1);
        verticalLayout_5 = new QVBoxLayout(widget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        install = new QPushButton(widget_5);
        install->setObjectName(QString::fromUtf8("install"));
        install->setFont(font);

        verticalLayout_5->addWidget(install);

        remove = new QPushButton(widget_5);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setFont(font);

        verticalLayout_5->addWidget(remove);


        horizontalLayout_3->addWidget(widget_5);


        verticalLayout_3->addWidget(frame_3);

        scrollArea = new QScrollArea(frame_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 708, 365));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy3);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Noto Sans Sinhala UI"));
        scrollAreaWidgetContents->setFont(font5);
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        horizontalLayout->addWidget(frame_2);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(pkg_info);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy4);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(pkg_info);
        QObject::connect(buttonBox, SIGNAL(accepted()), pkg_info, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), pkg_info, SLOT(reject()));

        QMetaObject::connectSlotsByName(pkg_info);
    } // setupUi

    void retranslateUi(QDialog *pkg_info)
    {
        pkg_info->setWindowTitle(QCoreApplication::translate("pkg_info", "Dialog", nullptr));
        detail->setText(QCoreApplication::translate("pkg_info", "Detail", nullptr));
        depend->setText(QCoreApplication::translate("pkg_info", "Depend", nullptr));
        files->setText(QCoreApplication::translate("pkg_info", "Files", nullptr));
        add_note->setText(QCoreApplication::translate("pkg_info", "addNote", nullptr));
        check_deps->setText(QCoreApplication::translate("pkg_info", "checkDeps", nullptr));
        check_files->setText(QCoreApplication::translate("pkg_info", "checkFiles", nullptr));
        name->setText(QCoreApplication::translate("pkg_info", "TextLabel", nullptr));
        desc->setText(QCoreApplication::translate("pkg_info", "TextLabel", nullptr));
        install->setText(QCoreApplication::translate("pkg_info", "Install", nullptr));
        remove->setText(QCoreApplication::translate("pkg_info", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pkg_info: public Ui_pkg_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PKG_INFO_H
