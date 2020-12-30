#ifndef GRESERVATION_H
#define GRESERVATION_H

#include <QWidget>
#include "qtmaterialraisedbutton.h"
#include "qtmaterialtextfield.h"
#include "database.h"
#include "qtmaterialsnackbar.h"
#include <QWidget>
#include <QTableWidget>
#include <QGraphicsEffect>
#include <QPropertyAnimation>
#include <QHeaderView>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include "secdialog.h"
#include "dialog.h"
#include "arduino.h"
#include <QTextDocument>
class greservation : public QWidget
{
    Q_OBJECT
public:
    explicit greservation(QWidget *parent = nullptr);
private slots:
    void opendrawer();
    void onaddclicked();
    void added();
    void onmodifyclicked();
    void modified();
    void ondeleteclicked();
    void onsearchclicked();
    void searched();
    void show();
    void deleted();
    void onprintclicked();
    void onstatclicked();
    void closeadd();
    void onmailclicked();
private:
    QPropertyAnimation *A_customdrawer,*A_transbg;
    SecDialog *sec;
    Dialog *d;
    Arduino A;

    Database tempdb;
    QWidget *Gr,*tablewidget,*transparentbg,*customdrawer;
protected:
    QtMaterialSnackbar *selectwarning;
    QtMaterialTextField *txtidres,*txtidfilm,*txtidevent,*txtnmbplace,*txtdateres;
    QtMaterialRaisedButton *addbtn,*mail,*cancelbtn,*deletebtn,*modifybtn,*deletebtn2,*statbtn,*searchbtn,*searchbtn2,*returnbtn, *printpdf,*addbtn2,*modifybtn2;
signals:

};

#endif // GRESERVATION_H
