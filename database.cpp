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
    bool connected = false; int super=1;
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
            if (query.value(4)==super) superuser=true;
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
void Database::showrestable(){
    int num_rows=0,r=0,c=0;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM RESERVATION");
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    restable->setRowCount(num_rows);
    q.prepare("SELECT * FROM RESERVATION");
    if(!q.exec()) qDebug() << q.lastError().text();
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<5;++c){
            restable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
}
void Database::showprofiltable(){
    int num_rows=0,r=0,c=0;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM PROFIL");
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    profiltable->setRowCount(num_rows);
    q.prepare("SELECT * FROM PROFIL");
    if(!q.exec()) qDebug() << q.lastError().text();
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<3;++c){
            profiltable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
}
void Database::showemployeetable(){
    int num_rows=0,r=0,c=0;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM EMPLOYEE");
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    employeetable->setRowCount(num_rows);
    q.prepare("SELECT * FROM EMPLOYEE");
    if(!q.exec()) qDebug() << q.lastError().text();
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<6;++c){
            employeetable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
}
void Database::showabonnementtable(){
    int num_rows=0,r=0,c=0;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM ABONNEMENTS");
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    abonnementtable->setRowCount(num_rows);
    q.prepare("SELECT * FROM ABONNEMENTS");
    if(!q.exec()) qDebug() << q.lastError().text();
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<4;++c){
            abonnementtable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
}
void Database::showsubtable(){
    int num_rows=0,r=0,c=0;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM SUBSCRIBERS");
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    subtable->setRowCount(num_rows);
    q.prepare("SELECT * FROM SUBSCRIBERS");
    if(!q.exec()) qDebug() << q.lastError().text();
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<4;++c){
            subtable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
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
void Database::addevent(int roomid, QString eventname, QString eventtype, QDateTime time){
    QSqlQuery query,q2;
    int tempid=1,test;
    q2.prepare("SELECT * FROM EVENTS ORDER BY ID");
    q2.exec();
    while(q2.next()){
        tempid++;
        test = q2.value(0).toInt();
        if(tempid==test) {tempid++; qDebug() <<"here";}
    }
    query.prepare("INSERT INTO EVENTS (ID, ROOMID, EVNAME, EVTYPE, TIME) VALUES (:ID, :roomid, :evname, :evtype, :time)");
    query.bindValue(":ID",tempid);
    query.bindValue(":roomid",roomid);
    query.bindValue(":evname",eventname);
    query.bindValue(":evtype",eventtype);
    query.bindValue(":time",time);
    if(query.exec()) qDebug() <<"added event";
}
void Database::addmovie(QString movname, QString movtype, QString length, QString lang){
    QSqlQuery query,q2;
    int tempid=1,test;
    q2.prepare("SELECT * FROM MOVIES ORDER BY ID");
    q2.exec();
    while(q2.next()){
        tempid++;
        test = q2.value(0).toInt();
        if(tempid==test) {tempid++; qDebug() <<"here";}
    }
    query.prepare("INSERT INTO MOVIES (ID, NAME, TYPE, LENGTH, LANGUAGE) VALUES (:ID, :movname, :movtype, :length, :lang)");
    query.bindValue(":ID",tempid);
    query.bindValue(":movname",movname);
    query.bindValue(":movtype",movtype);
    query.bindValue(":length",length);
    query.bindValue(":lang",lang);
    if(query.exec()) qDebug() <<"added movie";
}
void Database::addprofil(QString profil,QString post){
    QSqlQuery query,q2;
    int tempid=1,test;
    q2.prepare("SELECT * FROM PROFIL ORDER BY ID");
    q2.exec();
    while(q2.next()){
        tempid++;
        test = q2.value(0).toInt();
        if(tempid==test) {tempid++; qDebug() <<"here";}
    }
    query.prepare("INSERT INTO PROFIL (ID, PROFILE, POST) VALUES (:ID, :profile, :post)");
    query.bindValue(":ID",tempid);
    query.bindValue(":profile",profil);
    query.bindValue(":post",post);
    if(query.exec()) qDebug() <<"added profil";
}
void Database::addemployee(QString name, QString fname, QString email, QString username, QString password){
    QSqlQuery query,q2,q3,q4;
    int tempid=1,test,tempid2=1;
    q2.prepare("SELECT * FROM EMPLOYEE ORDER BY ID");
    q2.exec();
    while(q2.next()){
        tempid++;
        test = q2.value(0).toInt();
        if(tempid==test) {tempid++; qDebug() <<"here";}
    }
    q4.prepare("SELECT * FROM ACCOUNTS ORDER BY ID");
    q4.exec();
    while(q4.next()){
        tempid2++;
        test = q4.value(0).toInt();
        if(tempid2==test) {tempid2++; qDebug() <<"here";}
    }
    query.prepare("INSERT INTO EMPLOYEE (ID, NAME, FNAME, EMAIL, USERNAME, PASSWORD) VALUES (:ID, :name, :fname, :email, :username, :password)");
    query.bindValue(":ID",tempid);
    query.bindValue(":name",name);
    query.bindValue(":fname",fname);
    query.bindValue(":email",email);
    query.bindValue(":username",username);
    query.bindValue(":password",password);
    q3.prepare("INSERT INTO ACCOUNTS (ID, USERNAME, PASSWORD, OWNERID) VALUES (:ID, :username, :password, :ownerid)");
    q3.bindValue(":ID",tempid2);
    q3.bindValue(":username",username);
    q3.bindValue(":password",password);
    q3.bindValue(":ownerid",tempid);
    if(query.exec()) qDebug() <<"added employee";
    if(q3.exec()) qDebug() <<"account setup";
}
void Database::addabonnement(QString date, QString type, int points){
    QSqlQuery query,q2;
    int tempid=1,test;
    q2.prepare("SELECT * FROM ABONNEMENTS ORDER BY ID");
    q2.exec();
    while(q2.next()){
        tempid++;
        test = q2.value(0).toInt();
        if(tempid==test) {tempid++; qDebug() <<"here";}
    }
    query.prepare("INSERT INTO ABONNEMENTS (ID, DATES, TYPE, POINTS) VALUES (:ID, :date, :type, :points)");
    query.bindValue(":ID",tempid);
    query.bindValue(":date",date);
    query.bindValue(":type",type);
    query.bindValue(":points",points);
    if(query.exec()) qDebug() <<"added abonnement";
}
void Database::addsubscriber(QString name, QString fname, QString email){
    QSqlQuery query,q2;
    int tempid=1,test;
    q2.prepare("SELECT * FROM SUBSCRIBERS ORDER BY ID");
    q2.exec();
    while(q2.next()){
        tempid++;
        test = q2.value(0).toInt();
        if(tempid==test) {tempid++; qDebug() <<"here";}
    }
    query.prepare("INSERT INTO SUBSCRIBERS (ID, NAME, FNAME, EMAIL) VALUES (:ID, :name, :fname, :email)");
    query.bindValue(":ID",tempid);
    query.bindValue(":name",name);
    query.bindValue(":fname",fname);
    query.bindValue(":email",email);
    if(query.exec()) qDebug() <<"added subscriber";
}
void Database::addparking(QString spot, QString owner, QString license){
    QSqlQuery query,q2;
    int tempid=1,test;
    q2.prepare("SELECT * FROM PARKING ORDER BY ID");
    q2.exec();
    while(q2.next()){
        tempid++;
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
bool Database::addreservation(int idf,int idev,QString nplaces,QString dates){
    QSqlQuery query,q2; bool done;
    int tempid=1,test;
    q2.prepare("SELECT * FROM RESERVATION ORDER BY ID");
    q2.exec();
    while(q2.next()){
        tempid++;
        test = q2.value(0).toInt();
        if(tempid==test) tempid++;
    }
    query.prepare("INSERT INTO RESERVATION (ID, IDFILM, IDEVENT, NPLACES, DATERES) VALUES (:ID, :idfilm, :idevent, :nplaces, :dateres)");
    query.bindValue(":ID",tempid);
    query.bindValue(":idfilm",idf);     //7ot verification
    query.bindValue(":idevent",idev);
    query.bindValue(":nplaces",nplaces);
    query.bindValue(":dateres",dates);
    if(query.exec()) {done = true; qDebug() <<"added reservation";}
    else done = false;
    return done;
}
void Database::addroom(QString chairsize, QString chairquality, QString chaircount){
    QSqlQuery query,q2;
    int tempid=1,test;
    q2.prepare("SELECT * FROM ROOMS ORDER BY ID");
    q2.exec();
    while(q2.next()){
        tempid++;
        test = q2.value(0).toInt();
        if(tempid==test) tempid++;
    }
    query.prepare("INSERT INTO ROOMS (ID, CHAIRSIZE, CHAIRCOUNT, CHAIRQUALITY) VALUES (:ID, :chairsize, :chaircount, :chairquality)");
    query.bindValue(":ID",tempid);
    query.bindValue(":chairsize",chairsize);
    query.bindValue(":chaircount",chaircount);
    query.bindValue(":chairquality",chairquality);

    if(query.exec()) qDebug() <<"added room info";
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
void Database::showeventtable(){
    int num_rows=0,r=0,c=0;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));

    if(!q.exec("SELECT count(ID) AS num_rows FROM EVENTS")) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    evtable->setRowCount(num_rows);
    evtable->setSortingEnabled(false);
    if(!q.exec("SELECT * FROM EVENTS")) qDebug() <<q.lastError().text();
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<5;c++){
            evtable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
}
void Database::showroomtable(){
    int num_rows=0,r=0,c=0;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));

    if(!q.exec("SELECT count(ID) AS num_rows FROM ROOMS")) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    roomtable->setRowCount(num_rows);
    roomtable->setSortingEnabled(false);
    if(!q.exec("SELECT * FROM ROOMS")) qDebug() <<q.lastError().text();
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<4;c++){
            roomtable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
}
void Database::showmovietable(){
    int num_rows=0,r=0,c=0;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));

    if(!q.exec("SELECT count(ID) AS num_rows FROM MOVIES")) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    movtable->setRowCount(num_rows);
    movtable->setSortingEnabled(false);
    if(!q.exec("SELECT * FROM MOVIES")) qDebug() <<q.lastError().text();
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<5;c++){
            movtable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
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
bool Database::modifyevent(int id, int roomid, QString eventname, QString eventtype, QDateTime time){
    QSqlQuery q; int total=0;

    q.prepare("SELECT * FROM EVENTS WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("UPDATE EVENTS SET ROOMID=:roomid , EVNAME=:eventname, EVTYPE=:eventtype, TIME=:time WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.bindValue(":eventname",eventname);
        query.bindValue(":roomid",roomid);
        query.bindValue(":eventtype",eventtype);
        query.bindValue(":time",time);
        query.exec();
        q.first();
        return true;}
    else return false;
}
bool Database::modifysub(int id, QString name, QString fname, QString email){
    QSqlQuery q; int total=0;

    q.prepare("SELECT * FROM SUBSCRIBERS WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("UPDATE SUBSCRIBERS SET NAME=:name , FNAME=:fname, EMAIL=:email WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.bindValue(":name",name);
        query.bindValue(":fname",fname);
        query.bindValue(":email",email);
        query.exec();
        q.first();
        return true;}
    else return false;
}
bool Database::modifyprofil(int id, QString profil, QString post){
    QSqlQuery q; int total=0;

    q.prepare("SELECT * FROM PROFIL WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("UPDATE PROFIL SET PROFILE=:profil , POST=:post WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.bindValue(":profil",profil);
        query.bindValue(":post",post);
        query.exec();
        q.first();
        return true;}
    else return false;
}
bool Database::modifyemployee(int id,QString name, QString fname, QString email, QString username, QString password){
    QSqlQuery q; int total=0;
    q.prepare("SELECT * FROM EMPLOYEE WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query,q2;
        query.prepare("UPDATE EMPLOYEE SET NAME=:name , FNAME=:fname, EMAIL=:email, USERNAME=:username, PASSWORD=:password WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.bindValue(":name",name);
        query.bindValue(":fname",fname);
        query.bindValue(":email",email);
        query.bindValue(":username",username);
        query.bindValue(":password",password);
        query.exec();
        q.first();
        q2.prepare("UPDATE ACCOUNTS SET USERNAME=:username, PASSWORD=:password WHERE OWNERID=:ID");
        q2.bindValue(":ID",id);
        q2.bindValue(":username",username);
        q2.bindValue(":password",password);
        q2.exec();
        return true;}
    else return false;
}
bool Database::modifyabonnement(int id, QString date, QString type, int points){
    QSqlQuery q; int total=0;

    q.prepare("SELECT * FROM ABONNEMENTS WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("UPDATE ABONNEMENTS SET DATES=:date , TYPE=:type, POINTS=:points WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.bindValue(":date",date);
        query.bindValue(":type",type);
        query.bindValue(":points",points);
        query.exec();
        q.first();
        return true;}
    else return false;
}
bool Database::modifymovie(int id,QString movname,QString movtype,QString length, QString lang){
    QSqlQuery q; int total=0;

    q.prepare("SELECT * FROM MOVIES WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("UPDATE MOVIES SET NAME=:movname , TYPE=:movtype, LENGTH=:length, LANGUAGE=:lang WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.bindValue(":movname",movname);
        query.bindValue(":movtype",movtype);
        query.bindValue(":length",length);
        query.bindValue(":lang",lang);
        query.exec();
        q.first();
        return true;}
    else return false;
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
bool Database::modifyroom(int id,QString chairsize, QString chairquality, QString chaircount){
    QSqlQuery q; int total=0;

    q.prepare("SELECT * FROM ROOMS WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("UPDATE ROOMS SET CHAIRSIZE=:chairsize, CHAIRQUALITY=:chairquality, CHAIRCOUNT=:chaircount WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.bindValue(":chairsize",chairsize);
        query.bindValue(":chairquality",chairquality);
        query.bindValue(":chaircount",chaircount);
        query.exec();
        q.first();
        return true;}
    else return false;
}
bool Database::modifyres(int id ,int idf,int idev,QString nplaces,QString dates){
    QSqlQuery q; int total=0;
    q.prepare("SELECT * FROM RESERVATION WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("UPDATE RESERVATION SET IDFILM=:idf, IDEVENT=:idev, NPLACES=:nplaces, DATERES=:dates WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.bindValue(":idf",idf);
        query.bindValue(":idev",idev);
        query.bindValue(":nplaces",nplaces);
        query.bindValue(":dates",dates);
        query.exec();
        q.first();
        return true;
    }
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
    while(q.next()){total++;}
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
bool Database::deleteprofil(int id){
    QSqlQuery q; int total=0;
    q.prepare("SELECT * FROM PROFIL WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("DELETE FROM PVENTES WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.exec();
        q.first();

        return true;
    }
    else return false;
}
bool Database::deleteemployee(int id){
    QSqlQuery q; int total=0;
    q.prepare("SELECT * FROM EMPLOYEE WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query,q2;
        query.prepare("DELETE FROM EMPLOYEE WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.exec();
        q.first();
        q2.prepare("DELETE FROM ACCOUNTS WHERE OWNERID=:ID");
        q2.bindValue(":ID",id);
        q2.exec();
        return true;
    }
    else return false;
}
bool Database::deleteroom(int id){
    QSqlQuery q; int total=0;
    q.prepare("SELECT * FROM ROOMS WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("DELETE FROM ROOMS WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.exec();
        q.first();

        return true;
    }
    else return false;
}
bool Database::deleteabonnement(int id){
    QSqlQuery q; int total=0;
    q.prepare("SELECT * FROM ABONNEMENTS WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("DELETE FROM ABONNEMENTS WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.exec();
        q.first();

        return true;
    }
    else return false;
}
bool Database::deletesub(int id){
    QSqlQuery q; int total=0;
    q.prepare("SELECT * FROM SUBSCRIBERS WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("DELETE FROM SUBSCRIBERS WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.exec();
        q.first();

        return true;
    }
    else return false;
}
bool Database::deleteres(int id){
    QSqlQuery q; int total=0;
    q.prepare("SELECT * FROM RESERVATION WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("DELETE FROM RESERVATION WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.exec();
        q.first();
        return true;
    }
    else return false;
}
bool Database::deletemov(int id){
    QSqlQuery q; int total=0;
    q.prepare("SELECT * FROM MOVIES WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("DELETE FROM MOVIES WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.exec();
        q.first();
        return true;
    }
    else return false;
}
bool Database::deleteevent(int id){
    QSqlQuery q; int total=0;
    q.prepare("SELECT * FROM EVENTS WHERE ID=:ID");
    q.bindValue(":ID",id);
    q.exec();
    while(q.next()){total++;}
    if(total==1){
        QSqlQuery query;
        query.prepare("DELETE FROM EVENTS WHERE ID=:ID");
        query.bindValue(":ID",id);
        query.exec();
        q.first();
        return true;
    }
    else return false;
}
bool Database::searchevent(int id){
    int num_rows=0,r=0,c=0;
    bool output=true;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM EVENTS WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    evtable->setRowCount(num_rows);
    q.prepare("SELECT * FROM EVENTS WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) output = false;
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<5;++c){
            evtable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
    return output;
}
bool Database::searchemployee(int id){
    int num_rows=0,r=0,c=0;
    bool output=true;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM EMPLOYEE WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    employeetable->setRowCount(num_rows);
    q.prepare("SELECT * FROM EMPLOYEE WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) output = false;
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<6;++c){
            employeetable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
    return output;
}
bool Database::searchprofil(int id){
    int num_rows=0,r=0,c=0;
    bool output=true;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM PROFIL WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    profiltable->setRowCount(num_rows);
    q.prepare("SELECT * FROM PROFIL WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) output = false;
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<3;++c){
            profiltable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
    return output;
}
bool Database::searchsub(int id){
    int num_rows=0,r=0,c=0;
    bool output=true;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM SUBSCRIBERS WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    subtable->setRowCount(num_rows);
    q.prepare("SELECT * FROM SUBSCRIBERS WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) output = false;
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<4;++c){
            subtable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
    return output;
}
bool Database::searchabonnement(int id){
    int num_rows=0,r=0,c=0;
    bool output=true;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM ABONNEMENTS WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    abonnementtable->setRowCount(num_rows);
    q.prepare("SELECT * FROM ABONNEMENTS WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) output = false;
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<4;++c){
            abonnementtable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
    return output;
}
bool Database::searchroom(int id){
    int num_rows=0,r=0,c=0;
    bool output=true;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM ROOMS WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    roomtable->setRowCount(num_rows);
    q.prepare("SELECT * FROM ROOMS WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) output = false;
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<4;++c){
            roomtable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
    return output;
}
bool Database::searchres(int id){
    int num_rows=0,r=0,c=0;
    bool output=true;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM RESERVATION WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    restable->setRowCount(num_rows);
    q.prepare("SELECT * FROM RESERVATION WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) output = false;
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<5;++c){
            restable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
    return output;
}
bool Database::searchmov(int id){
    int num_rows=0,r=0,c=0;
    bool output=true;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    q.prepare("SELECT count(ID) AS num_rows FROM MOVIES WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    movtable->setRowCount(num_rows);
    q.prepare("SELECT * FROM MOVIES WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(!q.exec()) output = false;
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<5;++c){
            movtable->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
    return output;
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
