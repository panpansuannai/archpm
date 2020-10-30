/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialog
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *layout;
    QLabel *title;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialog)
    {
        if (dialog->objectName().isEmpty())
            dialog->setObjectName(QString::fromUtf8("dialog"));
        dialog->setWindowModality(Qt::NonModal);
        dialog->setEnabled(true);
        dialog->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dialog->sizePolicy().hasHeightForWidth());
        dialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        layout = new QVBoxLayout();
        layout->setObjectName(QString::fromUtf8("layout"));
        title = new QLabel(dialog);
        title->setObjectName(QString::fromUtf8("title"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Sans Javanese"));
        title->setFont(font);
        title->setLayoutDirection(Qt::LeftToRight);
        title->setFrameShape(QFrame::NoFrame);

        layout->addWidget(title, 0, Qt::AlignHCenter);


        verticalLayout->addLayout(layout);

        buttonBox = new QDialogButtonBox(dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialog);
    } // setupUi

    void retranslateUi(QDialog *dialog)
    {
        dialog->setWindowTitle(QCoreApplication::translate("dialog", "Dialog", nullptr));
        title->setText(QCoreApplication::translate("dialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog: public Ui_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
