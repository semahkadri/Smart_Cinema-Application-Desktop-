#ifndef GESPARKING_H
#define GESPARKING_H
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
class Gesparking : public QWidget
{
    Q_OBJECT
public:
    explicit Gesparking(QWidget *parent = nullptr);
private slots:
    void onprintclicked();
    void onaddclicked();
    void parkingadded();
    void onmodifyclicked();
    void modified();
    void ondeleteclicked();
    void deleted();
    void closeadd();
    void openadd();
protected:
    Database tempdb;
    QtMaterialSnackbar *selectwarning;
    QtMaterialRaisedButton *addbtn,*addbtn2,*cancelbtn,*deletebtn,*deletebtn2,*modifybtn2,*modifybtn, *printpdf;
    QTableWidget *parkingtable;
    QtMaterialTextField *txtspot,*txtcarowner,*txtlicense,*parkingid;
    QWidget* gparking,*tablewidget,*transparentbg,*customdrawer;
signals:

};

#endif // GESPARKING_H
