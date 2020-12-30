#ifndef GESEVENEMENT_H
#define GESEVENEMENT_H

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
#include <QTextDocument>
class gesevenement : public QWidget
{
    Q_OBJECT
public:
    explicit gesevenement(QWidget *parent = nullptr);
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
    QtMaterialTextField *txtidevent,*txteventname,*txteventtype,*txtidroom;
    QDateTime time;
    QtMaterialRaisedButton *addbtn,*cancelbtn,*deletebtn,*modifybtn,*deletebtn2,*searchbtn,*searchbtn2,*returnbtn, *printpdf,*addbtn2,*modifybtn2;

signals:

};

#endif // GESEVENEMENT_H
