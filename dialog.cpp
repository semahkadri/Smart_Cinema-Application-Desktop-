#include "dialog.h"
#include "ui_dialog.h"
#include "mailing/SmtpMime"
#include <QMessageBox>
#include <QApplication>
#include "mainwindow.h"
#include "mailing/SmtpMime"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_envoyer_clicked()
{
    MainWindow w;

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);




    smtp.setUser("semahkadriii@gmail.com");
    smtp.setPassword("sam1997.");



    MimeMessage message;

    message.setSender(new EmailAddress("semahkadriii@gmail.com", "Semah KADRI"));
    message.addRecipient(new EmailAddress(ui->lineEdit_adresse->text(), "kadri semah"));
    message.setSubject(ui->lineEdit_objet->text());



    MimeText text;

    text.setText(ui->textEdit_texte->toPlainText());



    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    if (smtp.sendMail(message)){
        QMessageBox::information(this, "OK", "email envoyé");
    }
    else{
        QMessageBox::critical(this, "Erreur","email non envoyé");
    }
    smtp.quit();
}
