#pragma once

#include <QDialog>
#include <QLineEdit>

#include "pm2/configure.h"

namespace Ui {
class config;
}

class Config : public QDialog {
  Q_OBJECT

public:
  explicit Config(std::shared_ptr<Configure> config, QWidget *parent = nullptr);
  ~Config();
public slots:
  void accept();

private:
  Ui::config *ui;
  std::shared_ptr<Configure> config_;
};
