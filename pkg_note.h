#ifndef PKG_NOTE_H
#define PKG_NOTE_H

#include <QDialog>

namespace Ui {
class pkg_note;
}

class pkg_note : public QDialog
{
    Q_OBJECT

public:
    explicit pkg_note(QString* ,QWidget *parent = nullptr);
    QString* text;
    ~pkg_note();
public slots:
    void accept();

private:
    Ui::pkg_note *ui;
};

#endif // PKG_NOTE_H
