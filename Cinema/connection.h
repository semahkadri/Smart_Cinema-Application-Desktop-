#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
private:
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    bool ouvrirconnexion();
    void fermerconnexion();
    QSqlDatabase get_db();
};

#endif // CONNECTION_H
