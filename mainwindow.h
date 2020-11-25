#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gestion_film.h"
#include "gestion_salles.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_sliderprogress_sliderMoved(int position);

    void on_slidervolume_sliderMoved(int position);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_positionchanged(qint64 position);

    void on_durationchanged(qint64 position);

    void on_pushButton_6_clicked();


private:
    Ui::MainWindow *ui;
    gestion_film *gf;
    gestion_salles *gs;
    QMediaPlayer *player;

};
#endif // MAINWINDOW_H
