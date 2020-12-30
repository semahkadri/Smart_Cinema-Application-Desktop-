#ifndef GESPROFIL_H
#define GESPROFIL_H

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

class gesprofil : public QWidget
{
    Q_OBJECT
public:
    explicit gesprofil(QWidget *parent = nullptr);
private:
    QPropertyAnimation *A_customdrawer,*A_transbg;
    Database tempdb;
    QWidget *Gf,*tablewidget,*transparentbg,*customdrawer;
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
protected:
    QtMaterialSnackbar *selectwarning;
    QtMaterialTextField *txtid,*txtprofil,*txtpost;
    QDateTime time;
    QtMaterialRaisedButton *addbtn,*cancelbtn,*deletebtn,*modifybtn,*deletebtn2,*searchbtn,*searchbtn2,*returnbtn, *printpdf,*addbtn2,*modifybtn2;
signals:

};

#endif // GESPROFIL_H
