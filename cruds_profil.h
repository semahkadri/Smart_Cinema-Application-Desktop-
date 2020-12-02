#ifndef CRUDS_PROFIL_H
#define CRUDS_PROFIL_H
#include <QVariant>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

class cruds_profil
{
    int idprofil;
    QString poste;

public:
    cruds_profil();
    cruds_profil(int,QString);
    int get_idprofil(){return idprofil;}
    QString get_poste(){return poste;}


       bool ajouter();
       bool supprimer(int);
       QSqlQueryModel *afficher();
        bool modifier();

};

#endif // CRUDS_PROFIL_H
