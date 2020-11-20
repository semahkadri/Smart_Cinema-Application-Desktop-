#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cruds_films.h"
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
    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/quitter.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(2);

    close();
}

void MainWindow::on_pushButton_clicked()
{
    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/gestion des films.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(1);

    gf=new gestion_film(this);
    gf->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/gestion des salles.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(1);

    gs=new gestion_salles(this);
    gs->show();
}
