#include "login.h"
#include "ui_login.h"
#include <QMessageBox>


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    son = new QSound("::/music.wav");
    son->play();
    animation = new QPropertyAnimation(ui->pushButton_3,"geometry");
    animation->setDuration(30000);
    animation->setStartValue(ui->pushButton_3->geometry());
    animation->setEndValue(QRectF(600,600,45,30));

    QEasingCurve curve;
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);

    animation->start();
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString username=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    if(username =="semah"&& password=="esprit")
    {QMessageBox::information(this,"login","Login correct");
        hide();
       emit sig();
    }
    else {
        QMessageBox::warning(this,"login","username or password incorrect");
    }
}
