#include "gestion_salles.h"
#include "ui_gestion_salles.h"
#include <QString>
#include "cruds_salles.h"
#include <QMessageBox>
gestion_salles::gestion_salles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_salles)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempsalles.afficher());
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
         ui->tableView->setModel(tempsalles.afficher());
         QMessageBox::information(nullptr,"AJOUT FILM","FILM AJOUTEE");
     }
     else
     {
         QMessageBox::warning(nullptr,"AJOUT FILM","FILM NON AJOUTEE");
     }
}

void gestion_salles::on_pushButton_supprimer_chaise_clicked()
{
    int i = ui->lineEdit_supp_chaise->text().toInt();
    bool test = tempsalles.supprimer(i);
    if (test)
    {
        ui->tableView->setModel(tempsalles.afficher());
        QMessageBox::information(nullptr,"SUPPRIMER FILM","FILM SUPPRIMER !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER FILM","FILM NON SUPPRIMER !");
    }
}
