#include "cruds_profil.h"

cruds_profil::cruds_profil()
{

}
cruds_profil::cruds_profil(int i, QString t)
{
     idprofil=i;
    poste=t;


}
bool cruds_profil::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PROFIL (idprofil,poste) VALUES (:idprofil,:poste)");
    QString res= QString::number(idprofil);
    query.bindValue(":idprofil",idprofil);
    query.bindValue(":poste",poste);

    return query.exec();
}
bool cruds_profil::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM PROFIL where idprofil=:idprofil");
    QString res= QString::number(i);
    query.bindValue(":idprofil",res);
    return query.exec();
}
QSqlQueryModel * cruds_profil::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from PROFIL ");
    model->setHeaderData(0,Qt::Horizontal,"IDPROFIL");
    model->setHeaderData(1,Qt::Horizontal,"POSTE");

    return model ;
}
bool cruds_profil::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE PROFIL SET poste=:poste WHERE idprofil=:idprofil");
    QString res= QString::number(idprofil);
    query.bindValue(":idprofil",idprofil);
    query.bindValue(":poste",poste);

    return query.exec();
}
