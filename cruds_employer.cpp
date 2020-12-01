#include "cruds_employer.h"

cruds_employer::cruds_employer()
{

}
cruds_employer::cruds_employer(int i,QString n,QString l,QString t,int m)
{
    idemp=i;
    nomemp=n;
    prenomemp=l;
    mailemp=t;
    idprofil=m ;
}
bool cruds_employer::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO GEREEMPLOYER (idemp,nomemp,prenomemp,mailemp,idprofil) VALUES (:idemp,:nomemp,:prenomemp,:mailemp,:idprofil)");
    QString res= QString::number(idemp);
    query.bindValue(":idemp",res);
    query.bindValue(":nomemp",nomemp);
    query.bindValue(":prenomemp",prenomemp);
    query.bindValue(":mailemp",mailemp);
    QString tes= QString::number(idprofil);
    query.bindValue(":idprofil",tes);

    return query.exec();
}

 bool cruds_employer::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM GEREEMPLOYER where idemp=:idemp");
    QString res= QString::number(i);
    query.bindValue(":idemp",res);
    return query.exec();
}
QSqlQueryModel * cruds_employer::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from GEREEMPLOYER ");
    model->setHeaderData(0,Qt::Horizontal,"IDEMP");
    model->setHeaderData(1,Qt::Horizontal,"NOMEMP");
    model->setHeaderData(2,Qt::Horizontal,"PRENOMEMP");
    model->setHeaderData(3,Qt::Horizontal,"MAILEMP");
     model->setHeaderData(4,Qt::Horizontal,"IDPROFIL");

    return model ;
}
bool cruds_employer::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE GEREEMPLOYER SET idemp=:idemp,nomemp=:nomemp,prenomemp=:prenomemp,mailemp=:mailemp WHERE idemp=:idemp");
    QString res= QString::number(idemp);
    query.bindValue(":idemp",idemp);
    query.bindValue(":nomemp",nomemp);
    query.bindValue(":prenomemp",prenomemp);
    query.bindValue(":mailemp",mailemp);

    return query.exec();
}
QSqlQueryModel * cruds_employer::afficher_nom(QString nomemp)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from GEREEMPLOYER WHERE nomemp = '"+nomemp+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"nom");
    model->setHeaderData(2,Qt::Horizontal,"prenom");
    model->setHeaderData(3,Qt::Horizontal,"description");
    model->setHeaderData(4,Qt::Horizontal,"mail");
    return model ;
}
QSqlQueryModel * cruds_employer::afficher_prenom(QString prenomemp)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from GEREEMPLOYER WHERE prenomemp = '"+prenomemp+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"nom");
    model->setHeaderData(2,Qt::Horizontal,"prenom");
    model->setHeaderData(3,Qt::Horizontal,"description");
    model->setHeaderData(4,Qt::Horizontal,"mail");
    return model ;
}
QSqlQueryModel * cruds_employer::afficher_id(QString nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from GEREEMPLOYER WHERE idemp = '"+nom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"nom");
    model->setHeaderData(2,Qt::Horizontal,"prenom");
    model->setHeaderData(3,Qt::Horizontal,"description");
    model->setHeaderData(4,Qt::Horizontal,"mail");
    return model ;
}
QSqlQueryModel * cruds_employer::trier_id()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from GEREEMPLOYER ORDER BY idemp");
        model->setHeaderData(0,Qt::Horizontal,"NOM");
        model->setHeaderData(1,Qt::Horizontal,"DUREE");
        model->setHeaderData(2,Qt::Horizontal,"LANGUAGE");
        model->setHeaderData(3,Qt::Horizontal,"TYPE");
        model->setHeaderData(4,Qt::Horizontal,"ID");
        return model ;
}
QSqlQueryModel * cruds_employer::trier_nom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from GEREEMPLOYER ORDER BY nomemp");
        model->setHeaderData(0,Qt::Horizontal,"NOM");
        model->setHeaderData(1,Qt::Horizontal,"DUREE");
        model->setHeaderData(2,Qt::Horizontal,"LANGUAGE");
        model->setHeaderData(3,Qt::Horizontal,"TYPE");
        model->setHeaderData(4,Qt::Horizontal,"ID");
        return model ;
}
QSqlQueryModel * cruds_employer::trier_prenom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from GEREEMPLOYER ORDER BY prenomemp");
        model->setHeaderData(0,Qt::Horizontal,"NOM");
        model->setHeaderData(1,Qt::Horizontal,"DUREE");
        model->setHeaderData(2,Qt::Horizontal,"LANGUAGE");
        model->setHeaderData(3,Qt::Horizontal,"TYPE");
        model->setHeaderData(4,Qt::Horizontal,"ID");
        return model ;
}
