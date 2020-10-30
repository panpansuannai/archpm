/********************************************************************************
** Form generated from reading UI file 'pkg_note.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PKG_NOTE_H
#define UI_PKG_NOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_pkg_note
{
public:
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *pkg_note)
    {
        if (pkg_note->objectName().isEmpty())
            pkg_note->setObjectName(QString::fromUtf8("pkg_note"));
        pkg_note->resize(567, 388);
        horizontalLayout = new QHBoxLayout(pkg_note);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textEdit = new QTextEdit(pkg_note);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout->addWidget(textEdit);

        buttonBox = new QDialogButtonBox(pkg_note);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(pkg_note);
        QObject::connect(buttonBox, SIGNAL(accepted()), pkg_note, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), pkg_note, SLOT(reject()));

        QMetaObject::connectSlotsByName(pkg_note);
    } // setupUi

    void retranslateUi(QDialog *pkg_note)
    {
        pkg_note->setWindowTitle(QCoreApplication::translate("pkg_note", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pkg_note: public Ui_pkg_note {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PKG_NOTE_H
