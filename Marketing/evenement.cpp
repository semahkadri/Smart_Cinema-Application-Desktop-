#include "evenement.h"
#include "connection.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>
evenement::evenement()
{
    id_event=0;
    id_salle=0;
    nom_event="";
    type_event="";
}


evenement::evenement(int id_event,QString nom_event,QString type_event,int id_salle,QDateTime time)
{
    this->id_event=id_event;
    this->nom_event=nom_event;
    this->type_event=type_event;
    this->id_salle=id_salle;
    this->time=time;
}

bool evenement::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id_event);
    QString ress=QString::number(id_salle);
    query.prepare("INSERT INTO evenement(id_event,nom_event,type_event,id_salle,time)""VALUES(:id_event,:nom_event,:type_event,:id_salle,:time)");
    query.bindValue(":id_event",res);
    query.bindValue(":nom_event",nom_event);
    query.bindValue(":type_event",type_event);
    query.bindValue(":id_salle",ress);
    query.bindValue(":time",time);
    return query.exec();
}

bool evenement::supprimer(int i)
{
    QSqlQuery query;
    QString res=QString::number(i);
    query.prepare("DELETE FROM evenement where id_event=:id_event");
    query.bindValue(":id_event",res);
    return query.exec();
}

QSqlQueryModel *evenement::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from evenement ");
    model->setHeaderData(0,Qt::Horizontal,"id_event");
    model->setHeaderData(1,Qt::Horizontal,"nom_event");
    model->setHeaderData(2,Qt::Horizontal,"type_event");
    model->setHeaderData(3,Qt::Horizontal,"id_salle");
    model->setHeaderData(4,Qt::Horizontal,"time");
    return model ;
}

bool evenement::modifier(int id_event,QString nom_event,QString type_event,int id_salle,QDateTime time)
{
    QSqlQuery query;
    query.prepare("UPDATE evenement SET id_event=:id_event,nom_event=:nom_event,type_event=:type_event,id_salle=:id_salle,time=:time WHERE id_event=:id_event");
    QString res= QString::number(id_event);
    QString ress=QString::number(id_salle);
    query.bindValue(":id_event",res);
    query.bindValue(":id_salle",ress);
    query.bindValue(":nom_event",nom_event);
    query.bindValue(":type_event",type_event);
    query.bindValue(":time",time);
    return query.exec();
}

QSqlQueryModel * evenement::trier_id_event()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * from evenement ORDER BY id_event");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_event "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_event"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_event"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_salle"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("time"));
    return model;
}

QSqlQueryModel * evenement::trier_time()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * from evenement ORDER BY time");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_event "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_event"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_event"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_salle"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("time"));
    return model;
}

