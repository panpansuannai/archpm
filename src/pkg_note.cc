#include "pkg_note.h"
#include "ui/ui_pkgnote.h"

pkg_note::pkg_note(QString *s, QWidget *parent)
    : QDialog(parent), text(s), ui(new Ui::pkgnote) {
  ui->setupUi(this);
  ui->textEdit->setText(*s);
  this->setWindowTitle("Add Note");
}

pkg_note::~pkg_note() { delete ui; }

void pkg_note::accept() {
  *text = ui->textEdit->toPlainText();
  close();
}
