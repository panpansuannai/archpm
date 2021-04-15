#include "mainwindow.h"
#include "dialog.h"

#include <QApplication>
#include <QMessageBox>

int check_uid()
{
        int uid = getuid();
        if(uid!=0){
                return 1;
        }
        return 0;
}

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        if(check_uid()){
                Dialog("", "You must to have root privileage").exec();
                //exit(1);
        }
        mainwindow w;
        w.show();
        return a.exec();
}
