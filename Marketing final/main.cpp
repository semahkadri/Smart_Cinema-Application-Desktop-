#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QtDebug>
#include "login.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{  QApplication a(argc, argv);
    Connection c;

    MainWindow w;
    QTranslator t;

    QStringList languages;

    if(c.ouvrirconnexion())
    {
        languages << "English" << "French" << "Chinese";
        QString lang = QInputDialog :: getItem(NULL,"Select Language","Language",languages);

        if (lang == "English")
        {
            t.load (":/english.qm");
        }else if (lang == "Chinese")
        {
            t.load(":/chinese.qm");
        }

        if (lang != "English")
        {

            a.installTranslator(&t);
            login l;
            l.show();
            w.afficher();
            a.installTranslator(&t);

            w.afficher2();
            a.installTranslator(&t);

            QObject::connect(&l,&login::sig,&w,&MainWindow::show);

           return a.exec();

        }

        /*login l;
        l.show();
        w.afficher();
        w.afficher2();
        QObject::connect(&l,&login::sig,&w,&MainWindow::show);

        return a.exec();*/
    }
    return 0;


}
