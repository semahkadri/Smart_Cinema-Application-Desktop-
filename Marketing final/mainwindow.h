#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSound>
#include "evenement.h"
#include "reservation.h"
#include <QMainWindow>
#include <QWidget>
#include "secdialog.h"
#include <QPrinter>
#include <QTranslator>
#include <QSqlTableModel>
#include <tableprinter.h>
#include <connection.h>
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void afficher();
    void afficher2();

private slots:

    void on_pushButton_clicked();
    void on_actionSon_triggered();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_modifier_3_clicked();

    void on_ajouter_event_clicked();

    void on_modifier_2_clicked();

    void on_supprimer_2_clicked();

    void on_pushButton_trie_clicked();

    void print2(QPrinter *printer);
    void print_two_tables2(QPrinter *printer);
    void uglyPrint2(QPrinter *printer);
    void print(QPrinter *printer);
    void print_two_tables(QPrinter *printer);
    void uglyPrint(QPrinter *printer);

    void on_pushButton_imprimer_2_clicked();

    void on_pushButton_imprimer_3_clicked();

    void on_pushButton_imprimer_4_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_ajouter_res_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_pushButton_imprimer_10_clicked();

    void on_pushButton_imprimer_9_clicked();

    void on_pushButton_imprimer_8_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_stat_clicked();
  //  void update_label();


    void on_lineEdit_nom_event_textEdited(const QString &arg1);

    void on_tableRes_activated(const QModelIndex &index);

    void on_tableEvent_activated(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    QSound *son;
    evenement tmpevenement;
    SecDialog *secDialog;
    reservation tmpreservation;
    QSqlTableModel *model;
    QByteArray data;
    Arduino A;
};
#endif // MAINWINDOW_H
