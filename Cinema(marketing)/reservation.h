#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<qdatetimeedit.h>
#include<qdatetime.h>
#include <QVariant>
#include <QComboBox>
class reservation
{
        public:
    reservation();
    reservation(int,int,int,QString,QDateTime);
    int get_id_reservation(){return id_reservation;}
    int get_id_film(){return id_film;}
    int get_id_event2(){return id_event2;}
    QString get_nombre_place(){return nombre_place;}
    QString get_date_reservation();

    bool ajouter2();
    bool supprimer2(int);
    QSqlQueryModel *afficher2();
    bool modifier2(int,int,int,QString,QDateTime);
    QSqlQueryModel * chercher(int);
    QSqlQueryModel *stat();

        private:
    int id_reservation;
    int id_film;
    int id_event2;
    QString nombre_place;
    QDateTime date_reservation;


};

#endif // RESERVATION_H
