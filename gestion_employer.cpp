#include "ui_gestion_employer.h"
#include"dialog.h"
#include "gestion_employer.h"
#include <QString>
#include "cruds_employer.h"
#include <QSound>
#include <QDebug>
#include <QMessageBox>
#include <QThread>
#include<QPixmap>
#include <QGridLayout>
gestion_employer::gestion_employer(QWidget *parent) :
    QDialog(parent),
    ui(new  Ui::gestion_employer)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempemployer.afficher());
    player= new QMediaPlayer(this);


}

gestion_employer::~gestion_employer()
{
    delete ui;
}



void gestion_employer::on_ajouter_employer_clicked()
{
    int i = ui->lineEditidemp->text().toInt();
   QString n = ui->lineEditnomemp->text();
   QString l= ui->lineEditprenomemp->text();

    QString t = ui->lineEditmailemp->text();
     int m = ui->lineEditidprofil11->text().toInt();


    cruds_employer c(i,n,l,t,m);
    bool test = c.ajouter();
    if (test)
    {
        player->setMedia(QUrl::fromLocalFile("D:/OneDrive/Bureau/administration/employer ajouter.mp3"));
                    player->play();
                    qDebug()<<player->errorString();
                    QThread::sleep(1);

        ui->tableView->setModel(tempemployer.afficher());
        QMessageBox::information(nullptr,"AJOUT EMPLOYER","EMPLOYER AJOUTEE");
    }
    else
    {
        QMessageBox::warning(nullptr,"AJOUT EMPLOYER","EMPLOYER NON AJOUTEE");
    }
}


void gestion_employer::on_pushButton_supprimer_clicked()
{
    int i = ui->lineEdit_supp->text().toInt();
    bool test = tempemployer.supprimer(i);
    if (test)
    {
        player->setMedia(QUrl::fromLocalFile("D:/OneDrive/Bureau/administration/employer supp.mp3"));
                    player->play();
                    qDebug()<<player->errorString();
                    QThread::sleep(1);

        ui->tableView->setModel(tempemployer.afficher());
        QMessageBox::information(nullptr,"SUPPRIMER EMPLOYER","EMPLOYER SUPPRIMER !");
    }
    else
    {

        QMessageBox::warning(nullptr,"SUPPRIMER EMPLOYER","EMPLOYER NON SUPPRIMER !");
    }
}
void gestion_employer::on_pushButton_modifier_clicked()
{
    int i = ui->lineEditidempM->text().toInt();
   QString n = ui->lineEditnomempM->text();
   QString l= ui->lineEditprenomempM->text();

    QString t = ui->lineEditmailempM->text();
    int m = ui->lineEditidprofil11->text().toInt();


    cruds_employer c(i,n,l,t,m);
    bool test = c.modifier();
         if (test)
         {
             player->setMedia(QUrl::fromLocalFile("D:/OneDrive/Bureau/administration/modifier.mp3"));
                         player->play();
                         qDebug()<<player->errorString();
                         QThread::sleep(1);
                     ui->tableView->setModel(tempemployer.afficher());

             ui->tableView->setModel(tempemployer.afficher());
             QMessageBox::information(nullptr,"MODIFER CLIENT","MODFIER AJOUTEE");
         }
         else
         {
             QMessageBox::warning(nullptr,"MODIFER CLIENT","CLIENT NON MODIFER");
         }
}
void gestion_employer::on_nom_clicked()
{
    ui->tableView->setModel(tempemployer.afficher());
           QString prenom = ui->lineEditnom123->text();
          ui->tableView->setModel(tempemployer.afficher_nom(prenom));
}

void gestion_employer::on_prenom_clicked()
{
    ui->tableView->setModel(tempemployer.afficher());
           QString nom = ui->lineEditprenom123->text();
          ui->tableView->setModel(tempemployer.afficher_prenom(nom));
}



void gestion_employer::on_id_clicked()
{
    ui->tableView->setModel(tempemployer.afficher());
           QString nom = ui->lineEditid123->text();
          ui->tableView->setModel(tempemployer.afficher_id(nom));
}


void gestion_employer::on_checkBoxnom_clicked()
{
    bool test = true;
          if (test)
              {
              ui->tableView->setModel(tempemployer.afficher());

                  ui->tableView->setModel(tempemployer.trier_nom());
              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier NOM"),
                                    QObject::tr("Erreur !.\n"));
          }
}


void gestion_employer::on_checkBoxid_clicked()
{
    bool test = true;
          if (test)
              {
              ui->tableView->setModel(tempemployer.afficher());

                  ui->tableView->setModel(tempemployer.trier_id());
              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier ID"),
                                    QObject::tr("Erreur !.\n"));
          }
}
void gestion_employer::on_checkBoxprenom_clicked()
{
    bool test = true;
          if (test)
              {
              ui->tableView->setModel(tempemployer.afficher());

                  ui->tableView->setModel(tempemployer.trier_prenom());
              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier PRENOM"),
                                    QObject::tr("Erreur !.\n"));
          }
}








void gestion_employer::on_pushButton_clicked()
{
    Dialog d;
    d.exec();
}
