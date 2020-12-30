#include "gesevenement.h"

gesevenement::gesevenement(QWidget *parent) : QWidget(parent)
{
    Gr = new QWidget(this);
    Gr->setGeometry(QRect(0,0,600,480));
    Gr->setStyleSheet("background-color: #696969");

    addbtn = new QtMaterialRaisedButton(this);
    addbtn->setText("Add Event");
    addbtn->setGeometry(QRect(10,20,120,30));
    addbtn->setHaloVisible(false);

    deletebtn = new QtMaterialRaisedButton(this);
    deletebtn->setText("Remove Event");
    deletebtn->setGeometry(QRect(10,70,120,30));
    deletebtn->setHaloVisible(false);

    modifybtn = new QtMaterialRaisedButton(this);
    modifybtn->setText("Modify Event");
    modifybtn->setGeometry(QRect(10,120,120,30));
    modifybtn->setHaloVisible(false);

    searchbtn = new QtMaterialRaisedButton(this);
    searchbtn->setText("Search Event");
    searchbtn->setGeometry(QRect(10,170,120,30));
    searchbtn->setHaloVisible(false);

    printpdf = new QtMaterialRaisedButton(this);
    printpdf->setText("Print");
    printpdf->setGeometry(QRect(10,220,120,30));
    printpdf->setHaloVisible(false);

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

    tempdb.evtable = new QTableWidget(1,5,tablewidget);
    tempdb.evtable->setColumnWidth(0,50);
    tempdb.evtable->setColumnWidth(1,70);
    tempdb.evtable->setColumnWidth(3,80);
    tempdb.evtable->setStyleSheet("background:transparent");
    tempdb.evtable->setGeometry(0,10,400,400);
    tempdb.evtable->verticalHeader()->setVisible(false);
    tempdb.evtable->setHorizontalHeaderLabels(QStringList() << "ID " << "Room ID" << "Event Name" << "Event type" <<"Time");
    tempdb.evtable->setStyleSheet("background-color: transparent");
    QHeaderView* header = tempdb.evtable->horizontalHeader();
    header->setStretchLastSection(true);
    tempdb.evtable->setSortingEnabled(false);
    tempdb.showeventtable();
    tempdb.evtable->setSortingEnabled(true);

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

    txtidevent = new QtMaterialTextField(customdrawer);
    txtidevent->setTextColor("black");
    txtidevent->setInkColor("black");
    txtidevent->setLabelColor("red");
    txtidevent->setLabel("Event ID");
    txtidevent->setGeometry(QRect(50,0,250,60));
    txtidevent->setVisible(false);

    txteventname  = new QtMaterialTextField(customdrawer);
    txteventname->setTextColor("black");
    txteventname->setInkColor("black");
    txteventname->setLabel("Event Name");
    txteventname->setGeometry(QRect(50,70,250,60));
    txteventname->setVisible(false);

    txteventtype  = new QtMaterialTextField(customdrawer);
    txteventtype->setTextColor("black");
    txteventtype->setInkColor("black");
    txteventtype->setLabel("Event Type");
    txteventtype->setGeometry(QRect(50,140,250,60));
    txteventtype->setVisible(false);

    txtidroom  = new QtMaterialTextField(customdrawer);
    txtidroom->setTextColor("black");
    txtidroom->setInkColor("black");
    txtidroom->setLabel("Room ID");
    txtidroom->setGeometry(QRect(50,210,250,60));
    txtidroom->setVisible(false);


    selectwarning = new QtMaterialSnackbar(tablewidget);

    connect(returnbtn,SIGNAL(clicked()),this,SLOT(show()), Qt::UniqueConnection);
    connect(searchbtn,SIGNAL(clicked()),this,SLOT(onsearchclicked()), Qt::UniqueConnection);
    connect(addbtn,SIGNAL(clicked()), this, SLOT(onaddclicked()), Qt::UniqueConnection);
    connect(cancelbtn,SIGNAL(clicked()),this,SLOT(closeadd()), Qt::UniqueConnection);
    connect(modifybtn,SIGNAL(clicked()),this,SLOT(onmodifyclicked()), Qt::UniqueConnection);
    connect(deletebtn,SIGNAL(clicked()),this,SLOT(ondeleteclicked()), Qt::UniqueConnection);
    connect(printpdf,SIGNAL(clicked()),this,SLOT(onprintclicked()), Qt::UniqueConnection);
}
void gesevenement::onprintclicked(){
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFileName("evenements.pdf");

    QTextDocument doc;

    QString text("<table><thead>");
    text.append("<tr>");
    for (int i = 0; i < tempdb.evtable->columnCount(); i++) {
        text.append("<th>").append(tempdb.evtable->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < tempdb.evtable->rowCount(); i++) {
        text.append("<tr>");
        for (int j = 0; j < tempdb.evtable->columnCount(); j++) {
            QTableWidgetItem *item = tempdb.evtable->item(i, j);
            if (!item || item->text().isEmpty()) {
                tempdb.evtable->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(tempdb.evtable->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
}
void gesevenement::ondeleteclicked(){
    opendrawer();
    cancelbtn->setVisible(true);
    deletebtn2->setVisible(true);
    txtidevent->setVisible(true);
    txtidevent->setEnabled(true);
    connect(deletebtn2,SIGNAL(clicked()),this,SLOT(deleted()), Qt::UniqueConnection);
}
void gesevenement::deleted(){
    tempdb.evtable->setSortingEnabled(false);
    if(!(tempdb.deleteevent(txtidevent->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Event deleted successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    tempdb.showeventtable();
    tempdb.evtable->setSortingEnabled(true);
    closeadd();
}
void gesevenement::show(){
    tempdb.evtable->setSortingEnabled(false);
    tempdb.showeventtable();
    tempdb.evtable->setSortingEnabled(true);
    returnbtn->setVisible(false);
}
void gesevenement::opendrawer(){
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
void gesevenement::closeadd(){
    addbtn2->setVisible(false);
    modifybtn2->setVisible(false);
    deletebtn2->setVisible(false);
    searchbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtidevent->setVisible(false);
    txteventtype->setVisible(false);
    txtidroom->setVisible(false);
    txteventname->setVisible(false);

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
void gesevenement::onaddclicked(){
    opendrawer();
    addbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txteventname->setVisible(true);
    txteventtype->setVisible(true);
    txtidevent->setVisible(true);
    txtidroom->setVisible(true);
    txtidevent->setEnabled(false);
    connect(addbtn2,SIGNAL(clicked()),this,SLOT(added()), Qt::UniqueConnection);
}
void gesevenement::added(){
    tempdb.evtable->setSortingEnabled(false);
    tempdb.addevent(txtidroom->text().toInt(),txteventname->text(),txteventtype->text(),time.currentDateTime());
    tempdb.showeventtable();
    tempdb.evtable->setSortingEnabled(true);
    closeadd();
}
void gesevenement::onmodifyclicked(){
    opendrawer();
    modifybtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txteventname->setVisible(true);
    txteventtype->setVisible(true);
    txtidevent->setVisible(true);
    txtidroom->setVisible(true);
    txtidevent->setEnabled(true);
    connect(modifybtn2,SIGNAL(clicked()),this,SLOT(modified()), Qt::UniqueConnection);
}
void gesevenement::modified(){
    tempdb.evtable->setSortingEnabled(false);
    if(!(tempdb.modifyevent(txtidevent->text().toInt(),txtidroom->text().toInt(),txteventname->text(),txteventtype->text(),time.currentDateTime()))){
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
    tempdb.showeventtable();
    tempdb.evtable->setSortingEnabled(true);
    closeadd();
}
void gesevenement::onsearchclicked(){
    opendrawer();
    searchbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtidevent->setVisible(true);
    txtidevent->setEnabled(true);
    connect(searchbtn2,SIGNAL(clicked()),this,SLOT(searched()), Qt::UniqueConnection);
}
void gesevenement::searched(){
   // tempdb.restable->clear();
    returnbtn->setVisible(true);
    if(!(tempdb.searchevent(txtidevent->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Event found successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    closeadd();
}
