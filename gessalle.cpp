#include "gessalle.h"

gessalle::gessalle(QWidget *parent) : QWidget(parent)
{
    Gr = new QWidget(this);
    Gr->setGeometry(QRect(0,0,600,480));
    Gr->setStyleSheet("background-color: #696969");

    addbtn = new QtMaterialRaisedButton(this);
    addbtn->setText("Add room");
    addbtn->setGeometry(QRect(10,20,120,30));
    addbtn->setHaloVisible(false);

    deletebtn = new QtMaterialRaisedButton(this);
    deletebtn->setText("Remove room");
    deletebtn->setGeometry(QRect(10,70,120,30));
    deletebtn->setHaloVisible(false);

    modifybtn = new QtMaterialRaisedButton(this);
    modifybtn->setText("Modify room");
    modifybtn->setGeometry(QRect(10,120,120,30));
    modifybtn->setHaloVisible(false);

    searchbtn = new QtMaterialRaisedButton(this);
    searchbtn->setText("Search room");
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

    tempdb.roomtable = new QTableWidget(1,4,tablewidget);
    tempdb.roomtable->setColumnWidth(0,50);
    tempdb.roomtable->setColumnWidth(1,70);
    tempdb.roomtable->setColumnWidth(3,80);
    tempdb.roomtable->setStyleSheet("background:transparent");
    tempdb.roomtable->setGeometry(0,10,400,400);
    tempdb.roomtable->verticalHeader()->setVisible(false);
    tempdb.roomtable->setHorizontalHeaderLabels(QStringList() << "ID " << "Chair Size" << "Chair count" << "Chair quality");
    tempdb.roomtable->setStyleSheet("background-color: transparent");
    QHeaderView* header = tempdb.roomtable->horizontalHeader();
    header->setStretchLastSection(true);
    tempdb.roomtable->setSortingEnabled(false);
    tempdb.showroomtable();
    tempdb.roomtable->setSortingEnabled(true);
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

    txtidroom = new QtMaterialTextField(customdrawer);
    txtidroom->setTextColor("black");
    txtidroom->setInkColor("black");
    txtidroom->setLabelColor("red");
    txtidroom->setLabel("Room ID");
    txtidroom->setGeometry(QRect(50,0,250,60));
    txtidroom->setVisible(false);

    txtchaircount  = new QtMaterialTextField(customdrawer);
    txtchaircount->setTextColor("black");
    txtchaircount->setInkColor("black");
    txtchaircount->setLabel("Chair count");
    txtchaircount->setGeometry(QRect(50,70,250,60));
    txtchaircount->setVisible(false);

    txtchairquality  = new QtMaterialTextField(customdrawer);
    txtchairquality->setTextColor("black");
    txtchairquality->setInkColor("black");
    txtchairquality->setLabel("Chair quality");
    txtchairquality->setGeometry(QRect(50,140,250,60));
    txtchairquality->setVisible(false);

    txtchairsize  = new QtMaterialTextField(customdrawer);
    txtchairsize->setTextColor("black");
    txtchairsize->setInkColor("black");
    txtchairsize->setLabel("Chair size");
    txtchairsize->setGeometry(QRect(50,210,250,60));
    txtchairsize->setVisible(false);


    selectwarning = new QtMaterialSnackbar(tablewidget);

    connect(returnbtn,SIGNAL(clicked()),this,SLOT(show()), Qt::UniqueConnection);
    connect(searchbtn,SIGNAL(clicked()),this,SLOT(onsearchclicked()), Qt::UniqueConnection);
    connect(addbtn,SIGNAL(clicked()), this, SLOT(onaddclicked()), Qt::UniqueConnection);
    connect(cancelbtn,SIGNAL(clicked()),this,SLOT(closeadd()), Qt::UniqueConnection);
    connect(modifybtn,SIGNAL(clicked()),this,SLOT(onmodifyclicked()), Qt::UniqueConnection);
    connect(deletebtn,SIGNAL(clicked()),this,SLOT(ondeleteclicked()), Qt::UniqueConnection);
    connect(printpdf,SIGNAL(clicked()),this,SLOT(onprintclicked()), Qt::UniqueConnection);
}
void gessalle::ondeleteclicked(){
    opendrawer();
    cancelbtn->setVisible(true);
    deletebtn2->setVisible(true);
    txtidroom->setVisible(true);
    txtidroom->setEnabled(true);
    connect(deletebtn2,SIGNAL(clicked()),this,SLOT(deleted()), Qt::UniqueConnection);
}
void gessalle::deleted(){
    tempdb.roomtable->setSortingEnabled(false);
    if(!(tempdb.deleteroom(txtidroom->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Room deleted successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    tempdb.showroomtable();
    tempdb.roomtable->setSortingEnabled(true);
    closeadd();
}
void gessalle::show(){
    tempdb.roomtable->setSortingEnabled(false);
    tempdb.showroomtable();
    tempdb.roomtable->setSortingEnabled(true);
    returnbtn->setVisible(false);
}
void gessalle::opendrawer(){
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
void gessalle::closeadd(){
    addbtn2->setVisible(false);
    modifybtn2->setVisible(false);
    deletebtn2->setVisible(false);
    searchbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtchaircount->setVisible(false);
    txtchairquality->setVisible(false);
    txtchairsize->setVisible(false);
    txtidroom->setVisible(false);

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
void gessalle::onaddclicked(){
    opendrawer();
    addbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtchaircount->setVisible(true);
    txtchairquality->setVisible(true);
    txtchairsize->setVisible(true);
    txtidroom->setVisible(true);
    txtidroom->setEnabled(false);
    connect(addbtn2,SIGNAL(clicked()),this,SLOT(added()), Qt::UniqueConnection);
}
void gessalle::added(){
    tempdb.roomtable->setSortingEnabled(false);
    tempdb.addroom(txtchairsize->text(),txtchairquality->text(),txtchaircount->text());
    tempdb.showroomtable();
    tempdb.roomtable->setSortingEnabled(true);
    closeadd();
}
void gessalle::onmodifyclicked(){
    opendrawer();
    modifybtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtchaircount->setVisible(true);
    txtchairquality->setVisible(true);
    txtidroom->setVisible(true);
    txtchairsize->setVisible(true);
    txtidroom->setEnabled(true);
    connect(modifybtn2,SIGNAL(clicked()),this,SLOT(modified()), Qt::UniqueConnection);
}
void gessalle::modified(){
    tempdb.roomtable->setSortingEnabled(false);
    if(!(tempdb.modifyroom(txtidroom->text().toInt(),txtchairsize->text(),txtchairquality->text(),txtchaircount->text()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Room modified successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    tempdb.showroomtable();
    tempdb.roomtable->setSortingEnabled(true);
    closeadd();
}
void gessalle::onsearchclicked(){
    opendrawer();
    searchbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtidroom->setVisible(true);
    txtidroom->setEnabled(true);
    connect(searchbtn2,SIGNAL(clicked()),this,SLOT(searched()), Qt::UniqueConnection);
}
void gessalle::searched(){
   // tempdb.restable->clear();
    returnbtn->setVisible(true);
    if(!(tempdb.searchroom(txtidroom->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Room found successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    closeadd();
}
void gessalle::onprintclicked(){
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFileName("movies.pdf");

    QTextDocument doc;

    QString text("<table><thead>");
    text.append("<tr>");
    for (int i = 0; i < tempdb.roomtable->columnCount(); i++) {
        text.append("<th>").append(tempdb.roomtable->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < tempdb.roomtable->rowCount(); i++) {
        text.append("<tr>");
        for (int j = 0; j < tempdb.roomtable->columnCount(); j++) {
            QTableWidgetItem *item = tempdb.roomtable->item(i, j);
            if (!item || item->text().isEmpty()) {
                tempdb.roomtable->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(tempdb.roomtable->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
}
