#include "statistics.h"
#include "ui_statistics.h"

QT_CHARTS_USE_NAMESPACE
Statistics::Statistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistics)
{
    ui->setupUi(this);
    QPieSeries *series = new QPieSeries();
    series->append("Coca cola",.40);
    series->append("Popcorn",.30);
    series->append("Fanta",.30);
    series->setHoleSize(0.2);
    QPieSlice *slice = series->slices().at(0);
    slice->setLabelVisible();

    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();

    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Most sold products");
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->horizontalFrame);
}

Statistics::~Statistics()
{
    delete ui;
}
