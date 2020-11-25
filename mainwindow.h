#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employer.h"
#include<QMessageBox>
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
    void on_gereremployer_clicked();

    void on_home_clicked();

    void on_gererprofil_clicked();

    void on_ajouteremployer_clicked();

    void on_pushButtoncancel_clicked();

    void on_pushButtoncancelprofil_clicked();

    void on_ajouterprofil_clicked();

    void on_pushButtonok_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
