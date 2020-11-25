#include "connexion.h"
//test..


connexion::connexion()
{

}

bool connexion::creat_cnx(){


    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet2A");
    db.setUserName("safia");
    db.setPassword("safia");

    if(db.open())
        test=true;


    return test;



}
