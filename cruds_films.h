#ifndef CRUDS_FILMS_H
#define CRUDS_FILMS_H
#include <QVariant>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
class cruds_films
{
    QString nom;
    QString language;
    int duree;
    int id;
    QString type;
public:
    cruds_films();
    cruds_films(QString,QString,int,int,QString);
    QString get_nom(){return nom;}
     QString get_language(){return language;}
      int get_duree(){return duree;}
       QString get_type(){return type;}
       int get_id(){return id;}
       bool ajouter();
       bool supprimer(int);
       QSqlQueryModel *afficher();
       QSqlQueryModel *afficher_nom(QString);
       QSqlQueryModel *trier_nom();
       QSqlQueryModel *trier_duree();
       QSqlQueryModel *trier_id();



       bool modifier();

};

#endif // CRUDS_FILMS_H
