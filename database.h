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
    bool addreservation(int,int,QString,QString);
    void addevent(int,QString,QString,QDateTime);
    bool deleteparking(int);
    bool parkingmodified(int,QString,QString,QString);
    bool createconnect();
    void fillcombobox();
    void closeconnection();
    bool loginconnection(QString,QString);
    void showtable(int);
    void showeventtable();
    void showmovietable();
    void showsubtable();
    void addmovie(QString , QString , QString , QString );
    bool modifymovie(int ,QString ,QString ,QString , QString );
    bool deletemov(int);
    bool searchmov(int);
    void showpvtable();
    void showrestable();
    void addpvente(QString);
    bool searchres(int);
    bool searchevent(int);
    void changetable();
    bool modifypv(int,QString);
    bool modifyres(int,int,int,QString,QString);
    bool modifyevent(int,int,QString,QString,QDateTime);
    bool deletepv(int);
    bool deleteres(int);
    bool deleteevent(int);
    bool updatetable(int, int , QString, QString, QString, QString);
    bool deletetable(int,int);
    void addproduct(QString, QString, QString, QString, int );
    bool modifyroom(int ,QString , QString , QString );
    void showroomtable();
    bool deleteroom(int);
    bool searchroom(int);
    void addroom(QString , QString , QString );
    void addsubscriber(QString , QString , QString );
    bool modifysub(int , QString , QString , QString );
    bool deletesub(int);
    bool searchsub(int);
    void showabonnementtable();
    void addabonnement(QString , QString , int );
    bool modifyabonnement(int , QString , QString , int );
    bool deleteabonnement(int);
    bool searchabonnement(int);
    void showemployeetable();
    void addemployee(QString name, QString fname, QString email, QString username, QString password);
    bool modifyemployee(int id,QString name, QString fname, QString email, QString username, QString password);
    bool deleteemployee(int id);
    bool searchemployee(int id);
    void showprofiltable();
    void addprofil(QString profil,QString post);
    bool modifyprofil(int id, QString profil, QString post);
    bool deleteprofil(int id);
    bool searchprofil(int id);
public:
    QTableWidget *table,*ptable,*pvtable,*restable,*evtable,*movtable,*roomtable,*subtable,*abonnementtable,*employeetable,*profiltable;
    QComboBox *selectpv;
    bool superuser=false;
    ~Database();
    explicit Database(QObject *parent = nullptr);

signals:

};

#endif // DATABASE_H
