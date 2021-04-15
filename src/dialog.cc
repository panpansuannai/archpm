#include "dialog.h"
#include "ui/ui_dialog.h"
#include <QScrollArea>

#include "pm/interface.h"

Dialog::Dialog(QString title, QString content, QWidget *parent)
    : QDialog(parent), ui(new Ui::dialog) {
  ui->setupUi(this);

  this->setWindowTitle(title);

  QScrollArea *area = new QScrollArea();
  area->setSizePolicy(
      QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
  ui->layout->addWidget(area);

  desc = new QLabel(this);
  QSizePolicy policy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  desc->setSizePolicy(policy);
  desc->setAlignment(Qt::AlignCenter | Qt::AlignTop);

  desc->setText(content);
  area->setWidget(desc);
}

void Dialog::slot_close() { this->~Dialog(); }

Dialog::~Dialog() { delete ui; }
