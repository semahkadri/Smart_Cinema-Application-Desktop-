#ifndef GESPRODUIT_H
#define GESPRODUIT_H
#include "qtmaterialraisedbutton.h"
#include "qtmaterialtextfield.h"
#include "qtmaterialsnackbar.h"
#include <QWidget>
#include <QTableWidget>
#include <QSqlQueryModel>
#include <QGraphicsEffect>
#include <QTableView>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include "statistics.h"
#include <QPropertyAnimation>
#include <QHeaderView>
#include "database.h"
class Gesproduit : public QWidget
{
    Q_OBJECT
public:
    explicit Gesproduit(QWidget *parent = nullptr);
private:
    Database tempdb;
    Statistics *stats;
    void opendrawer();
    bool vol;
private slots:
    void showstats();
    void onmodifypvclicked();
    void pvmodified();
    void ondeletepvclicked();
    void deletepv();
    void onprintclicked();
    void onaddclicked();
    void ondeleteclicked();
    void onmodifyclicked();
    void addproduct();
    void productmodified();
    void deleted();
    void closeadd();
    void onaddpvclicked();
    void addpv();
    void setpvente(int);

public:
    int  pvslot = 0;

    QPropertyAnimation *A_customdrawer,*A_transbg;
    QtMaterialSnackbar *selectwarning;
    QtMaterialRaisedButton *addbtn,*statbtn,*addbtn2,*addbtn3,*addpvbtn,*addpvbtn2,*modifypvbtn,*modifypvbtn2,*deletepvbtn,*deletepvbtn2,*cancelbtn,*deletebtn,*deletebtn2,*modifybtn, *print1pdf;
    QTableWidget *producttable;
    QLabel *pvtext;
    QtMaterialTextField *txttype,*txtid,*txtname,*txtquantity,*txtvalid,*txtpvname,*txtpvid;
    QWidget* gproduit,*pointvente,*tablewidget,*transparentbg,*customdrawer;
signals:

};

#endif // GESPRODUIT_H
