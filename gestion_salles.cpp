#include "gestion_salles.h"
#include "ui_gestion_salles.h"
#include <QString>
#include "cruds_salles.h"
#include <QMessageBox>
#include <QThread>
#include <QSound>
#include <QDebug>
gestion_salles::gestion_salles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_salles)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempsalles.afficher());
    player= new QMediaPlayer(this);
}

gestion_salles::~gestion_salles()
{
    delete ui;
}


void gestion_salles::on_ajouter_chaise_clicked()
{
    QString t = ui->lineEdit_taille_chaise->text();
    QString m = ui->lineEdit_chaise->text();
     QString q = ui->lineEdit_qualite_chaise->text();

      int i = ui->lineEdit_id_chaise->text().toInt();

     cruds_salles c(t,m,q,i);
     bool test = c.ajouter();
     if (test)
     {
         player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/chaise ajouter.mp3"));
             player->play();
             qDebug()<<player->errorString();
             QThread::sleep(1);
         ui->tableView->setModel(tempsalles.afficher());
         QMessageBox::information(nullptr,"AJOUT CHAISE","CHAISE AJOUTEE");
     }
     else
     {
         QMessageBox::warning(nullptr,"AJOUT FILM","CHAISE NON AJOUTEE");
     }
}

void gestion_salles::on_pushButton_supprimer_chaise_clicked()
{
    int i = ui->lineEdit_supp_chaise->text().toInt();
    bool test = tempsalles.supprimer(i);
    if (test)
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/chaise supprimer.mp3"));
            player->play();
            qDebug()<<player->errorString();
            QThread::sleep(1);
        ui->tableView->setModel(tempsalles.afficher());
        QMessageBox::information(nullptr,"SUPPRIMER CHAISE","CHAISE SUPPRIMER !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER CHAISE","CHAISE NON SUPPRIMER !");
    }
}

void gestion_salles::on_pushButton_modifier_clicked()
{
    QString t = ui->lineEdit_nouvelle_taille->text();
    QString m = ui->lineEdit_nouvelle_mark->text();
     QString q = ui->lineEdit_nouvelle_qualite->text();
      int i = ui->lineEdit_id->text().toInt();

     cruds_salles c(t,m,q,i);
     bool test = c.modifier();
     if (test)
     {
         player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/chaise modifier.mp3"));
             player->play();
             qDebug()<<player->errorString();
             QThread::sleep(1);
         ui->tableView->setModel(tempsalles.afficher());
         QMessageBox::information(nullptr,"MODIFIER CHAISE","CHAISE MODIFIER");
     }
     else
     {
         QMessageBox::warning(nullptr,"MODIFIER CHAISE","CHAISE NON MODIFIER");
     }
}

void gestion_salles::on_checkBox_clicked()
{
    bool test = true;
          if (test)
              {
              ui->tableView->setModel(tempsalles.afficher());

                  ui->tableView->setModel(tempsalles.trier_id());
              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier evenement"),
                                    QObject::tr("Erreur !.\n"));
          }
}

void gestion_salles::on_pushButton_3_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/chercherr.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(1);
    ui->tableView->setModel(tempsalles.afficher());
    QString taille = ui->lineEdit->text();
  ui->tableView_2->setModel(tempsalles.afficher_taille(taille));
}
