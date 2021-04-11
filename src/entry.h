#ifndef ENTRY_H
#define ENTRY_H

#include <QWidget>
#include "pm/interface.h"

namespace Ui {
class entry;
}

class entry : public QWidget
{
        Q_OBJECT

public:
        explicit entry(alpm_pkg_t*,operation*);
        alpm_pkg_t* package;
        operation* op;
        ~entry();
        Ui::entry *ui;
signals:
        void sig_remove_pkg(entry*);
        void sig_install_pkg();
public slots:
        void show_pkg_info();
        void install_pkg();
        void remove_pkg();
};

#endif // ENTRY_H
