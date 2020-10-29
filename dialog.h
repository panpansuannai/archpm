#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>

#include "pm/interface.h"

namespace Ui {
class dialog;
}

class dialog : public QDialog
{
        Q_OBJECT

public:
        explicit dialog(int,QString,QString content = nullptr,QWidget *parent = nullptr);
        explicit dialog(QString,alpm_list_t*,QString add=nullptr,QWidget *parent = nullptr);

        QLabel* desc = nullptr;
        ~dialog();
signals:
        void sig_close();
public slots:
        void slot_close(); 

private:
    Ui::dialog *ui;
};

#endif // DIALOG_H
