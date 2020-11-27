#include "statistiques.h"
#include "ui_statistiques.h"

statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);
    staisti::makePlot();
}

statistiques::~statistiques()
{
    delete ui;
}
void statistiques::makePlot()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
   ui->customPlot->addGraph();
     ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
     ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
     ui->customPlot->xAxis->setRange(-1, 1);
     ui->customPlot->yAxis->setRange(0, 1);
   ui->customPlot->replot();
}
