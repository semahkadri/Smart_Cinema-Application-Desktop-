#ifndef CRUDS_SALLES_H
#define CRUDS_SALLES_H
#include <QVariant>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

class cruds_salles
{
    QString taille;
    QString mark;
    QString qualite;
    int id;
public:
    cruds_salles();
    cruds_salles(QString,QString,QString,int);
    QString get_taille(){return taille;}
     QString get_mark(){return mark;}
      QString get_qualite(){return qualite;}
       int get_id(){return id;}
       bool ajouter();
       bool supprimer(int);
       QSqlQueryModel *afficher();
        bool modifier();
        QSqlQueryModel *trier_id();
        QSqlQueryModel *afficher_taille(QString);

};

#endif // CRUDS_SALLES_H
