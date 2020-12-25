#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QThread>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_connect_clicked()
{

        QString username = ui->lineEditusername->text();
         QString password = ui->lineEditpassword->text();
         if(username == "" && password =="")
         {

             QMessageBox::information(this,"LOGIN","WELCOME");
             this->hide();
             MainWindow *newmain=new MainWindow();
             newmain->show();
         }
         else
         {

               QMessageBox::warning(this,"LOGIN","CONNECTION FAILED");

         }
}

void login::on_pushButton_2_clicked()
{
    close();
}
