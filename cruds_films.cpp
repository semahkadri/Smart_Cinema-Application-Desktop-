#include "cruds_films.h"

cruds_films::cruds_films()
{

}
cruds_films::cruds_films(QString n,QString l,int d,int i,QString t)
{
    nom=n;
    language=l;
    duree=d;
    id=i;
    type=t;
}
bool cruds_films::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO GESTION (nom,duree,language,type,id) VALUES (:nom,:duree,:language,:type,:id)");
    QString res= QString::number(id);
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":language",language);
    query.bindValue(":duree",duree);
    query.bindValue(":type",type);
    return query.exec();
}
bool cruds_films::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM GESTION where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}
QSqlQueryModel * cruds_films::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from GESTION ");
    model->setHeaderData(0,Qt::Horizontal,"NOM");
    model->setHeaderData(1,Qt::Horizontal,"DUREE");
    model->setHeaderData(2,Qt::Horizontal,"LANGUAGE");
    model->setHeaderData(3,Qt::Horizontal,"TYPE");
    model->setHeaderData(4,Qt::Horizontal,"ID");
    return model ;
}


QSqlQueryModel * cruds_films::afficher_nom(QString nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from GESTION WHERE id = '"+nom+"'");
    model->setHeaderData(0,Qt::Horizontal,"NOM");
    model->setHeaderData(1,Qt::Horizontal,"DUREE");
    model->setHeaderData(2,Qt::Horizontal,"LANGUAGE");
    model->setHeaderData(3,Qt::Horizontal,"TYPE");
    model->setHeaderData(4,Qt::Horizontal,"ID");
    return model ;
}
//

bool cruds_films::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE GESTION SET nom=:nom,duree=:duree,language=:language,type=:type WHERE id=:id");
    QString res= QString::number(id);
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":language",language);
    query.bindValue(":duree",duree);
    query.bindValue(":type",type);
    return query.exec();
}
QSqlQueryModel * cruds_films::trier_id()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from GESTION ORDER BY id");
        model->setHeaderData(0,Qt::Horizontal,"NOM");
        model->setHeaderData(1,Qt::Horizontal,"DUREE");
        model->setHeaderData(2,Qt::Horizontal,"LANGUAGE");
        model->setHeaderData(3,Qt::Horizontal,"TYPE");
        model->setHeaderData(4,Qt::Horizontal,"ID");
        return model ;
}
QSqlQueryModel * cruds_films::trier_nom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from GESTION ORDER BY nom");
        model->setHeaderData(0,Qt::Horizontal,"NOM");
        model->setHeaderData(1,Qt::Horizontal,"DUREE");
        model->setHeaderData(2,Qt::Horizontal,"LANGUAGE");
        model->setHeaderData(3,Qt::Horizontal,"TYPE");
        model->setHeaderData(4,Qt::Horizontal,"ID");
        return model ;
}
QSqlQueryModel * cruds_films::trier_duree()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from GESTION ORDER BY duree");
        model->setHeaderData(0,Qt::Horizontal,"NOM");
        model->setHeaderData(1,Qt::Horizontal,"DUREE");
        model->setHeaderData(2,Qt::Horizontal,"LANGUAGE");
        model->setHeaderData(3,Qt::Horizontal,"TYPE");
        model->setHeaderData(4,Qt::Horizontal,"ID");
        return model ;
}



