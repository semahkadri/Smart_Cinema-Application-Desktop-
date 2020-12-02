#include "database.h"

Database::Database(QObject *parent) : QObject(parent)
{

}
bool Database::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("anotheronepls");
db.setUserName("anotherone");
db.setPassword("esprit18");

if (db.open()){
test=true; qDebug() << "database opened";}
 return  test;
}
void Database::closeconnection(){
    db.close();
    qDebug() << "database closed";
    db.removeDatabase(QSqlDatabase::defaultConnection);
}
bool Database::loginconnection(QString username, QString password){
    bool connected = false;
    QSqlQuery query(QSqlDatabase::database("lasttime"));
    query.prepare(QString("SELECT * FROM ACCOUNTS WHERE USERNAME =:username AND PASSWORD =:password"));
    query.bindValue(":username",username);
    query.bindValue(":password",password);
    if(!query.exec()){qDebug() <<"failed exec";}
    else{
        while(query.next()){
            QString usernameFromDB=query.value(1).toString();
            QString passwordFromDB=query.value(2).toString();
            if ((usernameFromDB == username )&& (passwordFromDB == password))connected = true;
            }
    }
    return connected;
}
void Database::showtable(int idx){
    int num_rows=0,r=0,c=0;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM PRODUCTS WHERE PVENTE =:IDX");
    q.bindValue(":IDX",idx);
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    table->setRowCount(num_rows);
    q.prepare("SELECT * FROM PRODUCTS WHERE PVENTE =:IDX");
    q.bindValue(":IDX",idx);
    if(!q.exec()) qDebug() <<q.lastError().text();
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<6;++c){
            table->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
}
void Database::showparkingtable(){
    int num_rows=0,r=0,c=0;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM PARKING");
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    ptable->setRowCount(num_rows);
    q.prepare("SELECT * FROM PARKING");
    if(!q.exec()) qDebug() <<q.lastError().text();
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<5;++c){
            ptable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
}
void Database::addparking(QString spot, QString owner, QString license){
    QSqlQuery query,q2;
    int tempid=1,test;
    q2.prepare("SELECT * FROM PARKING ORDER BY ID");
    q2.exec();
    while(q2.next()){
        tempid++; qDebug() <<"test";
        test = q2.value(0).toInt();
        if(tempid==test) {tempid++; qDebug() <<"here";}
    }
    QString state;
    if(!((license.isEmpty()||license =="-")&&(owner.isEmpty()||owner =="-"))) {state ="TAKEN";}
    if((license.isEmpty()||license =="-")&&(owner.isEmpty()||owner =="-")) {
        license = "FREE";
        state = "FREE";
        owner = "-";}


    query.prepare("INSERT INTO PARKING (ID, SPOT, STATE, CO, LICENSE) VALUES (:ID, :spot, :state, :owner, :license)");
    query.bindValue(":ID",tempid);
    query.bindValue(":spot",spot);
    query.bindValue(":state",state);
    query.bindValue(":owner",owner);
    query.bindValue(":license",license);
    if(query.exec()) qDebug() <<"added parking";
}
void Database::showpvtable(){
    int num_rows=0,r=0,c=0;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    if(!q.exec("SELECT count(PVID) AS num_rows FROM PVENTES")) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    pvtable->setRowCount(num_rows);
    pvtable->setSortingEnabled(false);
    if(!q.exec("SELECT * FROM PVENTES")) qDebug() <<q.lastError().text();
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<2;c++){
            pvtable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
}

void Database::fillcombobox(){
    int i=0;
    selectpv->addItem("Point Vente");
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    if(!q.exec("SELECT * FROM PVENTES ORDER BY PVID")) qDebug() << q.lastError().text();
    for(i=0,q.first();q.isValid();q.next(),i++){
        selectpv->addItem(q.value(1).toString());
    }
}

void Database::addpvente(QString proom){
    QSqlQuery query,q2;
    int tempid=1,test;
    q2.prepare("SELECT * FROM PVENTES ORDER BY PVID");
    q2.exec();
    while(q2.next()){
        tempid++; qDebug() <<"test";
        test = q2.value(0).toInt();
        if(tempid==test) {tempid++; qDebug() <<"here";}
    }
    query.prepare("INSERT INTO PVENTES (PVID, ROOM) VALUES (:ID, :proom)");
    query.bindValue(":ID",tempid);
    query.bindValue(":proom",proom);
    if(query.exec()) qDebug() <<"added pvente";

}
bool Database::modifypv(int id,QString proom){
    QSqlQuery q; int total=0;

    q.prepare("SELECT * FROM PVENTES WHERE PVID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("UPDATE PVENTES SET ROOM=:proom WHERE PVID=:ID");
        query.bindValue(":ID",id);
        query.bindValue(":proom",proom);
        query.exec();
        q.first();
        return true;}
    else return false;
}
bool Database::parkingmodified(int id,QString spot, QString co, QString license){
    QSqlQuery q; int total=0;
    QString state;
    if(!((license.isEmpty()||license =="-")&&(co.isEmpty()||co =="-"))) state ="TAKEN";
    if((license.isEmpty()||license =="-")&&(co.isEmpty()||co =="-")) {
        license = "FREE";
        state = "FREE";
        co = "-";}
    q.prepare("SELECT * FROM PARKING WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("UPDATE PARKING SET SPOT=:spot, STATE=:state, CO=:co, LICENSE=:license WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.bindValue(":spot",spot);
        query.bindValue(":state",state);
        query.bindValue(":co",co);
        query.bindValue(":license",license);
        query.exec();
        q.first();

        return true;
    }
    else return false;
}
void Database::addproduct(QString pname,QString ptype,QString pdate,QString pquantity,int idx){
    QString res = QString::number(idx);
    QSqlQuery query,q2;
    int tempid=1,test;
    q2.prepare("SELECT * FROM PRODUCTS ORDER BY ID");
    q2.exec();
    while(q2.next()){
        tempid++; qDebug() <<"test";
        test = q2.value(0).toInt();
        if(tempid==test) {tempid++; qDebug() <<"here";}
    }
    if(!query.exec("SELECT count(ID) AS num_rows FROM PRODUCTS")) qDebug() << query.lastError().text();
    else{
    query.first();
    query.prepare("INSERT INTO PRODUCTS (ID, PNAME, PTYPE, PDATE, PQUANTITY, PVENTE) VALUES (:ID, :pname, :ptype, :pdate, :pquantity, :IDX)");
    query.bindValue(":ID",tempid);
    query.bindValue(":IDX",res);
    query.bindValue(":pname",pname);
    query.bindValue(":ptype",ptype);
    query.bindValue(":pdate",pdate);
    query.bindValue(":pquantity",pquantity);
    if(query.exec()) qDebug() <<"added product";}
}

void Database::changetable(){
    if (loading){loading = false; return;}
}
bool Database::updatetable(int id,int idx, QString pname, QString ptype, QString pdate ,QString pquantity){
    QSqlQuery q; int total=0;

    q.prepare("SELECT * FROM PRODUCTS WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("UPDATE PRODUCTS SET PNAME=:pname, PTYPE=:ptype, PQUANTITY=:pquantity, PVENTE=:IDX, PDATE=:pdate WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.bindValue(":pname",pname);
        query.bindValue(":ptype",ptype);
        query.bindValue(":pquantity",pquantity);
        query.bindValue(":IDX",idx);
        query.bindValue(":pdate",pdate);
        query.exec();
        q.first();
        return true;}
    else return false;
}
bool Database::deletepv(int id){
    QSqlQuery q; int total=0;
    q.prepare("SELECT * FROM PVENTES WHERE PVID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("DELETE FROM PVENTES WHERE PVID=:ID");
        query.bindValue(":ID",id);
        query.exec();
        q.first();

        return true;
    }
    else return false;
}
bool Database::deleteparking(int id){
    QSqlQuery q;int total=0;
    q.prepare("SELECT * FROM PARKING WHERE ID=:id");
    q.bindValue(":id",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("DELETE FROM PARKING WHERE ID=:id");
        query.bindValue(":id",id);
        return query.exec();
    }
    else return false;
}
bool Database::deletetable(int id, int idx){
    QSqlQuery q;int total=0;
    q.prepare("SELECT * FROM PRODUCTS WHERE ID=:id AND PVENTE=:idx");
    q.bindValue(":id",id);
    q.bindValue(":idx",idx);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("DELETE FROM PRODUCTS WHERE ID=:id");
        query.bindValue(":id",id);
        return query.exec();
    }
    else return false;
}
Database::~Database(){

}
