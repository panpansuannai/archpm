#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class dialog;
}

class Dialog : public QDialog {
  Q_OBJECT

public:
  explicit Dialog(QString, QString, QWidget *parent = nullptr);

  QLabel *desc = nullptr;
  ~Dialog();
signals:
  void sig_close();
public slots:
  void slot_close();

private:
  Ui::dialog *ui;
};

#endif // DIALOG_H
