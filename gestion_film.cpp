#include "gestion_film.h"
#include "ui_gestion_film.h"
#include <QString>
#include "cruds_films.h"
#include <QMessageBox>
gestion_film::gestion_film(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_film)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempfilm.afficher());
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
        ui->tableView->setModel(tempfilm.afficher());
        QMessageBox::information(nullptr,"SUPPRIMER FILM","FILM SUPPRIMER !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER FILM","FILM NON SUPPRIMER !");
    }
}
//
void gestion_film::on_pushButton_modifier_clicked()
{
    QString nom1 = ui->lineEdit_nouveau_nom->text();
    QString language1= ui->lineEdit_nouveau_language->text();
     int i = ui->lineEdit_id->text().toInt();
     QString type1 = ui->lineEdit_nouveau_type->text();
      int duree1 = ui->lineEdit_nouveau_duree->text().toInt();

     cruds_films c(nom1,language1,duree1,i,type1);
     bool test = c.modifier(nom1,language1,duree1,i,type1);
     if (test)
     {
         ui->tableView->setModel(tempfilm.afficher());
         QMessageBox::information(nullptr,"MODIFIER FILM","FILM MODIFIER");
     }
     else
     {
         QMessageBox::warning(nullptr,"MODIFIER FILM","FILM NON MODIFIER");
     }
}
