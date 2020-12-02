#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cruds_employer.h"
#include <QThread>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{

    close();
}

void MainWindow::on_pushButton_clicked()
{

    gf=new gestion_employer(this);
    gf->show();
}

void MainWindow::on_pushButton_2_clicked()
{


    gs=new gestion_profil(this);
    gs->show();
}
