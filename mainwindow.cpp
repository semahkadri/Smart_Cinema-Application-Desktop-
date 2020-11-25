
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cruds_films.h"
#include <QDebug>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QThread>
#include <QVideoWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
       connect(player,&QMediaPlayer::positionChanged,this, &MainWindow::on_positionchanged);
         connect(player,&QMediaPlayer::durationChanged,this, &MainWindow::on_durationchanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/quitter1.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(1);
//
        QVideoWidget * VW =new QVideoWidget ;
          player->setVideoOutput(VW);
          player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/gestion_films/thanks.mpg"));
          VW->setGeometry(350,120,700,500);
          VW->show();
          player->setVolume(10);
          player->play();
          qDebug() <<player->state();
          QThread::sleep(9);

          VW->close();
          close();
        //
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
//
void MainWindow::on_sliderprogress_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::on_slidervolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_pushButton_4_clicked()
{
    player->setMedia(QUrl("C:/Users/user/Desktop/projet c++/QT/gestion_films/la.mp3"));
       player->play();
       qDebug()<<player->errorString();
}
void MainWindow::on_pushButton_5_clicked()
{
    player->stop();
}
void MainWindow::on_positionchanged(qint64 position)
{
ui->sliderprogress->setValue(position);
}
void MainWindow::on_durationchanged(qint64 position)
{
ui->sliderprogress->setMaximum(position);
}

