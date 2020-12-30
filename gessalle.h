#ifndef GESSALLE_H
#define GESSALLE_H

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
#include <QTextDocument>

class gessalle : public QWidget
{
    Q_OBJECT
public:
    explicit gessalle(QWidget *parent = nullptr);
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
    void closeadd();
private:
    QPropertyAnimation *A_customdrawer,*A_transbg;
    Database tempdb;
    QWidget *Gr,*tablewidget,*transparentbg,*customdrawer;
protected:
    QtMaterialSnackbar *selectwarning;
    QtMaterialTextField *txtidroom,*txtchaircount,*txtchairquality,*txtchairsize;
    QDateTime time;
    QtMaterialRaisedButton *addbtn,*cancelbtn,*deletebtn,*modifybtn,*deletebtn2,*searchbtn,*searchbtn2,*returnbtn, *printpdf,*addbtn2,*modifybtn2;
signals:
};

#endif // GESSALLE_H
