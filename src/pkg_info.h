#ifndef PKG_INFO_H
#define PKG_INFO_H

#include "pkg_entry.h"

#include <QDialog>

#include <alpm.h>

namespace Ui {
class pkginfo;
}

class PkgInfo : public QDialog
{
    Q_OBJECT

public:
    explicit PkgInfo(Package::PackagePtr, QWidget *parent = nullptr);
    void add_pkg_name(QLayout*,alpm_list_t*);
    void add_depend_name(QLayout*,alpm_list_t*);
    void add_file_name(QString&,alpm_list_t*);
    ~PkgInfo();

public slots:
        void slot_install();
        void slot_remove();
        void slot_files();
        void slot_detail();
        void slot_depend();

        void slot_c_deps();
        void slot_c_files();
        void slot_add_note();
        void slot_newinfo(QString);
private:
    Package::PackagePtr package_;
    Ui::pkginfo *ui;
};

#endif // PKG_INFO_H
