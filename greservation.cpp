#include "greservation.h"
#include "secdialog.h"

greservation::greservation(QWidget *parent) : QWidget(parent)
{
    Gr = new QWidget(this);
    Gr->setGeometry(QRect(0,0,600,480));
    Gr->setStyleSheet("background-color: #696969");

    addbtn = new QtMaterialRaisedButton(this);
    addbtn->setText("Add Reserv");
    addbtn->setGeometry(QRect(10,20,120,30));
    addbtn->setHaloVisible(false);

    deletebtn = new QtMaterialRaisedButton(this);
    deletebtn->setText("Remove Reserv");
    deletebtn->setGeometry(QRect(10,70,120,30));
    deletebtn->setHaloVisible(false);

    modifybtn = new QtMaterialRaisedButton(this);
    modifybtn->setText("Modify Reserv");
    modifybtn->setGeometry(QRect(10,120,120,30));
    modifybtn->setHaloVisible(false);

    searchbtn = new QtMaterialRaisedButton(this);
    searchbtn->setText("Search Reserv");
    searchbtn->setGeometry(QRect(10,170,120,30));
    searchbtn->setHaloVisible(false);

    printpdf = new QtMaterialRaisedButton(this);
    printpdf->setText("Print");
    printpdf->setGeometry(QRect(10,220,120,30));
    printpdf->setHaloVisible(false);

    statbtn = new QtMaterialRaisedButton(this);
    statbtn->setText("Stats");
    statbtn->setGeometry(QRect(10,270,120,30));
    statbtn->setHaloVisible(false);

    mail = new QtMaterialRaisedButton(this);
    mail->setText("mail");
    mail->setGeometry(QRect(10,320,120,30));
    mail->setHaloVisible(false);

    returnbtn = new QtMaterialRaisedButton(this);
    returnbtn->setText("Return");
    returnbtn->setGeometry(QRect(10,220,120,30));
    returnbtn->setBackgroundColor("darkred");
    returnbtn->setHaloVisible(false);
    returnbtn->setVisible(false);

    tablewidget = new QWidget(this);
    tablewidget->setGeometry(160,20,400,410);
    tablewidget->setStyleSheet("background-color: white;"
                               "border-radius: 10px");

    transparentbg = new QWidget(this);
    transparentbg->setGeometry(QRect(-500,0,500,600));
    transparentbg->setStyleSheet("background-color: rgba(0, 0, 0, 0.75);"
                                 "border-radius: 0px;");

    customdrawer = new QWidget(this);
    customdrawer->setGeometry(QRect(-300,0,300,600));
    customdrawer->setStyleSheet("background-color: white;"
                                "border-radius: 0px;");

    tempdb.restable = new QTableWidget(1,5,tablewidget);
    tempdb.restable->setColumnWidth(0,50);
    tempdb.restable->setColumnWidth(1,70);
    tempdb.restable->setColumnWidth(3,80);
    tempdb.restable->setStyleSheet("background:transparent");
    tempdb.restable->setGeometry(0,10,400,400);
    tempdb.restable->verticalHeader()->setVisible(false);
    tempdb.restable->setHorizontalHeaderLabels(QStringList() << "ID Res" << "ID Film" << "ID Evenement" << "N°Places" <<"Date Res");
    tempdb.restable->setStyleSheet("background-color: transparent");
    QHeaderView* header = tempdb.restable->horizontalHeader();
    header->setStretchLastSection(true);
    tempdb.restable->setSortingEnabled(false);
    tempdb.showrestable();
    tempdb.restable->setSortingEnabled(true);

    addbtn2 = new QtMaterialRaisedButton(customdrawer);
    addbtn2->setText("Add");
    addbtn2->setHaloVisible(false);
    addbtn2->setGeometry(QRect(45,420,120,30));
    addbtn2->setVisible(false);

    searchbtn2 = new QtMaterialRaisedButton(customdrawer);
    searchbtn2->setText("Search");
    searchbtn2->setHaloVisible(false);
    searchbtn2->setGeometry(QRect(45,420,120,30));
    searchbtn2->setVisible(false);

    modifybtn2 = new QtMaterialRaisedButton(customdrawer);
    modifybtn2->setText("Modify");
    modifybtn2->setHaloVisible(false);
    modifybtn2->setGeometry(QRect(45,420,120,30));
    modifybtn2->setVisible(false);

    deletebtn2 = new QtMaterialRaisedButton(customdrawer);
    deletebtn2->setText("Delete");
    deletebtn2->setHaloVisible(false);
    deletebtn2->setGeometry(QRect(45,420,120,30));
    deletebtn2->setVisible(false);

    cancelbtn = new QtMaterialRaisedButton(customdrawer);
    cancelbtn->setText("Cancel");
    cancelbtn->setHaloVisible(false);
    cancelbtn->setGeometry(QRect(175,420,120,30));
    cancelbtn->setVisible(false);

    txtidres = new QtMaterialTextField(customdrawer);
    txtidres->setTextColor("black");
    txtidres->setInkColor("black");
    txtidres->setLabelColor("red");
    txtidres->setLabel("Reservation ID");
    txtidres->setGeometry(QRect(50,0,250,60));
    txtidres->setVisible(false);

    txtidfilm  = new QtMaterialTextField(customdrawer);
    txtidfilm->setTextColor("black");
    txtidfilm->setInkColor("black");
    txtidfilm->setLabel("Film ID");
    txtidfilm->setGeometry(QRect(50,70,250,60));
    txtidfilm->setVisible(false);

    txtidevent  = new QtMaterialTextField(customdrawer);
    txtidevent->setTextColor("black");
    txtidevent->setInkColor("black");
    txtidevent->setLabel("Event ID");
    txtidevent->setGeometry(QRect(50,140,250,60));
    txtidevent->setVisible(false);

    txtdateres  = new QtMaterialTextField(customdrawer);
    txtdateres->setTextColor("black");
    txtdateres->setInkColor("black");
    txtdateres->setLabel("Reservation date");
    txtdateres->setGeometry(QRect(50,210,250,60));
    txtdateres->setVisible(false);

    txtnmbplace  = new QtMaterialTextField(customdrawer);
    txtnmbplace->setTextColor("black");
    txtnmbplace->setInkColor("black");
    txtnmbplace->setLabel("Place Numbers");
    txtnmbplace->setGeometry(QRect(50,280,250,60));
    txtnmbplace->setVisible(false);

    selectwarning = new QtMaterialSnackbar(tablewidget);

    connect(returnbtn,SIGNAL(clicked()),this,SLOT(show()), Qt::UniqueConnection);
    connect(searchbtn,SIGNAL(clicked()),this,SLOT(onsearchclicked()), Qt::UniqueConnection);
    connect(addbtn,SIGNAL(clicked()), this, SLOT(onaddclicked()), Qt::UniqueConnection);
    connect(cancelbtn,SIGNAL(clicked()),this,SLOT(closeadd()), Qt::UniqueConnection);
    connect(modifybtn,SIGNAL(clicked()),this,SLOT(onmodifyclicked()), Qt::UniqueConnection);
    connect(deletebtn,SIGNAL(clicked()),this,SLOT(ondeleteclicked()), Qt::UniqueConnection);
    connect(printpdf,SIGNAL(clicked()),this,SLOT(onprintclicked()), Qt::UniqueConnection);
    connect(statbtn,SIGNAL(clicked()),this,SLOT(onstatclicked()), Qt::UniqueConnection);
    connect(mail,SIGNAL(clicked()),this,SLOT(onmailclicked()), Qt::UniqueConnection);


}

void greservation::onmailclicked(){
    Dialog d;
    d.exec();
}
void greservation::onstatclicked(){
    sec = new SecDialog(this);
    sec ->show();
}
void greservation::show(){
    tempdb.restable->setSortingEnabled(false);
    tempdb.showrestable();
    tempdb.restable->setSortingEnabled(true);
    returnbtn->setVisible(false);
}
void greservation::opendrawer(){
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
void greservation::ondeleteclicked(){
    opendrawer();
    cancelbtn->setVisible(true);
    deletebtn2->setVisible(true);
    txtidres->setVisible(true);
    connect(deletebtn2,SIGNAL(clicked()),this,SLOT(deleted()), Qt::UniqueConnection);
}
void greservation::onsearchclicked(){
    opendrawer();
    searchbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtidres->setVisible(true);
    txtidres->setEnabled(true);
    connect(searchbtn2,SIGNAL(clicked()),this,SLOT(searched()), Qt::UniqueConnection);
}
void greservation::searched(){
   // tempdb.restable->clear();
    returnbtn->setVisible(true);
    if(!(tempdb.searchres(txtidres->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Reservation found successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    closeadd();
}
void greservation::deleted(){
    tempdb.restable->setSortingEnabled(false);
    if(!(tempdb.deleteres(txtidres->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Reservation deleted successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    tempdb.showrestable();
    tempdb.restable->setSortingEnabled(true);
    closeadd();
}
void greservation::onprintclicked(){
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFileName("reservation.pdf");

    QTextDocument doc;

    QString text("<table><thead>");
    text.append("<tr>");
    for (int i = 0; i < tempdb.restable->columnCount(); i++) {
        text.append("<th>").append(tempdb.restable->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < tempdb.restable->rowCount(); i++) {
        text.append("<tr>");
        for (int j = 0; j < tempdb.restable->columnCount(); j++) {
            QTableWidgetItem *item = tempdb.restable->item(i, j);
            if (!item || item->text().isEmpty()) {
                tempdb.restable->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(tempdb.restable->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
}
void greservation::onaddclicked(){
    opendrawer();
    addbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtnmbplace->setVisible(true);
    txtdateres->setVisible(true);
    txtidres->setVisible(true);
    txtidres->setEnabled(false);
    txtidfilm->setVisible(true);
    txtidevent->setVisible(true);
    connect(addbtn2,SIGNAL(clicked()),this,SLOT(added()), Qt::UniqueConnection);
}
void greservation::onmodifyclicked(){
    opendrawer();
    modifybtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtnmbplace->setVisible(true);
    txtdateres->setVisible(true);
    txtidres->setVisible(true);
    txtidres->setEnabled(true);
    txtidfilm->setVisible(true);
    txtidevent->setVisible(true);
    connect(modifybtn2,SIGNAL(clicked()),this,SLOT(modified()), Qt::UniqueConnection);
}
void greservation::modified(){
    tempdb.restable->setSortingEnabled(false);
    if(!(tempdb.modifyres(txtidres->text().toInt(),txtidfilm->text().toInt(),txtidevent->text().toInt(),txtnmbplace->text(),txtdateres->text()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Reservation modified successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    tempdb.showrestable();
    tempdb.restable->setSortingEnabled(true);
    closeadd();
}
void greservation::added(){
    tempdb.restable->setSortingEnabled(false);
    if(tempdb.addreservation(txtidfilm->text().toInt(),txtidevent->text().toInt(),txtnmbplace->text(),txtdateres->text()))
    {A.write_to_arduino("1");
    tempdb.showrestable();}
    else{A.write_to_arduino("2");}
    tempdb.restable->setSortingEnabled(true);
    closeadd();
}
void greservation::closeadd(){
    addbtn2->setVisible(false);
    modifybtn2->setVisible(false);
    deletebtn2->setVisible(false);
    searchbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtnmbplace->setVisible(false);
    txtdateres->setVisible(false);
    txtidres->setVisible(false);
    txtidfilm->setVisible(false);
    txtidevent->setVisible(false);
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
