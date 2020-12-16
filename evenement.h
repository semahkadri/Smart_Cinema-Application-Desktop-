#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<qdatetimeedit.h>
#include<qdatetime.h>
#include <QVariant>
#include <QComboBox>

class evenement
{
public: 
    evenement();
    evenement(int,QString,QString,int,QDateTime);
    int get_id_event(){return id_event;}
    QString get_nom_event(){return nom_event;}
    QString get_type_event(){return type_event;}
    int get_id_salle(){return id_salle;}
    QString get_time();

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel *afficher();
    bool modifier(int,QString,QString,int,QDateTime);
    QSqlQueryModel *trier_id_event();
    QSqlQueryModel *trier_time();

private:
    int id_event;
    QString nom_event;
    QString type_event;
    int id_salle;
    QDateTime time;
};

#endif // EVENEMENT_H
