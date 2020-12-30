#include "gsubscribers.h"

gsubscribers::gsubscribers(QWidget *parent) : QWidget(parent)
{
    Gs = new QWidget(this);
    Gs->setGeometry(QRect(0,0,600,480));
    Gs->setStyleSheet("background-color: #696969");

    addbtn = new QtMaterialRaisedButton(this);
    addbtn->setText("Add Movie");
    addbtn->setGeometry(QRect(10,20,120,30));
    addbtn->setHaloVisible(false);

    deletebtn = new QtMaterialRaisedButton(this);
    deletebtn->setText("Remove movie");
    deletebtn->setGeometry(QRect(10,70,120,30));
    deletebtn->setHaloVisible(false);

    modifybtn = new QtMaterialRaisedButton(this);
    modifybtn->setText("Modify movie");
    modifybtn->setGeometry(QRect(10,120,120,30));
    modifybtn->setHaloVisible(false);

    searchbtn = new QtMaterialRaisedButton(this);
    searchbtn->setText("Search movie");
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

    tempdb.subtable = new QTableWidget(1,4,tablewidget);
    tempdb.subtable->setColumnWidth(0,50);
    tempdb.subtable->setColumnWidth(1,70);
    tempdb.subtable->setColumnWidth(3,80);
    tempdb.subtable->setStyleSheet("background:transparent");
    tempdb.subtable->setGeometry(0,10,400,400);
    tempdb.subtable->verticalHeader()->setVisible(false);
    tempdb.subtable->setHorizontalHeaderLabels(QStringList() << "ID " << "First Name" << "Last Name" << "Email");
    tempdb.subtable->setStyleSheet("background-color: transparent");
    QHeaderView* header = tempdb.subtable->horizontalHeader();
    header->setStretchLastSection(true);
    tempdb.subtable->setSortingEnabled(false);
    tempdb.showsubtable();
    tempdb.subtable->setSortingEnabled(true);
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

    txtsubid = new QtMaterialTextField(customdrawer);
    txtsubid->setTextColor("black");
    txtsubid->setInkColor("black");
    txtsubid->setLabelColor("red");
    txtsubid->setLabel("subscriber ID");
    txtsubid->setGeometry(QRect(50,0,250,60));
    txtsubid->setVisible(false);

    txtsubname  = new QtMaterialTextField(customdrawer);
    txtsubname->setTextColor("black");
    txtsubname->setInkColor("black");
    txtsubname->setLabel("First Name");
    txtsubname->setGeometry(QRect(50,70,250,60));
    txtsubname->setVisible(false);

    txtsubfname  = new QtMaterialTextField(customdrawer);
    txtsubfname->setTextColor("black");
    txtsubfname->setInkColor("black");
    txtsubfname->setLabel("Family Name");
    txtsubfname->setGeometry(QRect(50,140,250,60));
    txtsubfname->setVisible(false);

    txtsubemail  = new QtMaterialTextField(customdrawer);
    txtsubemail->setTextColor("black");
    txtsubemail->setInkColor("black");
    txtsubemail->setLabel("Email");
    txtsubemail->setGeometry(QRect(50,210,250,60));
    txtsubemail->setVisible(false);



    selectwarning = new QtMaterialSnackbar(tablewidget);

    connect(returnbtn,SIGNAL(clicked()),this,SLOT(show()), Qt::UniqueConnection);
    connect(searchbtn,SIGNAL(clicked()),this,SLOT(onsearchclicked()), Qt::UniqueConnection);
    connect(addbtn,SIGNAL(clicked()), this, SLOT(onaddclicked()), Qt::UniqueConnection);
    connect(cancelbtn,SIGNAL(clicked()),this,SLOT(closeadd()), Qt::UniqueConnection);
    connect(modifybtn,SIGNAL(clicked()),this,SLOT(onmodifyclicked()), Qt::UniqueConnection);
    connect(deletebtn,SIGNAL(clicked()),this,SLOT(ondeleteclicked()), Qt::UniqueConnection);
    connect(printpdf,SIGNAL(clicked()),this,SLOT(onprintclicked()), Qt::UniqueConnection);
}
void gsubscribers::ondeleteclicked(){
    opendrawer();
    cancelbtn->setVisible(true);
    deletebtn2->setVisible(true);
    txtsubid->setVisible(true);
    txtsubid->setEnabled(true);
    connect(deletebtn2,SIGNAL(clicked()),this,SLOT(deleted()), Qt::UniqueConnection);
}
void gsubscribers::deleted(){
    tempdb.subtable->setSortingEnabled(false);
    if(!(tempdb.deletesub(txtsubid->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Subscriber deleted successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    tempdb.showsubtable();
    tempdb.subtable->setSortingEnabled(true);
    closeadd();
}
void gsubscribers::show(){
    tempdb.subtable->setSortingEnabled(false);
    tempdb.showsubtable();
    tempdb.subtable->setSortingEnabled(true);
    returnbtn->setVisible(false);
}
void gsubscribers::opendrawer(){
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
void gsubscribers::closeadd(){
    addbtn2->setVisible(false);
    modifybtn2->setVisible(false);
    deletebtn2->setVisible(false);
    searchbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtsubid->setVisible(false);
    txtsubname->setVisible(false);
    txtsubfname->setVisible(false);
    txtsubemail->setVisible(false);


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
void gsubscribers::onaddclicked(){
    opendrawer();
    addbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtsubid->setVisible(true);
    txtsubfname->setVisible(true);
    txtsubemail->setVisible(true);
    txtsubname->setVisible(true);
    txtsubid->setEnabled(false);
    connect(addbtn2,SIGNAL(clicked()),this,SLOT(added()), Qt::UniqueConnection);
}
void gsubscribers::added(){
    tempdb.subtable->setSortingEnabled(false);
    tempdb.addsubscriber(txtsubname->text(),txtsubfname->text(),txtsubemail->text());
    tempdb.showsubtable();
    tempdb.subtable->setSortingEnabled(true);
    closeadd();
}
void gsubscribers::onmodifyclicked(){
    opendrawer();
    modifybtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtsubemail->setVisible(true);
    txtsubfname->setVisible(true);
    txtsubname->setVisible(true);
    txtsubid->setVisible(true);
    txtsubid->setEnabled(true);
    connect(modifybtn2,SIGNAL(clicked()),this,SLOT(modified()), Qt::UniqueConnection);
}
void gsubscribers::modified(){
    tempdb.subtable->setSortingEnabled(false);
    if(!(tempdb.modifysub(txtsubid->text().toInt(),txtsubname->text(),txtsubfname->text(),txtsubemail->text()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Subscriber modified successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    tempdb.showsubtable();
    tempdb.subtable->setSortingEnabled(true);
    closeadd();
}
void gsubscribers::onsearchclicked(){
    opendrawer();
    searchbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtsubid->setVisible(true);
    txtsubid->setEnabled(true);
    connect(searchbtn2,SIGNAL(clicked()),this,SLOT(searched()), Qt::UniqueConnection);
}
void gsubscribers::searched(){
   // tempdb.restable->clear();
    returnbtn->setVisible(true);
    if(!(tempdb.searchsub(txtsubid->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Subscriber found successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    closeadd();
}
void gsubscribers::onprintclicked(){
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFileName("movies.pdf");

    QTextDocument doc;

    QString text("<table><thead>");
    text.append("<tr>");
    for (int i = 0; i < tempdb.subtable->columnCount(); i++) {
        text.append("<th>").append(tempdb.subtable->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < tempdb.subtable->rowCount(); i++) {
        text.append("<tr>");
        for (int j = 0; j < tempdb.subtable->columnCount(); j++) {
            QTableWidgetItem *item = tempdb.subtable->item(i, j);
            if (!item || item->text().isEmpty()) {
                tempdb.subtable->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(tempdb.subtable->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
}
