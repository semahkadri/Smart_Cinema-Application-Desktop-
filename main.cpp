#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "connexion.h"
#include <QMessageBox>
#include <QThread>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
int main(int argc, char *argv[])
{


     QApplication a(argc, argv);
      QMediaPlayer * player = new QMediaPlayer;
      QVideoWidget * VW =new QVideoWidget ;
      player->setVideoOutput(VW);
      player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/aa.mpg"));
      VW->setGeometry(350,120,700,500);
      VW->show();
      player->play();
      qDebug() <<player->state();
      QThread::sleep(6);
      VW->close();
    //
      player= new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/bienvenue.mp3"));
            player->play();
            qDebug()<<player->errorString();
            //
            QMediaPlaylist *playlist = new QMediaPlaylist();
                playlist->addMedia(QUrl("C:/Users/user/Desktop/projet c++/QT/gestion_films/la.mp3"));
                playlist->setPlaybackMode(QMediaPlaylist::Loop);
                QMediaPlayer *music = new QMediaPlayer();
                music->setPlaylist(playlist);
                music->setVolume(1);
                music->play();


        //

    MainWindow w;
    w.show();
    connexion c;
    bool test=c.create_cnx();
        if(test)
        {

            qDebug() <<"connexion etablie";
        }
        else
        {

            qDebug() <<"ereur de connexion";
        }
    return a.exec();
}
