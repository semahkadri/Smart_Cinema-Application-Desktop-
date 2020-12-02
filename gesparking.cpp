#include "gesparking.h"
#include <QDebug>
Gesparking::Gesparking(QWidget *parent) : QWidget(parent)
{

    gparking = new QWidget(this);
    gparking->setGeometry(QRect(0,0,600,480));
    gparking->setStyleSheet("background-color: #696969");

    addbtn = new QtMaterialRaisedButton(this);
    addbtn->setText("Add Car");
    addbtn->setGeometry(QRect(10,20,100,30));
    addbtn->setHaloVisible(false);

    deletebtn = new QtMaterialRaisedButton(this);
    deletebtn->setText("Remove Car");
    deletebtn->setGeometry(QRect(10,70,100,30));
    deletebtn->setHaloVisible(false);

    modifybtn = new QtMaterialRaisedButton(this);
    modifybtn->setText("Modify Spot");
    modifybtn->setGeometry(QRect(10,120,100,30));
    modifybtn->setHaloVisible(false);

    printpdf = new QtMaterialRaisedButton(this);
    printpdf->setText("Print");
    printpdf->setGeometry(QRect(10,170,100,30));
    printpdf->setHaloVisible(false);

    tablewidget = new QWidget(this);
    tablewidget->setGeometry(160,20,400,410);
    tablewidget->setStyleSheet("background-color: white;"
                               "border-radius: 10px");

    tempdb.ptable = new QTableWidget(1,5,tablewidget);
    tempdb.ptable->setColumnWidth(0,30);
    tempdb.ptable->setColumnWidth(3,80);
    tempdb.ptable->setStyleSheet("background:transparent");
    tempdb.ptable->setGeometry(0,10,447,400);
    tempdb.ptable->verticalHeader()->setVisible(false);
    tempdb.ptable->setHorizontalHeaderLabels(QStringList() << "ID" << "Spot N°" << "State" << "Car Owner" <<"License");
    tempdb.ptable->setStyleSheet("background-color: transparent");
    tempdb.showparkingtable();

    transparentbg = new QWidget(this);
    transparentbg->setGeometry(QRect(-500,0,500,600));
    transparentbg->setStyleSheet("background-color: rgba(0, 0, 0, 0.75);"
                                 "border-radius: 0px;");

    customdrawer = new QWidget(this);
    customdrawer->setGeometry(QRect(-300,0,300,600));
    customdrawer->setStyleSheet("background-color: white;"
                                "border-radius: 0px;");

    addbtn2 = new QtMaterialRaisedButton(customdrawer);
    addbtn2->setText("Add");
    addbtn2->setHaloVisible(false);
    addbtn2->setGeometry(QRect(45,420,120,30));

    deletebtn2 = new QtMaterialRaisedButton(customdrawer);
    deletebtn2->setText("Delete");
    deletebtn2->setHaloVisible(false);
    deletebtn2->setGeometry(QRect(45,420,120,30));

    cancelbtn = new QtMaterialRaisedButton(customdrawer);
    cancelbtn->setText("Cancel");
    cancelbtn->setHaloVisible(false);
    cancelbtn->setGeometry(QRect(175,420,120,30));

    modifybtn2 = new QtMaterialRaisedButton(customdrawer);
    modifybtn2->setText("Modify");
    modifybtn2->setHaloVisible(false);
    modifybtn2->setGeometry(QRect(45,420,120,30));


    txtcarowner = new QtMaterialTextField(customdrawer);
    txtcarowner->setTextColor("black");
    txtcarowner->setInkColor("black");
    txtcarowner->setLabel("Car owner");
    txtcarowner->setGeometry(QRect(50,140,250,60));

    txtlicense = new QtMaterialTextField(customdrawer);
    txtlicense->setTextColor("black");
    txtlicense->setInkColor("black");
    txtlicense->setLabel("License plate");
    txtlicense->setGeometry(QRect(50,210,250,60));

    parkingid = new QtMaterialTextField(customdrawer);
    parkingid->setTextColor("black");
    parkingid->setInkColor("black");
    parkingid->setLabelColor("red");
    parkingid->setLabel("Product ID");
    parkingid->setGeometry(QRect(50,0,250,60));

    txtspot = new QtMaterialTextField(customdrawer);
    txtspot->setTextColor("black");
    txtspot->setInkColor("black");
    txtspot->setLabel("Car spot:");
    txtspot->setGeometry(QRect(50,70,250,60));

    selectwarning = new QtMaterialSnackbar(tablewidget);
    addbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtcarowner->setVisible(false);
    txtlicense->setVisible(false);
    txtspot->setVisible(false);
    parkingid->setVisible(false);
    deletebtn2->setVisible(false);
    modifybtn2->setVisible(false);

    connect(modifybtn, SIGNAL(clicked()),this,SLOT(onmodifyclicked()),Qt::UniqueConnection);
    connect(deletebtn, SIGNAL(clicked()), this, SLOT(ondeleteclicked()),Qt::UniqueConnection);
    connect(addbtn, SIGNAL(clicked()),this, SLOT(onaddclicked()),Qt::UniqueConnection);
    connect(printpdf,SIGNAL(clicked()),this,SLOT(onprintclicked()),Qt::UniqueConnection);
    connect(cancelbtn, SIGNAL(clicked()),this, SLOT(closeadd()),Qt::UniqueConnection);
}

void Gesparking::onprintclicked(){

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFileName("parking.pdf");

    QTextDocument doc;

    QString text("<table><thead>");
    text.append("<tr>");
    for (int i = 0; i < tempdb.ptable->columnCount(); i++) {
        text.append("<th>").append(tempdb.ptable->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < tempdb.ptable->rowCount(); i++) {
        text.append("<tr>");
        for (int j = 0; j < tempdb.ptable->columnCount(); j++) {
            QTableWidgetItem *item = tempdb.ptable->item(i, j);
            if (!item || item->text().isEmpty()) {
                tempdb.ptable->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(tempdb.ptable->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
    }

void Gesparking::openadd(){
    QPropertyAnimation *A_customdrawer,*A_transbg;
    A_customdrawer = new QPropertyAnimation(customdrawer,"geometry");
    A_customdrawer->setStartValue(customdrawer->geometry());
    A_customdrawer->setEndValue(QRect(-53,0,300,600));
    A_customdrawer->setDuration(200);
    A_customdrawer->setEasingCurve(QEasingCurve::InOutQuint);
    A_customdrawer->start(QPropertyAnimation::DeleteWhenStopped);
    A_transbg = new QPropertyAnimation(transparentbg,"geometry");
    A_transbg->setStartValue(transparentbg->geometry());
    A_transbg->setEndValue(QRect(100,0,500,600));
    A_transbg->setDuration(100);
    A_transbg->setEasingCurve(QEasingCurve::InOutQuint);
    A_transbg->start(QPropertyAnimation::DeleteWhenStopped);
}
void Gesparking::onaddclicked(){
    addbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtcarowner->setVisible(true);
    txtlicense->setVisible(true);
    txtspot->setVisible(true);
    openadd();
    connect(addbtn2,SIGNAL(clicked()),this,SLOT(parkingadded()),Qt::UniqueConnection);
}
void Gesparking::parkingadded(){
    tempdb.addparking(txtspot->text(),txtcarowner->text(),txtlicense->text());
    tempdb.showparkingtable();
    closeadd();
}
void Gesparking::closeadd(){
    addbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtcarowner->setVisible(false);
    txtlicense->setVisible(false);
    txtspot->setVisible(false);
    parkingid->setVisible(false);
    deletebtn2->setVisible(false);
    modifybtn2->setVisible(false);
    QPropertyAnimation *A_customdrawer,*A_transbg;
    A_customdrawer = new QPropertyAnimation(customdrawer,"geometry");
    A_customdrawer->setStartValue(QRect(-53,0,300,600));
    A_customdrawer->setEndValue(QRect(-300,0,300,600));
    A_customdrawer->setDuration(200);
    A_customdrawer->setEasingCurve(QEasingCurve::InOutQuint);
    A_customdrawer->start(QPropertyAnimation::DeleteWhenStopped);
    A_transbg = new QPropertyAnimation(transparentbg,"geometry");
    A_transbg->setStartValue(QRect(100,0,500,600));
    A_transbg->setEndValue(QRect(-500,0,500,600));
    A_transbg->setDuration(100);
    A_transbg->setEasingCurve(QEasingCurve::InOutQuint);
    A_transbg->start(QPropertyAnimation::DeleteWhenStopped);
}
void Gesparking::onmodifyclicked(){

    parkingid->setVisible(true);
    cancelbtn->setVisible(true);
    txtcarowner->setVisible(true);
    txtlicense->setVisible(true);
    txtspot->setVisible(true);
    modifybtn2->setVisible(true);
    openadd();
    connect(modifybtn2,SIGNAL(clicked()),this,SLOT(modified()),Qt::UniqueConnection);

}
void Gesparking::modified(){
    if(!tempdb.parkingmodified(parkingid->text().toInt(),txtspot->text(),txtcarowner->text(),txtlicense->text()))
        {
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Parking modified successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    closeadd();
    tempdb.showparkingtable();
}
void Gesparking::ondeleteclicked(){
    openadd();
    parkingid->setVisible(true);
    cancelbtn->setVisible(true);
    deletebtn2->setVisible(true);
    connect(deletebtn2,SIGNAL(clicked()),this,SLOT(deleted()),Qt::UniqueConnection);
}
void Gesparking::deleted(){
    if(!tempdb.deleteparking(parkingid->text().toInt()))
        {
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Parking deleted successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    closeadd();
    tempdb.showparkingtable();
}
