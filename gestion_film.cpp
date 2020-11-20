#include "gestion_film.h"
#include "ui_gestion_film.h"
#include <QString>
#include "cruds_films.h"
#include <QSound>
#include <QDebug>
#include <QMessageBox>
#include <QThread>
#include<QPixmap>
#include <QGridLayout>
gestion_film::gestion_film(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_film)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempfilm.afficher());
    player= new QMediaPlayer(this);
}

gestion_film::~gestion_film()
{
    delete ui;
}



void gestion_film::on_ajouter_film_clicked()
{
   QString n = ui->lineEdit_nom_film->text();
   QString l= ui->lineEdit_language_film->text();
    int i = ui->lineEdit_id_film->text().toInt();
    QString t = ui->lineEdit_type_film->text();
     int d = ui->lineEdit_duree_film->text().toInt();

    cruds_films c(n,l,d,i,t);
    bool test = c.ajouter();
    if (test)
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/film ajouter.mp3"));
            player->play();
            qDebug()<<player->errorString();
            QThread::sleep(1);
        ui->tableView->setModel(tempfilm.afficher());
        QMessageBox::information(nullptr,"AJOUT FILM","FILM AJOUTEE");
    }
    else
    {
        QMessageBox::warning(nullptr,"AJOUT FILM","FILM NON AJOUTEE");
    }
}


void gestion_film::on_pushButton_supprimer_clicked()
{
    int i = ui->lineEdit_supp->text().toInt();
    bool test = tempfilm.supprimer(i);
    if (test)
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/film supprimer.mp3"));
            player->play();
            qDebug()<<player->errorString();
            QThread::sleep(1);
        ui->tableView->setModel(tempfilm.afficher());
        QMessageBox::information(nullptr,"SUPPRIMER FILM","FILM SUPPRIMER !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER FILM","FILM NON SUPPRIMER !");
    }
}
void gestion_film::on_pushButton_modifier_clicked()
{
    QString n = ui->lineEdit_nouveau_nom->text();
    QString l= ui->lineEdit_nouveau_language->text();
     int i = ui->lineEdit_id->text().toInt();
     QString t = ui->lineEdit_nouveau_type->text();
      int d = ui->lineEdit_nouveau_duree->text().toInt();
    cruds_films c(n,l,d,i,t);
    bool test = c.modifier();
         if (test)
         {
             player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/film modifier.mp3"));
                 player->play();
                 qDebug()<<player->errorString();
                 QThread::sleep(1);
             ui->tableView->setModel(tempfilm.afficher());
             QMessageBox::information(nullptr,"MODIFER CLIENT","MODFIER AJOUTEE");
         }
         else
         {
             QMessageBox::warning(nullptr,"MODIFER CLIENT","CLIENT NON MODIFER");
         }
}



void gestion_film::on_checkBox_nom_clicked()
{
    bool test = true;
          if (test)
              {
              ui->tableView->setModel(tempfilm.afficher());

                  ui->tableView->setModel(tempfilm.trier_nom());
              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier evenement"),
                                    QObject::tr("Erreur !.\n"));
          }
}


void gestion_film::on_checkBox_duree_clicked()
{
    bool test = true;
          if (test)
              {
              ui->tableView->setModel(tempfilm.afficher());

                  ui->tableView->setModel(tempfilm.trier_duree());
              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier evenement"),
                                    QObject::tr("Erreur !.\n"));
          }
}
void gestion_film::on_checkBox_language_clicked()
{
    bool test = true;
          if (test)
              {
              ui->tableView->setModel(tempfilm.afficher());

                  ui->tableView->setModel(tempfilm.trier_id());
              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier evenement"),
                                    QObject::tr("Erreur !.\n"));
          }
}

void gestion_film::on_pushButton_3_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/chercher.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(1);
     ui->tableView->setModel(tempfilm.afficher());
    QString nom = ui->lineEdit->text();
   ui->tableView_2->setModel(tempfilm.afficher_nom(nom));



}
