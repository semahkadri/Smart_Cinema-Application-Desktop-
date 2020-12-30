#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qcoreapplication.h>
#include "gesproduit.h"
#include "greservation.h"
#include "gesevenement.h"
#include "gesfilm.h"
#include "gessalle.h"
#include "gesprofil.h"
#include "welcomewidget.h"
#include "gsubscribers.h"
#include "gesemployee.h"
#include "gabonnements.h"
#include "gesparking.h"
#include "QSqlQuery"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent,Qt::FramelessWindowHint | Qt::WindowSystemMenuHint)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(3);
    this->setGraphicsEffect(effect);

    int ret =A.connect_arduino();
        switch(ret){
        case(0):qDebug()<<"arduino is available and connect to : " <<A.getarduino_port_name();
                break;
        case(1):qDebug()<<"arduino is available but not connected to : "<<A.getarduino_port_name();
                break;
        case(-1):qDebug()<<"arduino in not available";
        }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

    bigpanel = new QWidget(this);
    //bigpanel->setParent(this);
    bigpanel->setGeometry(QRect(0,0,700,500));
    bigpanel->setStyleSheet("background-color: rgb(255,255,255);"
                            "border-radius:15px");
    sidepanel = new QWidget(this);
    //sidepanel->setParent(this);
    sidepanel->setGeometry(QRect(-200,0,350,500));
    sidepanel->setStyleSheet("background-color: rgb(51, 51, 51);"
                             "border-radius:15px");
    cinemapp = new QLabel(sidepanel);
    //cinemapp->setParent(sidepanel);
    cinemapp->setGeometry(QRect(100,0,240,490));
    cinemapp->setStyleSheet("image: url(:/images/Tekengebied 1.png);"
                            "background-color: rgba(255,255,255,0);border: 0px;");

    loginbtn = new QtMaterialRaisedButton(bigpanel);
    //loginbtn->setParent(bigpanel);
    loginbtn->setText("Login");
    loginbtn->setGeometry(QRect(210,450,200,30));
    loginbtn->setHaloVisible(false);

    quitbtn = new QtMaterialRaisedButton(bigpanel);
    //quitbtn->setParent(bigpanel);
    quitbtn->setText("Exit");
    quitbtn->setGeometry(QRect(440,450,200,30));
    quitbtn->setHaloVisible(false);

    passwordtext = new QtMaterialTextField(bigpanel);
    passwordtext->setLabel("password");
    passwordtext->setInkColor("black");
    passwordtext->setGeometry(QRect(160,200,530,60));
    passwordtext->setMaxLength(20);

    seepw = new QRadioButton(bigpanel);
    seepw->setText("");
    seepw->setGeometry(QRect(600,240,15,15));
    passwordtext->setEchoMode(QLineEdit::Password);
    connect(seepw,SIGNAL(clicked()),this,SLOT(seepassword()));

    logintext = new QtMaterialTextField(bigpanel);
    logintext->setLabel("username");
    logintext->setInkColor("black");
    logintext->setGeometry(QRect(160,100,530,60));
    logintext->setMaxLength(20);
    loginwarning = new QtMaterialSnackbar(this);

    Gprofil = new QtMaterialRaisedButton(sidepanel);
    //Gparking->setParent(sidepanel);
    Gprofil->setText("Gestion Profil");
    Gprofil->setGeometry(QRect(800,175,200,30));
    Gprofil->setHaloVisible(false);

    Gproduit = new QtMaterialRaisedButton(sidepanel);
    //Gproduit->setParent(sidepanel);
    Gproduit->setText("Gestion Produit");
    Gproduit->setGeometry(QRect(800,120,200,30)); // between buttons 55 pix
    Gproduit->setHaloVisible(false);

    Gparking = new QtMaterialRaisedButton(sidepanel);
    //Gparking->setParent(sidepanel);
    Gparking->setText("Gestion Parking");
    Gparking->setGeometry(QRect(800,65,200,30));
    Gparking->setHaloVisible(false);

    Greservation = new QtMaterialRaisedButton(sidepanel);
    //Gparking->setParent(sidepanel);
    Greservation->setText("Gestion Reservation");
    Greservation->setGeometry(QRect(800,230,200,30));
    Greservation->setHaloVisible(false);

    Gevent = new QtMaterialRaisedButton(sidepanel);
    //quitbtn2->setParent(sidepanel);
    Gevent->setText("Gestion Evenement");
    Gevent->setGeometry(QRect(800,285,200,30));
    Gevent->setHaloVisible(false);

    gmovie = new QtMaterialRaisedButton(sidepanel);
    //quitbtn2->setParent(sidepanel);
    gmovie->setText("Gestion films");
    gmovie->setGeometry(QRect(800,340,200,30));
    gmovie->setHaloVisible(false);

    quitbtn2 = new QtMaterialRaisedButton(sidepanel);
    //quitbtn2->setParent(sidepanel);
    quitbtn2->setText("Exit");
    quitbtn2->setGeometry(QRect(800,395,200,30));
    quitbtn2->setHaloVisible(false);

    welcomebtn = new QtMaterialRaisedButton(sidepanel);
    //welcome->setParent(sidepanel);
    welcomebtn->setText("Welcome");
    welcomebtn->setGeometry(QRect(800,10,200,30));
    welcomebtn->setHaloVisible(false);

    Gemployee = new QtMaterialRaisedButton(sidepanel);
    //welcome->setParent(sidepanel);
    Gemployee->setText("G-Employee");
    Gemployee->setGeometry(QRect(0,1400,200,30));
    Gemployee->setHaloVisible(false);

    gabonnement = new QtMaterialRaisedButton(sidepanel);
    //welcome->setParent(sidepanel);
    gabonnement->setText("Abonnements");
    gabonnement->setGeometry(QRect(0,1200,200,30));
    gabonnement->setHaloVisible(false);

    gsubscribe = new QtMaterialRaisedButton(sidepanel);
    //welcome->setParent(sidepanel);
    gsubscribe->setText("Abonees");
    gsubscribe->setGeometry(QRect(0,1000,200,30));
    gsubscribe->setHaloVisible(false);

    groom = new QtMaterialRaisedButton(sidepanel);
    //welcome->setParent(sidepanel);
    groom->setText("Gestion salle");
    groom->setGeometry(QRect(0,800,200,30));
    groom->setHaloVisible(false);


    scroll = new QPushButton(sidepanel);
    scroll->setGeometry(QRect(800,430,65,65));
    scroll->setStyleSheet(
                          "image: url(:/images/arrow-down-sign-to-navigate.png);"
                          "background-color: rgba(255, 255, 255, 0);"
                                                    "border: 0px;");


    scrolled=false;

    stack = new QStackedWidget(bigpanel);
    QWidget *ayesm = new Gesproduit;
    QWidget *welcome = new welcomewidget;
    QWidget *gsparking = new Gesparking;
    QWidget *gsreservation = new greservation;
    QWidget *gsevenement = new gesevenement;
    QWidget *gmovies = new gesfilm;
    QWidget *gsalle = new gessalle;
    QWidget *gsubs = new gsubscribers;
    QWidget *gabs = new gabonnements;
    QWidget *gemp = new gesemployee;
    QWidget *gprofil = new gesprofil;
    stack->setStyleSheet("background-color: rgb(255,255,255);");
    stack->setGeometry(QRect(1000,10,690,480));
    stack->addWidget(welcome);
    stack->addWidget(gsparking);
    stack->addWidget(ayesm);
    stack->addWidget(gsreservation);
    stack->addWidget(gsevenement);
    stack->addWidget(gmovies);
    stack->addWidget(gsalle);
    stack->addWidget(gsubs);
    stack->addWidget(gabs);
    stack->addWidget(gemp);
    stack->addWidget(gprofil);


    connect(welcomebtn, SIGNAL(clicked()),this, SLOT(onwelcomeclicked()), Qt::UniqueConnection);
    connect(Greservation, SIGNAL(clicked()),this, SLOT(onreservationclicked()), Qt::UniqueConnection);
    connect(Gparking, SIGNAL(clicked()),this, SLOT(onparkingclicked()), Qt::UniqueConnection);
    connect(Gproduit, SIGNAL(clicked()),this, SLOT(gesproduitclicked()), Qt::UniqueConnection);
    connect(quitbtn2, SIGNAL(clicked()),this, SLOT(quitclicked()), Qt::UniqueConnection);
    connect(quitbtn, SIGNAL(clicked()),this, SLOT(quitclicked()), Qt::UniqueConnection);
    connect(loginbtn, SIGNAL(clicked()), this, SLOT(loginclicked()), Qt::UniqueConnection);
    connect(Gevent, SIGNAL(clicked()),this,SLOT(oneventclicked()), Qt::UniqueConnection);
    connect(scroll,SIGNAL(clicked()),this,SLOT(onscrollclicked()), Qt::UniqueConnection);
    connect(gmovie,SIGNAL(clicked()),this,SLOT(onmovieclicked()), Qt::UniqueConnection);
    connect(groom,SIGNAL(clicked()),this,SLOT(ongessalleclicked()), Qt::UniqueConnection);
    connect(gsubscribe,SIGNAL(clicked()),this,SLOT(onsubscribeclicked()), Qt::UniqueConnection);
    connect(gabonnement,SIGNAL(clicked()),this,SLOT(onabonnementclicked()),Qt::UniqueConnection);
    connect(Gprofil,SIGNAL(clicked()),this,SLOT(onprofilclicked()),Qt::UniqueConnection);

}


void MainWindow::onscrollclicked( ){
   QPropertyAnimation *A_scrollmove,*A_gemployee,*A_Abonnement,*A_groom,*A_subscribers,*A_movie,*A_gesevent,*A_greservation,*A_gclient,*A_quitbtn2,*A_welcome,*A_gparking,*A_gproduit;
    if(!scrolled){
        scrolled=true;
        scroll->setStyleSheet(
                              "image: url(:/images/arrow-up-sign-to-navigate.png);"
                              "background-color: rgba(255, 255, 255, 0);"
                                                        "border: 0px;");

        A_greservation = new QPropertyAnimation(Greservation,"geometry");
        A_gesevent = new QPropertyAnimation(Gevent,"geometry");
        A_gparking = new QPropertyAnimation(Gparking,"geometry");
        A_gclient = new QPropertyAnimation(Gprofil,"geometry");
        A_gproduit = new QPropertyAnimation(Gproduit,"geometry");
        A_quitbtn2 = new QPropertyAnimation(quitbtn2,"geometry");
        A_welcome = new QPropertyAnimation(welcomebtn,"geometry");
        A_scrollmove = new QPropertyAnimation(scroll,"geometry");
        A_movie = new QPropertyAnimation(gmovie,"geometry");
        A_groom = new QPropertyAnimation(groom,"geometry");
        A_subscribers = new QPropertyAnimation(gsubscribe,"geometry");
        A_Abonnement = new QPropertyAnimation(gabonnement,"geometry");
        A_gemployee = new QPropertyAnimation(Gemployee,"geometry");

       //scrolling up from top
        A_scrollmove->setDuration(1600);
        A_welcome->setDuration(1600);   //number 1
        A_gparking->setDuration(1600);  //number 2
        A_gproduit->setDuration(1600);  //number 3
        A_gesevent->setDuration(1600);
        A_gclient->setDuration(1600);
        A_greservation->setDuration(1600);
        A_quitbtn2->setDuration(1600);
        A_movie->setDuration(1600);
       //scrolling up from bottom
        A_groom ->setDuration(1500);
        A_subscribers->setDuration(1600);
        A_Abonnement->setDuration(1700);
        A_gemployee->setDuration(1800);

        //scrolling up from top
        A_scrollmove->setStartValue(QRect(70,430,65,65));
        A_greservation->setStartValue(QRect(0,230,200,30));
        A_gclient->setStartValue(QRect(0,175,200,30));
        A_quitbtn2->setStartValue(QRect(0,395,200,30));
        A_gparking->setStartValue(QRect(0,65,200,30));
        A_gproduit->setStartValue(QRect(0,120,200,30));
        A_welcome->setStartValue(QRect(0,10,200,30));
        A_gesevent->setStartValue(QRect(0,285,200,30));
        A_movie->setStartValue(QRect(0,340,200,30));

        //scrolling up from bottom
        A_groom->setStartValue(groom->geometry());
        A_subscribers->setStartValue(groom->geometry());
        A_Abonnement->setStartValue(gabonnement->geometry());
        A_gemployee->setStartValue(Gemployee->geometry());

        //scrolling up from top
        A_scrollmove->setEndValue(QRect(70,5,65,65));
        A_welcome->setEndValue(QRect(0,-1600,200,30));     //number 0
        A_gparking->setEndValue(QRect(0,-1400,200,30));    //number 1
        A_gproduit->setEndValue(QRect(0,-1200,200,30));   //number 2
        A_gesevent->setEndValue(QRect(0,-600,200,30));
        A_quitbtn2->setEndValue(QRect(0,-200,200,30));
        A_gclient->setEndValue(QRect(0,-1000,200,30));    //number 4
        A_greservation->setEndValue(QRect(0,-800,200,30));//number 3
        A_movie->setEndValue(QRect(0,-400,200,30));

        //scrolling up from bottom
        A_groom->setEndValue(QRect(0,65,200,30));
        A_subscribers->setEndValue(QRect(0,120,200,30));
        A_Abonnement->setEndValue(QRect(0,175,200,30));
        A_gemployee->setEndValue(QRect(0,230,200,30));

        A_scrollmove->setEasingCurve(QEasingCurve::InOutQuint);
        A_greservation->setEasingCurve(QEasingCurve::InOutQuint);
        A_gclient->setEasingCurve(QEasingCurve::InOutQuint);
        A_quitbtn2->setEasingCurve(QEasingCurve::InOutQuint);
        A_gparking->setEasingCurve(QEasingCurve::InOutQuint);
        A_gproduit->setEasingCurve(QEasingCurve::InOutQuint);
        A_welcome->setEasingCurve(QEasingCurve::InOutQuint);
        A_gesevent->setEasingCurve(QEasingCurve::InOutQuint);
        A_movie->setEasingCurve(QEasingCurve::InOutQuint);
        A_groom->setEasingCurve(QEasingCurve::InOutQuint);
        A_subscribers->setEasingCurve(QEasingCurve::InOutQuint);
        A_Abonnement->setEasingCurve(QEasingCurve::InOutQuint);
        A_gemployee->setEasingCurve(QEasingCurve::InOutQuint);
        //delte when finished
        A_groom->start(QPropertyAnimation::DeleteWhenStopped);
        A_greservation->start(QPropertyAnimation::DeleteWhenStopped);
        A_gclient->start(QPropertyAnimation::DeleteWhenStopped);
        A_gproduit->start(QPropertyAnimation::DeleteWhenStopped);
        A_gparking->start(QPropertyAnimation::DeleteWhenStopped);
        A_scrollmove->start(QPropertyAnimation::DeleteWhenStopped);
        A_quitbtn2->start(QPropertyAnimation::DeleteWhenStopped);
        A_welcome->start(QPropertyAnimation::DeleteWhenStopped);
        A_gesevent->start(QPropertyAnimation::DeleteWhenStopped);
        A_movie->start(QPropertyAnimation::DeleteWhenStopped);
        A_subscribers->start(QPropertyAnimation::DeleteWhenStopped);
        A_Abonnement->start(QPropertyAnimation::DeleteWhenStopped);
        A_gemployee->start(QPropertyAnimation::DeleteWhenStopped);
    }else{
        scrolled=false;
        scroll->setStyleSheet(
                              "image: url(:/images/arrow-down-sign-to-navigate.png);"
                              "background-color: rgba(255, 255, 255, 0);"
                                                        "border: 0px;");
        A_greservation = new QPropertyAnimation(Greservation,"geometry");
        A_gesevent = new QPropertyAnimation(Gevent,"geometry");
        A_gparking = new QPropertyAnimation(Gparking,"geometry");
        A_gclient = new QPropertyAnimation(Gprofil,"geometry");
        A_gproduit = new QPropertyAnimation(Gproduit,"geometry");
        A_quitbtn2 = new QPropertyAnimation(quitbtn2,"geometry");
        A_welcome = new QPropertyAnimation(welcomebtn,"geometry");
        A_scrollmove = new QPropertyAnimation(scroll,"geometry");
        A_movie = new QPropertyAnimation(gmovie,"geometry");
        A_groom = new QPropertyAnimation(groom,"geometry");
        A_subscribers = new QPropertyAnimation(gsubscribe,"geometry");
        A_Abonnement = new QPropertyAnimation(gabonnement,"geometry");
        A_gemployee = new QPropertyAnimation(Gemployee,"geometry");
        //scrolling down from top
        A_scrollmove->setDuration(1500);
        A_welcome->setDuration(1100);   //number 1
        A_gparking->setDuration(1200);  //number 2
        A_gproduit->setDuration(1300);  //number 3
        A_gesevent->setDuration(1600);
        A_gclient->setDuration(1400);
        A_greservation->setDuration(1500);
        A_quitbtn2->setDuration(1700);
        A_movie->setDuration(1600);
        //scrolling down to bottom
        A_groom->setDuration(1500);
        A_subscribers->setDuration(1500);
        A_Abonnement->setDuration(1500);
        A_gemployee->setDuration(1500);
        //scrolling down from top
        A_movie->setStartValue(QRect(0,-1000,200,30));
        A_scrollmove->setStartValue(QRect(70,5,65,65));
        A_greservation->setStartValue(QRect(0,-1000,200,30));
        A_gclient->setStartValue(QRect(0,-1000,200,30));
        A_quitbtn2->setStartValue(QRect(0,-1000,200,30));
        A_gparking->setStartValue(QRect(0,-1000,200,30));
        A_gproduit->setStartValue(QRect(0,-1000,200,30));
        A_welcome->setStartValue(QRect(0,-1000,200,30));
        A_gesevent->setStartValue(QRect(0,-1000,200,30));

        //scrolling down to bottom
        A_groom->setStartValue(QRect(0,65,200,30));
        A_subscribers->setStartValue(QRect(0,120,200,30));
        A_Abonnement->setStartValue(QRect(0,175,200,30));
        A_gemployee->setStartValue(QRect(0,230,200,30));

        //scrolling down from top
        A_movie->setEndValue(QRect(0,340,200,30));
        A_scrollmove->setEndValue(QRect(70,430,65,65));
        A_welcome->setEndValue(QRect(0,10,200,30));     //number 0
        A_gparking->setEndValue(QRect(0,65,200,30));    //number 1
        A_gproduit->setEndValue(QRect(0,120,200,30));   //number 2
        A_gesevent->setEndValue(QRect(0,285,200,30));
        A_quitbtn2->setEndValue(QRect(0,395,200,30));
        A_gclient->setEndValue(QRect(0,175,200,30));    //number 4
        A_greservation->setEndValue(QRect(0,230,200,30));//number 3

        //scrolling down to bottom
        A_groom->setEndValue(QRect(0,800,200,30));
        A_subscribers->setEndValue(QRect(0,1000,200,30));
        A_Abonnement->setEndValue(QRect(0,1200,200,30));
        A_gemployee->setEndValue(QRect(0,1400,200,30));

        A_movie->setEasingCurve(QEasingCurve::InOutQuint);
        A_scrollmove->setEasingCurve(QEasingCurve::InOutQuint);
        A_greservation->setEasingCurve(QEasingCurve::InOutQuint);
        A_gclient->setEasingCurve(QEasingCurve::InOutQuint);
        A_quitbtn2->setEasingCurve(QEasingCurve::InOutQuint);
        A_gparking->setEasingCurve(QEasingCurve::InOutQuint);
        A_gproduit->setEasingCurve(QEasingCurve::InOutQuint);
        A_welcome->setEasingCurve(QEasingCurve::InOutQuint);
        A_gesevent->setEasingCurve(QEasingCurve::InOutQuint);
        A_groom->setEasingCurve(QEasingCurve::InOutQuint);
        A_subscribers->setEasingCurve(QEasingCurve::InOutQuint);
        A_Abonnement->setEasingCurve(QEasingCurve::InOutQuint);
        A_gemployee->setEasingCurve(QEasingCurve::InOutQuint);
        //delte when finished
        A_movie->start(QPropertyAnimation::DeleteWhenStopped);
        A_greservation->start(QPropertyAnimation::DeleteWhenStopped);
        A_gclient->start(QPropertyAnimation::DeleteWhenStopped);
        A_gproduit->start(QPropertyAnimation::DeleteWhenStopped);
        A_gparking->start(QPropertyAnimation::DeleteWhenStopped);
        A_scrollmove->start(QPropertyAnimation::DeleteWhenStopped);
        A_quitbtn2->start(QPropertyAnimation::DeleteWhenStopped);
        A_welcome->start(QPropertyAnimation::DeleteWhenStopped);
        A_gesevent->start(QPropertyAnimation::DeleteWhenStopped);
        A_groom->start(QPropertyAnimation::DeleteWhenStopped);
        A_subscribers->start(QPropertyAnimation::DeleteWhenStopped);
        A_Abonnement->start(QPropertyAnimation::DeleteWhenStopped);
        A_gemployee->start(QPropertyAnimation::DeleteWhenStopped);
    }
}
void MainWindow::hidebuttons(){
    quitbtn->setVisible(false);
    loginbtn->setVisible(false);
    logintext->setVisible(false);
    seepw->setVisible(false);
    passwordtext->setVisible(false);
}
void MainWindow::loginclicked()
{
    QString username = logintext->text();
    QString password = passwordtext->text();

    if(db.loginconnection(username,password)){
                QPropertyAnimation *A_movie,*A_sidepanel,*A_scroll,*A_gesevent,*A_greservation,*A_gclient,*A_password,*A_radiobtn,*A_username,*A_loginbtn,*A_quitbtn,*A_stack,*A_quitbtn2,*A_logo,*A_welcome,*A_gparking,*A_gproduit;
                A_greservation = new QPropertyAnimation(Greservation,"geometry");
                A_gesevent = new QPropertyAnimation(Gevent,"geometry");
                A_gparking = new QPropertyAnimation(Gparking,"geometry");
                A_gclient = new QPropertyAnimation(Gprofil,"geometry");
                A_username = new QPropertyAnimation(logintext,"geometry");
                A_password = new QPropertyAnimation(passwordtext,"geometry");
                A_radiobtn = new QPropertyAnimation(seepw,"geometry");
                A_gproduit = new QPropertyAnimation(Gproduit,"geometry");
                A_sidepanel = new QPropertyAnimation(sidepanel,"geometry");
                A_loginbtn = new QPropertyAnimation(loginbtn,"geometry");
                A_quitbtn = new QPropertyAnimation(quitbtn,"geometry");
                A_quitbtn2 = new QPropertyAnimation(quitbtn2,"geometry");
                A_logo = new QPropertyAnimation(cinemapp,"geometry");
                A_welcome = new QPropertyAnimation(welcomebtn,"geometry");
                A_stack = new QPropertyAnimation(stack,"geometry");
                A_scroll=new QPropertyAnimation(scroll,"geometry");
                A_movie=new QPropertyAnimation(gmovie,"geometry");
                //Duration in ms

                A_greservation->setDuration(2400);
                A_username->setDuration(1500);
                A_gclient->setDuration(2300);
                A_password->setDuration(1500);
                A_radiobtn->setDuration(1500);
                A_logo->setDuration(8000);
                A_quitbtn2->setDuration(200);
                A_loginbtn->setDuration(1500);
                A_sidepanel->setDuration(1500);
                A_quitbtn->setDuration(1500);
                A_stack->setDuration(2000);
                A_welcome->setDuration(2000);   //number 1
                A_gparking->setDuration(2100);  //number 2
                A_gproduit->setDuration(2200);  //number 3
                A_gesevent->setDuration(2500);
                A_quitbtn2->setDuration(2700);
                A_movie->setDuration(2600);
                A_scroll->setDuration(2800);
                //set start value
                A_movie->setStartValue(gmovie->geometry());
                A_greservation->setStartValue(Greservation->geometry());
                A_gclient->setStartValue(Gprofil->geometry());
                A_radiobtn->setStartValue(seepw->geometry());
                A_username->setStartValue(logintext->geometry());
                A_password->setStartValue(passwordtext->geometry());
                A_quitbtn->setStartValue(quitbtn->geometry());
                A_sidepanel->setStartValue(sidepanel->geometry());
                A_loginbtn->setStartValue(loginbtn->geometry());
                A_quitbtn2->setStartValue(quitbtn2->geometry());
                A_gparking->setStartValue(Gparking->geometry());
                A_gproduit->setStartValue(Gproduit->geometry());
                A_welcome->setStartValue(welcomebtn->geometry());
                A_gesevent->setStartValue(Gevent->geometry());
                A_stack->setStartValue(stack->geometry());
                A_scroll->setStartValue(scroll->geometry());
                //set end value
                A_movie->setEndValue(QRect(0,340,200,30));
                A_password->setEndValue(QRect(1060,200,530,60));
                A_username->setEndValue(QRect(1060,100,530,60));
                A_radiobtn->setEndValue(QRect(900,240,15,15));
                A_logo->setEndValue(QRect(300,0,240,490));
                A_sidepanel->setEndValue(QRect(600,0,250,500));
                A_loginbtn->setEndValue(QRect(800,450,200,30));
                A_quitbtn->setEndValue(QRect(800,450,200,30));
                A_stack->setEndValue(QRect(10,10,690,480));
                A_welcome->setEndValue(QRect(0,10,200,30));     //number 0
                A_gparking->setEndValue(QRect(0,65,200,30));    //number 1
                A_gproduit->setEndValue(QRect(0,120,200,30));   //number 2
                A_gesevent->setEndValue(QRect(0,285,200,30));
                A_quitbtn2->setEndValue(QRect(0,395,200,30));
                A_gclient->setEndValue(QRect(0,175,200,30));    //number 4
                A_greservation->setEndValue(QRect(0,230,200,30));//number 3
                A_scroll->setEndValue(QRect(70,430,65,65));
                //special effects
                A_movie->setEasingCurve(QEasingCurve::InOutQuint);
                A_greservation->setEasingCurve(QEasingCurve::InOutQuint);
                A_gclient->setEasingCurve(QEasingCurve::InOutQuint);
                A_password->setEasingCurve(QEasingCurve::InOutQuint);
                A_username->setEasingCurve(QEasingCurve::InOutQuint);
                A_radiobtn->setEasingCurve(QEasingCurve::InOutQuint);
                A_logo->setEasingCurve(QEasingCurve::OutQuint);
                A_stack->setEasingCurve(QEasingCurve::InOutQuint);
                A_sidepanel->setEasingCurve(QEasingCurve::InOutQuint);
                A_loginbtn->setEasingCurve(QEasingCurve::InOutQuint);
                A_quitbtn2->setEasingCurve(QEasingCurve::InOutQuint);
                A_gparking->setEasingCurve(QEasingCurve::InOutQuint);
                A_gproduit->setEasingCurve(QEasingCurve::InOutQuint);
                A_quitbtn->setEasingCurve(QEasingCurve::InOutQuint);
                A_welcome->setEasingCurve(QEasingCurve::InOutQuint);
                A_gesevent->setEasingCurve(QEasingCurve::InOutQuint);
                A_scroll->setEasingCurve(QEasingCurve::InOutQuint);
                //hide the buttons on page switch
                connect(A_quitbtn,SIGNAL(finished()),this,SLOT(hidebuttons()));
                //delte when finished
                A_movie->start((QPropertyAnimation::DeleteWhenStopped));
                A_greservation->start((QPropertyAnimation::DeleteWhenStopped));
                A_gclient->start(QPropertyAnimation::DeleteWhenStopped);
                A_password->start(QPropertyAnimation::DeleteWhenStopped);
                A_username->start(QPropertyAnimation::DeleteWhenStopped);
                A_radiobtn->start(QPropertyAnimation::DeleteWhenStopped);
                A_stack->start(QPropertyAnimation::DeleteWhenStopped);
                A_gproduit->start(QPropertyAnimation::DeleteWhenStopped);
                A_gparking->start(QPropertyAnimation::DeleteWhenStopped);
                A_logo->start(QPropertyAnimation::DeleteWhenStopped);
                A_loginbtn->start(QPropertyAnimation::DeleteWhenStopped);
                A_quitbtn->start(QPropertyAnimation::DeleteWhenStopped);
                A_sidepanel->start(QPropertyAnimation::DeleteWhenStopped);
                A_quitbtn2->start(QPropertyAnimation::DeleteWhenStopped);
                A_welcome->start(QPropertyAnimation::DeleteWhenStopped);
                A_gesevent->start(QPropertyAnimation::DeleteWhenStopped);
                A_scroll->start(QPropertyAnimation::DeleteWhenStopped);

                if(!db.superuser){
                    Gemployee->setOverlayColor("red");

                }else{
                    connect(Gemployee,SIGNAL(clicked()),this,SLOT(onemployeeclicked()),Qt::UniqueConnection);
                }
    }else{
                loginwarning->addMessage("Invalid username or password");
                loginwarning->setTextColor("red");
                loginwarning->setBoxWidth(400);
                loginwarning->setGeometry(QRect(210,430,430,70));
                loginwarning->setBackgroundColor("black");
                loginwarning->show();}


}

void MainWindow::quitclicked(){
    close();
}
void MainWindow::onwelcomeclicked(){
    stack->setCurrentIndex(0);
}
void MainWindow::onparkingclicked(){
    stack->setCurrentIndex(1);
}
void MainWindow::gesproduitclicked(){
    stack->setCurrentIndex(2);

}
void MainWindow::onreservationclicked(){
    stack->setCurrentIndex(3);
}
void MainWindow::oneventclicked(){
    stack->setCurrentIndex(4);
}
void MainWindow::onmovieclicked(){
    stack->setCurrentIndex(5);
}

void MainWindow::ongessalleclicked(){
    stack->setCurrentIndex(6);
}
void MainWindow::onsubscribeclicked(){
    stack->setCurrentIndex(7);
}
void MainWindow::onabonnementclicked(){
    stack->setCurrentIndex(8);
}
void MainWindow::onemployeeclicked(){
    stack->setCurrentIndex(9);
}
void MainWindow::onprofilclicked(){
    stack->setCurrentIndex(10);
}
void MainWindow::seepassword(){
    if(seepw->isChecked()){
    passwordtext->setEchoMode(QLineEdit::Normal);
   }
    else{
    passwordtext->setEchoMode(QLineEdit::Password);
    }
}

void MainWindow::addwidget(QWidget *widget){
    stack->addWidget(widget);
}
MainWindow::~MainWindow()
{
    delete ui;
}

