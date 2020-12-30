#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPropertyAnimation>
#include <QStackedWidget>
#include <QGraphicsEffect>
#include "qtmaterialraisedbutton.h"
#include "qtmaterialtextfield.h"
#include "qtmaterialsnackbar.h"
#include "qtmaterialradiobutton.h"
#include "database.h"
#include <QLabel>
#include <qradiobutton.h>
#include <QPixmap>
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
    void addwidget(QWidget*);
    bool scrolled;

private slots:
    void loginclicked();
    void quitclicked();
    void hidebuttons();
    void gesproduitclicked();
    void onwelcomeclicked();
    void oneventclicked();
    void onparkingclicked();

    void onreservationclicked();
    void onmovieclicked();
    void seepassword();
    void onscrollclicked();
    void ongessalleclicked();
    void onsubscribeclicked();
    void onabonnementclicked();
    void onemployeeclicked();
    void onprofilclicked();
protected:
    Database db;
    Arduino A;
    Ui::MainWindow *ui;
    QLabel *cinemapp;
    QStackedWidget *stack;
    QtMaterialSnackbar *loginwarning;
    QRadioButton *seepw;
    QWidget *bigpanel,*sidepanel;
    QPushButton *scroll;
    QtMaterialRaisedButton *loginbtn,*Greservation,*Gemployee,*gabonnement,*gsubscribe,*quitbtn,*quitbtn2,*groom,*Gproduit,*Gevent,*Gparking,*Gprofil,*welcomebtn,*gmovie;
    QtMaterialTextField *textfield,*logintext,*passwordtext;
};
#endif // MAINWINDOW_H
