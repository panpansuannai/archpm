#ifndef CONFIG_H
#define CONFIG_H

#include <QDialog>
#include <QLineEdit>

#include "pm/interface.h"

namespace Ui {
class config;
}

class config : public QDialog
{
        Q_OBJECT

public:
        explicit config(QWidget *parent = nullptr,conf_t* _conf=nullptr);
        conf_t* conf;
        void list_config(QLineEdit*,alpm_list_t*);
        ~config();
public slots:
        void accept();
private:
        Ui::config *ui;
};

#endif // CONFIG_H
