#ifndef CRUDS_EMPLOYER_H
#define CRUDS_EMPLOYER_H
#include <QVariant>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
class cruds_employer
{
    int idemp;
    QString nomemp;
    QString prenomemp;
    QString mailemp;
    int idprofil;
public:
    cruds_employer();
    cruds_employer(int,QString,QString,QString,int);
    int get_idemp(){return idemp;}
     QString get_nomemp(){return nomemp;}
       QString get_prenomemp(){return prenomemp;}
       QString get_mailemp(){return mailemp;}
      int get_idprofil(){return idprofil;}

       bool ajouter();
       bool supprimer(int);
       QSqlQueryModel *afficher();
       bool modifier();
       QSqlQueryModel  *afficher_nom(QString);
               QSqlQueryModel  *afficher_prenom(QString);
               QSqlQueryModel  *afficher_id(QString);
               QSqlQueryModel *trier_nom();
                      QSqlQueryModel *trier_prenom();
                      QSqlQueryModel *trier_id();


};

#endif // CRUDS_EMPLOYER_H
