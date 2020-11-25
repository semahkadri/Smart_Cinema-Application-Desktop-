#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QMessageBox>
#include <QDialog>
#include <QPropertyAnimation>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include "connection.h"
#include "reservation.h"
#include <qcustomplot.h>
#include <QMessageBox>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "qcustomplot.h"
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include "secdialog.h"
#include<QDateTime>
#include<QDate>
#include <QRegExpValidator>
#define CARACTERES_ETRANGERS "~{}[]()|-`'^ç@_]\"°01234567890+=£$*µ/§!?,.&#;><"
#include<QIntValidator>
#include "tableprinter.h"
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    son=new QSound(":/music.wav");
    son->play();
    ui->tableEvent->setModel(tmpevenement.afficher());
    ui->tableRes->setModel(tmpreservation.afficher2());

    ui->stackedWidget->setCurrentIndex(1);
    ui->comboBox->addItem("Classic");
    ui->comboBox->addItem("Cosplay");
    ui->comboBox->addItem("Halloween");
    ui->comboBox->addItem("Reveillon");
    ui->comboBox->addItem("Show product");
    ui->comboBox->addItem("New film");

    ui->comboBox2->addItem("Classic");
    ui->comboBox2->addItem("Cosplay");
    ui->comboBox2->addItem("Halloween");
    ui->comboBox2->addItem("Reveillon");
    ui->comboBox2->addItem("Show product");
    ui->comboBox2->addItem("New film");


    ui->comboBox_3->addItem("1");
    ui->comboBox_3->addItem("2");
    ui->comboBox_3->addItem("3");
    ui->comboBox_3->addItem("4");
    ui->comboBox_3->addItem("5");

    ui->comboBox_4->addItem("1");
    ui->comboBox_4->addItem("2");
    ui->comboBox_4->addItem("3");
    ui->comboBox_4->addItem("4");
    ui->comboBox_4->addItem("5");


    model = new QSqlTableModel;
    model->select();

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    close();
}
void MainWindow::on_actionSon_triggered()

{

    son->play();

}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}

void MainWindow::on_modifier_3_clicked()
{

}

void MainWindow::afficher()
{

    Connection c;
    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(c.get_db());
    qry->prepare("SELECT* from evenement");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableEvent->setModel(modal);
}

void MainWindow::afficher2()
{

    Connection c;
    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(c.get_db());
    qry->prepare("SELECT* from reservation");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableRes->setModel(modal);
}

void MainWindow::on_ajouter_event_clicked()
{
    QString nom_event= ui->lineEdit_nom_event->text();
    int id_event = ui->lineEdit_id_event->text().toInt();
    int id_salle=ui->lineEdit_id_salle->text().toInt();
    QString type_event=ui->comboBox->currentText();
    QDateTime time=ui->dateEdit->dateTime();
    evenement e(id_event,nom_event,type_event,id_salle,time);

    bool test=e.ajouter();
    if(test)
    {

        ui->tableEvent->setModel(tmpevenement.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un evnement"),
                                 QObject::tr("evenement ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un evenement"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_modifier_2_clicked()
{
        QString nom_event= ui->lineEdit_nouv_nom->text();  //lineEdit_nouv_nom
        int id_event = ui->lineEdit_id_event->text().toInt(); //lineEdit_id_eventmodif
        int id_salle=ui->lineEdit_nouv_idsalle->text().toInt(); //lineEdit_nouv_idsalle
        QString type_event=ui->comboBox2->currentText(); //comboBox2
        QDateTime time=ui->dateEdit_4->dateTime();
        evenement e(id_event,nom_event,type_event,id_salle,time);
         bool test=e.modifier(id_event,nom_event,type_event,id_salle,time);
        if(test)
        {
            ui->tableEvent->setModel(tmpevenement.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Modifier un evenement !"),
                                     QObject::tr(" evenement modifiée ! \n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }

        else {

            QMessageBox::critical(nullptr, QObject::tr("Modifier un evenement"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

}


void MainWindow::on_supprimer_2_clicked()
{
    int id_event = ui->lineEdit_id_eventsupp->text().toInt();
    bool test = tmpevenement.supprimer(id_event);
    if (test)
    {
        ui->tableEvent->setModel(tmpevenement.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un evenement !"),
                                 QObject::tr(" evenement suprimé ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Suppimer un evenement"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_trie_clicked()
{
    bool test = true;
    if (test)
        {
            ui->tableEvent->setModel(tmpevenement.trier_id_event());
            QMessageBox::information(nullptr, QObject::tr("Trier evenement par id"),
                                     QObject::tr("evenement trié.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                         | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }

    else{
        QMessageBox::critical(nullptr, QObject::tr("Trier evenement par id"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


// ----------------- example of inharitance from PagePrepare ---------------------

class PrintBorder : public PagePrepare
{
public:
    virtual void preparePage(QPainter *painter);
    static int pageNumber;
};

int PrintBorder::pageNumber = 0;

void PrintBorder::preparePage(QPainter *painter)
{ // print a border on each page
    QRect rec = painter->viewport();
    painter->setPen(QPen(QColor(0, 0, 0), 1));
    painter->drawRect(rec);
    painter->translate(10, painter->viewport().height() - 10);
    painter->drawText(0, 0, QString("Page %1").arg(pageNumber));
    pageNumber += 1;
}

// --------------------------------------------------------------------------------




void MainWindow::print(QPrinter *printer) {

    // ------------------ simplest example Res --------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5 << 10 << 15;
    if(!tablePrinter.printTable(ui->tableRes->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}

void MainWindow::print2(QPrinter *printer) {

    // ------------------ simplest example Event--------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5 << 10 <<5 <<5;
    if(!tablePrinter.printTable(ui->tableEvent->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}

void MainWindow::print_two_tables(QPrinter *printer) {

    // ------------------ two tables example Res--------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5 << 10 << 15;
    if(!tablePrinter.printTable(ui->tableRes->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    // print second table
    painter.translate(0, 100);
    if(!tablePrinter.printTable(ui->tableRes->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}

void MainWindow::print_two_tables2(QPrinter *printer) {

    // ------------------ two tables example Event--------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5 << 10 <<5 <<2;
    if(!tablePrinter.printTable(ui->tableEvent->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    // print second table
    painter.translate(0, 100);
    if(!tablePrinter.printTable(ui->tableEvent->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}


void MainWindow::uglyPrint(QPrinter *printer) {

    // ---------------- death-to-designers example Res------------------

    QPainter uglyPainter;
    if(!uglyPainter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    TablePrinter uglyTablePrinter(&uglyPainter, printer);
    QVector<int> colStretch = QVector<int>() << 5 << 5 << 0 << 10 <<5;
    uglyTablePrinter.setPen(QPen(QColor(0, 100, 255), 3, Qt::DotLine)); // pen for borders
    uglyTablePrinter.setHeaderColor(Qt::red);
    uglyTablePrinter.setContentColor(Qt::green);
    QFont font1; // font for headers
    font1.setBold(true);
    QFont font2; // font for content
    font2.setItalic(true);
    uglyTablePrinter.setHeadersFont(font1);
    uglyTablePrinter.setContentFont(font2);
    PrintBorder *printB = new PrintBorder;
    printB->pageNumber = 1;
    uglyTablePrinter.setPagePrepare(printB);
    QVector<QString> headers = QVector<QString>() << "id_reservation" << "id_film" << "id_event2" << "nombre_place"<<"date_reservation";
    uglyPainter.setPen(QPen(Qt::yellow));
    uglyPainter.drawText(uglyPainter.viewport().width()/2 - 40, 40, "TABLE Reservation");
    uglyPainter.translate(0, 60); // start print point
    uglyTablePrinter.setCellMargin(10, 5, 5, 5);
    uglyTablePrinter.setPageMargin(100, 40, 40, 40);
    if(!uglyTablePrinter.printTable(ui->tableRes->model(), colStretch, headers)) {
        qDebug() << uglyTablePrinter.lastError();
    }
    uglyPainter.end();
    delete printB;
}
void MainWindow::uglyPrint2(QPrinter *printer) {

    // ---------------- death-to-designers example Event------------------

    QPainter uglyPainter;
    if(!uglyPainter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    TablePrinter uglyTablePrinter(&uglyPainter, printer);
    QVector<int> colStretch = QVector<int>() << 5 << 5 << 0 <<0 <<5;
    uglyTablePrinter.setPen(QPen(QColor(0, 100, 255), 3, Qt::DotLine)); // pen for borders
    uglyTablePrinter.setHeaderColor(Qt::red);
    uglyTablePrinter.setContentColor(Qt::green);
    QFont font1; // font for headers
    font1.setBold(true);
    QFont font2; // font for content
    font2.setItalic(true);
    uglyTablePrinter.setHeadersFont(font1);
    uglyTablePrinter.setContentFont(font2);
    PrintBorder *printB = new PrintBorder;
    printB->pageNumber = 1;
    uglyTablePrinter.setPagePrepare(printB);
    QVector<QString> headers = QVector<QString>() << "id_event" << "nom_event" << "type_event" << "id_salle"<< "time" ;

    uglyPainter.setPen(QPen(Qt::yellow));
    uglyPainter.drawText(uglyPainter.viewport().width()/2 - 40, 40, "TABLE EVENEMENT");
    uglyPainter.translate(0, 60); // start print point
    uglyTablePrinter.setCellMargin(10, 5, 5, 5);
    uglyTablePrinter.setPageMargin(100, 40, 40, 40);
    if(!uglyTablePrinter.printTable(ui->tableEvent->model(), colStretch, headers)) {
        qDebug() << uglyTablePrinter.lastError();
    }
    uglyPainter.end();
    delete printB;
}

void MainWindow::on_pushButton_imprimer_2_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print2(QPrinter*)));
    dialog.exec();
}

void MainWindow::on_pushButton_imprimer_3_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(uglyPrint2(QPrinter*)));
    dialog.exec();
}


void MainWindow::on_pushButton_imprimer_4_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print_two_tables2(QPrinter*)));
    dialog.exec();
}

void MainWindow::on_checkBox_clicked()
{
    bool test = true;
    if (test)
    {
        ui->tableEvent->setModel(tmpevenement.trier_id_event());

    }

    else{
        QMessageBox::critical(nullptr, QObject::tr("Trier par id"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."));
    }
}

void MainWindow::on_checkBox_2_clicked()
{
    bool test = true;
    if (test)
    {
        ui->tableEvent->setModel(tmpevenement.trier_time());

    }

    else{
        QMessageBox::critical(nullptr, QObject::tr("Trier par date"),
                              QObject::tr("Erreur !.\n"
                                          "Cli+++ck Cancel to exit."));
    }
}






void MainWindow::on_ajouter_res_clicked()
{
    int id_reservation = ui->lineEdit_id_res->text().toInt();
    int id_film=ui->lineEdit_id_film->text().toInt();
    int id_event2=ui->lineEdit_id_eventt->text().toInt();
    QString nombre_place=ui->comboBox_3->currentText();
    QDateTime date_reservation=ui->dateEdit_2->dateTime();
    reservation r(id_reservation,id_film,id_event2,nombre_place,date_reservation);

    bool test=r.ajouter2();
    if(test)
    {

        ui->tableRes->setModel(tmpreservation.afficher2());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter une réservation"),
                                 QObject::tr("Reservation ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une réservation"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_modifier_clicked()
{
    int id_reservation = ui->lineEdit_idmodif->text().toInt();//lineEdit_idmodif
    int id_film=ui->lineEdit_nouvfilm->text().toInt();//lineEdit_nouvfilm
    int id_event2=ui->lineEdit_id_eventmodif_2->text().toInt();//lineEdit_id_eventmodif_2
    QString nombre_place=ui->comboBox_4->currentText();//comboBox_4
    QDateTime date_reservation=ui->dateEdit_3->dateTime(); //dateEdit_3

    reservation r(id_reservation,id_film,id_event2,nombre_place,date_reservation);

    bool test=r.modifier2(id_reservation,id_film,id_event2,nombre_place,date_reservation);
    if(test)
    {
        ui->tableRes->setModel(tmpreservation.afficher2());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier une réservation !"),
                                 QObject::tr(" réservation modifiée ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else {

        QMessageBox::critical(nullptr, QObject::tr("Modifier une réservation !"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_supprimer_clicked()
{
    int id_reservation = ui->lineEdit_idsupp->text().toInt();
    bool test = tmpreservation.supprimer2(id_reservation);
    if (test)
    {
        ui->tableRes->setModel(tmpreservation.afficher2());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une réservation !"),
                                 QObject::tr(" réservation suprimé ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Suppimer une réservation !"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

void MainWindow::on_pushButton_imprimer_10_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print2(QPrinter*)));
    dialog.exec();
}

void MainWindow::on_pushButton_imprimer_9_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(uglyPrint2(QPrinter*)));
    dialog.exec();
}

void MainWindow::on_pushButton_imprimer_8_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print_two_tables2(QPrinter*)));
    dialog.exec();
}

void MainWindow::on_pushButton_rechercher_clicked()
{
    int id_reservation = ui->lineEdit_chercher->text().toInt();
    ui->tableRes->setModel(tmpreservation.chercher(id_reservation));
}

void MainWindow::on_pushButton_stat_clicked()
{

        //  SecDialog secDeialog;
        // secDeialog.setModal(true);
        //  secDeialog.exec();

        secDialog = new SecDialog(this);
        secDialog ->show();

}
