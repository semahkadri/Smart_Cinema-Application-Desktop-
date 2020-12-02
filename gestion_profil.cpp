 #include "gestion_profil.h"
#include "ui_gestion_profil.h"
#include <QString>
#include "cruds_profil.h"
#include <QMessageBox>
#include <QThread>
#include <QSound>
#include <QDebug>
gestion_profil::gestion_profil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_profil)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempsalles.afficher());
    player= new QMediaPlayer(this);
}

gestion_profil::~gestion_profil()
{
    delete ui;
}


void gestion_profil::on_ajouter_clicked()
{
    int i = ui->lineEditidprofil->text().toInt();
    QString t = ui->lineEditposteprofil->text();



     cruds_profil c(i,t);
     bool test = c.ajouter();
     if (test)
     {

         ui->tableView->setModel(tempsalles.afficher());
         QMessageBox::information(nullptr,"AJOUT PROFIL","PROFIL AJOUTEE");
     }
     else
     {
         QMessageBox::warning(nullptr,"AJOUT PROFIL","PROFIL NON AJOUTEE");
     }
}

void gestion_profil::on_pushButton_supprimer_clicked()
{
    int i = ui->lineEdit_supp_profil->text().toInt();
    bool test = tempsalles.supprimer(i);
    if (test)
    {

        ui->tableView->setModel(tempsalles.afficher());
        QMessageBox::information(nullptr,"SUPPRIMER PROFIL","PROFIL SUPPRIMER !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER PROFIL","PROFIL NON SUPPRIMER !");
    }
}

void gestion_profil::on_pushButton_modifier_clicked()
{
    int i = ui->lineEditidprofil1->text().toInt();

    QString t = ui->lineEditposteprofil1->text();


     cruds_profil c(i,t);
     bool test = c.modifier();
     if (test)
     {

         ui->tableView->setModel(tempsalles.afficher());
         QMessageBox::information(nullptr,"MODIFIER PROFIL","PROFIL MODIFIER");
     }
     else
     {
         QMessageBox::warning(nullptr,"MODIFIER PROFIL","PROFIL NON MODIFIER");
     }
}



