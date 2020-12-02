#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "connexion.h"
#include <QMessageBox>
#include <QThread>
#include "login.h"
int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("  Smart Cinema");
   // w.show();
    QGuiApplication::setWindowIcon(QIcon("D:/OneDrive/Bureau/smart logo/smart logo.jpg"));


    login l;
        l.show();
         l.setWindowTitle("  Login ");
         QGuiApplication::setWindowIcon(QIcon("D:/OneDrive/Bureau/smart logo/smart logooooo.png"));

        QObject::connect(&l,&login::sig,&w,&MainWindow::show);

    connexion c;
    bool test=c.create_cnx();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("database is open"),
                                 QObject::tr("connexion etablie"),QMessageBox::Ok);
        //qDebug() <<"connexion etablie";

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                 QObject::tr("erreur de connexion"),QMessageBox::Cancel);
        //qDebug() <<"ereur de connexion";
    }
    return a.exec();
}
