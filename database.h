#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QHeaderView>
#include <QMainWindow>
#include <QTableWidget>
#include <QPropertyAnimation>
#include <QStackedWidget>
#include <QGraphicsEffect>
#include "qtmaterialraisedbutton.h"
#include "qtmaterialtextfield.h"
#include "qtmaterialsnackbar.h"
#include "qtmaterialradiobutton.h"
#include <QLabel>
#include <qradiobutton.h>
class Database : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase db;
    bool loading;
public :
    void showparkingtable();
    void addparking(QString,QString,QString);
    bool deleteparking(int);
    bool parkingmodified(int,QString,QString,QString);
    bool createconnect();
    void fillcombobox();
    void closeconnection();
    bool loginconnection(QString,QString);
    void showtable(int);
    void showpvtable();
    void addpvente(QString);
    void changetable();
    bool modifypv(int,QString);
    bool deletepv(int);
    bool updatetable(int, int , QString, QString, QString, QString);
    bool deletetable(int,int);
    void addproduct(QString, QString, QString, QString, int );
public:
    QTableWidget *table,*ptable,*pvtable;
    QComboBox *selectpv;
    ~Database();
    explicit Database(QObject *parent = nullptr);

signals:

};

#endif // DATABASE_H
