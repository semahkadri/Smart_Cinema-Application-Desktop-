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

int main(int argc, char *argv[])
{  QApplication a(argc, argv);
    Connection c;

    MainWindow w;

    if(c.ouvrirconnexion())
    {
        login l;
        l.show();
        w.afficher();
        w.afficher2();
        QObject::connect(&l,&login::sig,&w,&MainWindow::show);

        return a.exec();
    }
    return 0;


}
