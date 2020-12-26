#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QThread>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)

{
    ui->setupUi(this);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }
       QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(on_pushButton_connect_clicked()));
    this->setWindowTitle("INTERFACE PRINCIPALE");

   /*QPixmap pix("C:/Users/WSI/Desktop/projet/b.jpg");
    ui->label->setPixmap(pix);*/

}



login::~login()
{
    delete ui;
}
/*
void login::on_pushButton_connect_clicked()
{
    data1= A.read_from_arduino();

    if      (data1=="5")
    {
           QMessageBox::information(this,"LOGIN","WELCOME");
          this->hide();
          MainWindow *newmain=new MainWindow();
          newmain->show();
    }
    else if (data1=="0")
          QMessageBox::information(this,"LOGIN","WELCOME");
}
*/
void login::on_pushButton_connect_clicked()
{
  data1= A.read_from_arduino();

        QString username = ui->lineEditusername->text();
         QString password = ui->lineEditpassword->text();

         if(username == "" && password=="")
         {

             QMessageBox::information(this,"LOGIN","WELCOME");
             this->hide();
             MainWindow *newmain=new MainWindow();
             newmain->show();
         }
/*
         else if (data1 != "5" )
         {

               QMessageBox::warning(this,"LOGIN","CONNECTION FAILED");

         }*/
}

void login::on_pushButton_2_clicked()
{
    close();
}


