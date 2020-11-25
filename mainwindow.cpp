#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employer.h"

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


void MainWindow::on_gereremployer_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_gererprofil_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_ajouteremployer_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButtoncancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtoncancelprofil_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_ajouterprofil_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButtonok_clicked()
{
int idemp = ui-> lineEditidemp ->text().toInt();
QString nomemp = ui->lineEditnomemp->text();
QString prenomemp = ui->lineEditprenomemp->text();
QString mailemp = ui->lineEditmailemp->text();
employer e(idemp,nomemp,prenomemp,mailemp);

bool test = e.ajouter();
if (test)
{
    QMessageBox::information(nullptr,"Ajout employer","employer ajouté !");
}

}
