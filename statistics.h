#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDialog>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>

namespace Ui {
class Statistics;
}

class Statistics : public QDialog
{
    Q_OBJECT

public:
    explicit Statistics(QWidget *parent = nullptr);
    ~Statistics();

private:
    Ui::Statistics *ui;
};

#endif // STATISTICS_H
