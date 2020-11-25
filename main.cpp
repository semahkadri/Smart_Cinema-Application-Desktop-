#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <connexion.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    connexion c;
    bool test=c.creat_cnx();
    if (test){
        qDebug()  <<"connexion etablie";

    }
    else {
        qDebug()  <<"erreur";
    }

    return a.exec();
}

