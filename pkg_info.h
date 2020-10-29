#ifndef PKG_INFO_H
#define PKG_INFO_H

#include "entry.h"

#include <QDialog>

#include <alpm.h>

namespace Ui {
class pkg_info;
}

class pkg_info : public QDialog
{
    Q_OBJECT

public:
    entry *ent;
    explicit pkg_info(entry*,QWidget *parent = nullptr);
    void add_pkg_name(QString&,alpm_list_t*);
    void add_depend_name(QString&,alpm_list_t*);
    void add_file_name(QString&,alpm_list_t*);
    ~pkg_info();

public slots:
        void slot_install();
        void slot_remove();
        void slot_files();
        void slot_detail();
        void slot_depend();

        void slot_c_deps();
        void slot_c_files();
        void slot_add_note();
private:
    Ui::pkg_info *ui;
};

#endif // PKG_INFO_H
