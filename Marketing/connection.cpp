#include "connection.h"
#include <QSqlError>
Connection::Connection(){
}
bool Connection::ouvrirconnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("semah");//inserer nom de l'utilisateur
    db.setPassword("esprit");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;

    else throw QString ("Erreur Paramétres"+db.lastError().text());
    return  test;
}
void Connection::fermerconnexion()
{QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.close();}
QSqlDatabase Connection::get_db()
{
    return db;
}
