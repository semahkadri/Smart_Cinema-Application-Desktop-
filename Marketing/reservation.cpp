#include "reservation.h"
#include "connection.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>
reservation::reservation()
{
    id_reservation=0;
    id_film=0;
    id_event2=0;
    QString nombre_place="";
}

reservation::reservation(int id_reservation,int id_film,int id_event2,QString nombre_place,QDateTime date_reservation)
{
    this->id_reservation=id_reservation;
    this->id_film=id_film;
    this->id_event2=id_event2;
    this->nombre_place=nombre_place;
    this->date_reservation=date_reservation;

}

bool reservation::ajouter2()
{
    QSqlQuery query;
    QString res=QString::number(id_reservation);
    QString ress=QString::number(id_film);
    QString resss=QString::number(id_event2);
    query.prepare("INSERT INTO reservation(id_reservation,id_film,id_event2,nombre_place,date_reservation)""VALUES(:id_reservation,:id_film,:id_event2,:nombre_place,:date_reservation)");
    query.bindValue(":id_reservation",res);
    query.bindValue(":id_film",ress);
    query.bindValue(":id_event2",resss);
    query.bindValue(":nombre_place",nombre_place);
    query.bindValue(":date_reservation",date_reservation);
    return query.exec();
}

bool reservation::supprimer2(int i)
{
    QSqlQuery query;
    QString res=QString::number(i);
    query.prepare("DELETE FROM reservation where id_reservation=:id_reservation");
    query.bindValue(":id_reservation",res);
    return query.exec();
}

QSqlQueryModel *reservation::afficher2()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from reservation ");
    model->setHeaderData(0,Qt::Horizontal,"id_reservation");
    model->setHeaderData(1,Qt::Horizontal,"id_film");
    model->setHeaderData(2,Qt::Horizontal,"id_event2");
    model->setHeaderData(3,Qt::Horizontal,"nombre_place");
    model->setHeaderData(4,Qt::Horizontal,"date_reservation");
    return model ;
}

bool reservation::modifier2(int id_reservation,int id_film,int id_event2,QString nombre_place,QDateTime date_reservation)
{
    QSqlQuery query;
    query.prepare("UPDATE reservation SET id_reservation=:id_reservation,id_film=:id_film,id_event2=:id_event2,nombre_place=:nombre_place,date_reservation=:date_reservation WHERE id_reservation=:id_reservation");
    QString res= QString::number(id_reservation);
    QString ress=QString::number(id_film);
    QString resss=QString::number(id_event2);
    query.bindValue(":id_reservation",res);
    query.bindValue(":id_film",ress);
    query.bindValue(":id_event2",resss);
    query.bindValue(":nombre_place",nombre_place);
    query.bindValue(":date_reservation",date_reservation);
    return query.exec();
}

QSqlQueryModel *  reservation::chercher(int id_reservation)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(id_reservation);
    model->setQuery("SELECT * FROM reservation WHERE (id_reservation LIKE '"+res+"%' ) ");
    return  model;


}
