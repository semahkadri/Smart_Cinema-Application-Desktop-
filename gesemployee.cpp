#include "gesemployee.h"

gesemployee::gesemployee(QWidget *parent) : QWidget(parent)
{
    Ge = new QWidget(this);
    Ge->setGeometry(QRect(0,0,600,480));
    Ge->setStyleSheet("background-color: #696969");

    addbtn = new QtMaterialRaisedButton(this);
    addbtn->setText("Add Employee");
    addbtn->setGeometry(QRect(10,20,120,30));
    addbtn->setHaloVisible(false);

    deletebtn = new QtMaterialRaisedButton(this);
    deletebtn->setText("Remove Employee");
    deletebtn->setGeometry(QRect(10,70,120,30));
    deletebtn->setHaloVisible(false);

    modifybtn = new QtMaterialRaisedButton(this);
    modifybtn->setText("Modify Employee");
    modifybtn->setGeometry(QRect(10,120,120,30));
    modifybtn->setHaloVisible(false);

    searchbtn = new QtMaterialRaisedButton(this);
    searchbtn->setText("Search ");
    searchbtn->setGeometry(QRect(10,170,120,30));
    searchbtn->setHaloVisible(false);

    printpdf = new QtMaterialRaisedButton(this);
    printpdf->setText("Print");
    printpdf->setGeometry(QRect(10,220,120,30));
    printpdf->setHaloVisible(false);

    mail = new QtMaterialRaisedButton(this);
    mail->setText("mail");
    mail->setGeometry(QRect(10,270,120,30));
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

    tempdb.employeetable = new QTableWidget(1,6,tablewidget);
    tempdb.employeetable->setColumnWidth(0,50);
    tempdb.employeetable->setColumnWidth(1,70);
    tempdb.employeetable->setColumnWidth(3,80);
    tempdb.employeetable->setStyleSheet("background:transparent");
    tempdb.employeetable->setGeometry(0,10,400,400);
    tempdb.employeetable->verticalHeader()->setVisible(false);
    tempdb.employeetable->setHorizontalHeaderLabels(QStringList() << "ID " << "Name" << "Last Name" << "Email" <<"Username" <<"Password");
    tempdb.employeetable->setStyleSheet("background-color: transparent");
    QHeaderView* header = tempdb.employeetable->horizontalHeader();
    header->setStretchLastSection(true);
    tempdb.employeetable->setSortingEnabled(false);
    tempdb.showemployeetable();
    tempdb.employeetable->setSortingEnabled(true);

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

    txtid = new QtMaterialTextField(customdrawer);
    txtid->setTextColor("black");
    txtid->setInkColor("black");
    txtid->setLabelColor("red");
    txtid->setLabel("ID");
    txtid->setGeometry(QRect(50,0,250,60));
    txtid->setVisible(false);

    txtfirstname  = new QtMaterialTextField(customdrawer);
    txtfirstname->setTextColor("black");
    txtfirstname->setInkColor("black");
    txtfirstname->setLabel("First Name");
    txtfirstname->setGeometry(QRect(50,70,250,60));
    txtfirstname->setVisible(false);

    txtlastname  = new QtMaterialTextField(customdrawer);
    txtlastname->setTextColor("black");
    txtlastname->setInkColor("black");
    txtlastname->setLabel("Last Name");
    txtlastname->setGeometry(QRect(50,140,250,60));
    txtlastname->setVisible(false);

    txtemail  = new QtMaterialTextField(customdrawer);
    txtemail->setTextColor("black");
    txtemail->setInkColor("black");
    txtemail->setLabel("Email");
    txtemail->setGeometry(QRect(50,210,250,60));
    txtemail->setVisible(false);

    txtusername  = new QtMaterialTextField(customdrawer);
    txtusername->setTextColor("black");
    txtusername->setInkColor("black");
    txtusername->setLabel("Username");
    txtusername->setGeometry(QRect(50,280,250,60));
    txtusername->setVisible(false);

    txtpassword  = new QtMaterialTextField(customdrawer);
    txtpassword->setTextColor("black");
    txtpassword->setInkColor("black");
    txtpassword->setLabel("Password");
    txtpassword->setGeometry(QRect(50,350,250,60));
    txtpassword->setVisible(false);

    selectwarning = new QtMaterialSnackbar(tablewidget);

    connect(returnbtn,SIGNAL(clicked()),this,SLOT(show()), Qt::UniqueConnection);
    connect(searchbtn,SIGNAL(clicked()),this,SLOT(onsearchclicked()), Qt::UniqueConnection);
    connect(addbtn,SIGNAL(clicked()), this, SLOT(onaddclicked()), Qt::UniqueConnection);
    connect(cancelbtn,SIGNAL(clicked()),this,SLOT(closeadd()), Qt::UniqueConnection);
    connect(modifybtn,SIGNAL(clicked()),this,SLOT(onmodifyclicked()), Qt::UniqueConnection);
    connect(deletebtn,SIGNAL(clicked()),this,SLOT(ondeleteclicked()), Qt::UniqueConnection);
    connect(printpdf,SIGNAL(clicked()),this,SLOT(onprintclicked()), Qt::UniqueConnection);
    connect(mail,SIGNAL(clicked()),this,SLOT(onmailclicked()), Qt::UniqueConnection);
}
void gesemployee::ondeleteclicked(){
    opendrawer();
    cancelbtn->setVisible(true);
    deletebtn2->setVisible(true);
    txtid->setVisible(true);
    txtid->setEnabled(true);
    connect(deletebtn2,SIGNAL(clicked()),this,SLOT(deleted()), Qt::UniqueConnection);
}
void gesemployee::onmailclicked(){
    Dialog d;
    d.exec();
}
void gesemployee::deleted(){
    tempdb.employeetable->setSortingEnabled(false);
    if(!(tempdb.deleteemployee(txtid->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Employee deleted successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    tempdb.showemployeetable();
    tempdb.employeetable->setSortingEnabled(true);
    closeadd();
}
void gesemployee::show(){
    tempdb.employeetable->setSortingEnabled(false);
    tempdb.showemployeetable();
    tempdb.employeetable->setSortingEnabled(true);
    returnbtn->setVisible(false);
}
void gesemployee::opendrawer(){
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
void gesemployee::closeadd(){
    addbtn2->setVisible(false);
    modifybtn2->setVisible(false);
    deletebtn2->setVisible(false);
    searchbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtid->setVisible(false);
    txtemail->setVisible(false);
    txtfirstname->setVisible(false);
    txtlastname->setVisible(false);
    txtusername->setVisible(false);
    txtpassword->setVisible(false);

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
void gesemployee::onaddclicked(){
    opendrawer();
    addbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtemail->setVisible(true);
    txtfirstname->setVisible(true);
    txtlastname->setVisible(true);
    txtpassword->setVisible(true);
    txtusername->setVisible(true);
    txtid->setVisible(true);
    txtid->setEnabled(false);
    connect(addbtn2,SIGNAL(clicked()),this,SLOT(added()), Qt::UniqueConnection);
}
void gesemployee::added(){
    tempdb.employeetable->setSortingEnabled(false);
    tempdb.addemployee(txtfirstname->text(),txtlastname->text(),txtemail->text(),txtusername->text(),txtpassword->text());
    tempdb.showemployeetable();
    tempdb.employeetable->setSortingEnabled(true);
    closeadd();
}
void gesemployee::onmodifyclicked(){
    opendrawer();
    modifybtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtemail->setVisible(true);
    txtfirstname->setVisible(true);
    txtlastname->setVisible(true);
    txtusername->setVisible(true);
    txtpassword->setVisible(true);
    txtid->setVisible(true);
    txtid->setEnabled(true);
    connect(modifybtn2,SIGNAL(clicked()),this,SLOT(modified()), Qt::UniqueConnection);
}
void gesemployee::modified(){
    tempdb.employeetable->setSortingEnabled(false);
    if(!(tempdb.modifyemployee(txtid->text().toInt(),txtfirstname->text(),txtlastname->text(),txtemail->text(),txtusername->text(),txtpassword->text()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Employee modified successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    tempdb.showemployeetable();
    tempdb.employeetable->setSortingEnabled(true);
    closeadd();
}
void gesemployee::onsearchclicked(){
    opendrawer();
    searchbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtid->setVisible(true);
    txtid->setEnabled(true);
    connect(searchbtn2,SIGNAL(clicked()),this,SLOT(searched()), Qt::UniqueConnection);
}
void gesemployee::searched(){
   // tempdb.restable->clear();
    returnbtn->setVisible(true);
    if(!(tempdb.searchemployee(txtid->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Employee found successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    closeadd();
}
void gesemployee::onprintclicked(){
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFileName("movies.pdf");

    QTextDocument doc;

    QString text("<table><thead>");
    text.append("<tr>");
    for (int i = 0; i < tempdb.employeetable->columnCount(); i++) {
        text.append("<th>").append(tempdb.employeetable->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < tempdb.employeetable->rowCount(); i++) {
        text.append("<tr>");
        for (int j = 0; j < tempdb.employeetable->columnCount(); j++) {
            QTableWidgetItem *item = tempdb.employeetable->item(i, j);
            if (!item || item->text().isEmpty()) {
                tempdb.employeetable->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(tempdb.employeetable->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
}
