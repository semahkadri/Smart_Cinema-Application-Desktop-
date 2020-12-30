#ifndef GESEMPLOYEE_H
#define GESEMPLOYEE_H

#include "qtmaterialraisedbutton.h"
#include "qtmaterialtextfield.h"
#include "database.h"
#include "qtmaterialsnackbar.h"
#include <QWidget>
#include <QTableWidget>
#include <QGraphicsEffect>
#include <QPropertyAnimation>
#include <QHeaderView>
#include "dialog.h"
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>

class gesemployee : public QWidget
{
    Q_OBJECT
public:
    explicit gesemployee(QWidget *parent = nullptr);
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
    void onmailclicked();
    void onprintclicked();
    void closeadd();
private:
    QPropertyAnimation *A_customdrawer,*A_transbg;
    Database tempdb;
    Dialog *d;
    QWidget *Ge,*tablewidget,*transparentbg,*customdrawer;
protected:
    QtMaterialSnackbar *selectwarning;
    QtMaterialTextField *txtid,*txtfirstname,*txtlastname,*txtemail,*txtusername,*txtpassword;
    QDateTime time;
    QtMaterialRaisedButton *addbtn,*cancelbtn,*deletebtn,*mail,*modifybtn,*deletebtn2,*searchbtn,*searchbtn2,*returnbtn, *printpdf,*addbtn2,*modifybtn2;
signals:

};

#endif // GESEMPLOYEE_H
