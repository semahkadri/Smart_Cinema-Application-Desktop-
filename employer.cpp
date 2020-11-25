#include "employer.h"

employer:: employer()
{

}


employer::employer(int i,QString n,QString p,QString k)
{
    idemp = i;
    nomemp = n;
    prenomemp = p;
    mailemp = k;
}


bool employer::ajouter()
{

  QSqlQuery query;
  query.prepare("INSERT INTO GEREEMPLOYER(id,nomemp,prenomemp,mailemp) VALUES (:idemp,:nomemp,:prenomemp,:mailemp)");
  QString res= QString::number(idemp);
  query.bindValue(":idemp",res);
  query.bindValue(":nomemp",nomemp);
  query.bindValue(":prenomemp",prenomemp);
  query.bindValue(":mailemp",mailemp);
  return query.exec();
}
