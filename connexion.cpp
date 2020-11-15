#include "connexion.h"

connexion::connexion()
{

}
bool connexion::create_cnx()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("2A8");
    db.setUserName("ilyes");
    db.setPassword("ilyes");
    if(db.open())
    test=true;
    return test;
}
