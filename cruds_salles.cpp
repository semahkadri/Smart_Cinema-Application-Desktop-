#include "cruds_salles.h"

cruds_salles::cruds_salles()
{

}
cruds_salles::cruds_salles(QString t,QString m,QString q,int i)
{
    taille=t;
    mark=m;
    qualite=q;
    id=i;
}
bool cruds_salles::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO GESTIONN (taille,mark,qualite,id) VALUES (:taille,:mark,:qualite,:id)");
    QString res= QString::number(id);
    query.bindValue(":id",id);
    query.bindValue(":taille",taille);
    query.bindValue(":mark",mark);
    query.bindValue(":qualite",qualite);
    return query.exec();
}
bool cruds_salles::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM GESTIONN where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}
QSqlQueryModel * cruds_salles::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from GESTIONN ");
    model->setHeaderData(0,Qt::Horizontal,"TAILLE");
    model->setHeaderData(1,Qt::Horizontal,"MARK");
    model->setHeaderData(2,Qt::Horizontal,"QUALITE");
    model->setHeaderData(3,Qt::Horizontal,"ID");
    return model ;
}
//
QSqlQueryModel * cruds_salles::afficher_taille(QString taille)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from GESTIONN WHERE id = '"+taille+"'");
    model->setHeaderData(0,Qt::Horizontal,"NOM");
    model->setHeaderData(1,Qt::Horizontal,"DUREE");
    model->setHeaderData(2,Qt::Horizontal,"LANGUAGE");
    model->setHeaderData(3,Qt::Horizontal,"TYPE");
    model->setHeaderData(4,Qt::Horizontal,"ID");
    return model ;
}

//
bool cruds_salles::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE GESTIONN SET taille=:taille,mark=:mark,qualite=:qualite WHERE id=:id");
    QString res= QString::number(id);
    query.bindValue(":id",id);
    query.bindValue(":taille",taille);
    query.bindValue(":mark",mark);
    query.bindValue(":qualite",qualite);
    return query.exec();
}
QSqlQueryModel * cruds_salles::trier_id()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from GESTIONN ORDER BY id");
        model->setHeaderData(0,Qt::Horizontal,"TAILLE");
        model->setHeaderData(1,Qt::Horizontal,"MARK");
        model->setHeaderData(2,Qt::Horizontal,"QUALITE");
        model->setHeaderData(3,Qt::Horizontal,"ID");
        return model ;
}
