#include "mainwindow.h"
#include "dialog.h"

#include "pm/interface.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        if(check_uid()){
                dialog(0,"You must to have root privileage").exec();
                exit(1);
        }
        mainwindow w;
        w.show();
        return a.exec();
}
