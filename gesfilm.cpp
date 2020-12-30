#include "gesfilm.h"

gesfilm::gesfilm(QWidget *parent) : QWidget(parent)
{
    Gf = new QWidget(this);
    Gf->setGeometry(QRect(0,0,600,480));
    Gf->setStyleSheet("background-color: #696969");

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

    tempdb.movtable = new QTableWidget(1,5,tablewidget);
    tempdb.movtable->setColumnWidth(0,50);
    tempdb.movtable->setColumnWidth(1,70);
    tempdb.movtable->setColumnWidth(3,80);
    tempdb.movtable->setStyleSheet("background:transparent");
    tempdb.movtable->setGeometry(0,10,400,400);
    tempdb.movtable->verticalHeader()->setVisible(false);
    tempdb.movtable->setHorizontalHeaderLabels(QStringList() << "ID " << "Movie Name" << "Type" << "Length" <<"Language");
    tempdb.movtable->setStyleSheet("background-color: transparent");
    QHeaderView* header = tempdb.movtable->horizontalHeader();
    header->setStretchLastSection(true);
    tempdb.movtable->setSortingEnabled(false);
    tempdb.showmovietable();
    tempdb.movtable->setSortingEnabled(true);

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

    txtidmovie = new QtMaterialTextField(customdrawer);
    txtidmovie->setTextColor("black");
    txtidmovie->setInkColor("black");
    txtidmovie->setLabelColor("red");
    txtidmovie->setLabel("movie ID");
    txtidmovie->setGeometry(QRect(50,0,250,60));
    txtidmovie->setVisible(false);

    txtmoviename  = new QtMaterialTextField(customdrawer);
    txtmoviename->setTextColor("black");
    txtmoviename->setInkColor("black");
    txtmoviename->setLabel("movie Name");
    txtmoviename->setGeometry(QRect(50,70,250,60));
    txtmoviename->setVisible(false);

    txtmovietype  = new QtMaterialTextField(customdrawer);
    txtmovietype->setTextColor("black");
    txtmovietype->setInkColor("black");
    txtmovietype->setLabel("Movie Type");
    txtmovietype->setGeometry(QRect(50,140,250,60));
    txtmovietype->setVisible(false);

    txtlang  = new QtMaterialTextField(customdrawer);
    txtlang->setTextColor("black");
    txtlang->setInkColor("black");
    txtlang->setLabel("language");
    txtlang->setGeometry(QRect(50,210,250,60));
    txtlang->setVisible(false);

    txtlength  = new QtMaterialTextField(customdrawer);
    txtlength->setTextColor("black");
    txtlength->setInkColor("black");
    txtlength->setLabel("length");
    txtlength->setGeometry(QRect(50,280,250,60));
    txtlength->setVisible(false);

    selectwarning = new QtMaterialSnackbar(tablewidget);

    connect(returnbtn,SIGNAL(clicked()),this,SLOT(show()), Qt::UniqueConnection);
    connect(searchbtn,SIGNAL(clicked()),this,SLOT(onsearchclicked()), Qt::UniqueConnection);
    connect(addbtn,SIGNAL(clicked()), this, SLOT(onaddclicked()), Qt::UniqueConnection);
    connect(cancelbtn,SIGNAL(clicked()),this,SLOT(closeadd()), Qt::UniqueConnection);
    connect(modifybtn,SIGNAL(clicked()),this,SLOT(onmodifyclicked()), Qt::UniqueConnection);
    connect(deletebtn,SIGNAL(clicked()),this,SLOT(ondeleteclicked()), Qt::UniqueConnection);
    connect(printpdf,SIGNAL(clicked()),this,SLOT(onprintclicked()), Qt::UniqueConnection);
}
void gesfilm::ondeleteclicked(){
    opendrawer();
    cancelbtn->setVisible(true);
    deletebtn2->setVisible(true);
    txtidmovie->setVisible(true);
    txtidmovie->setEnabled(true);
    connect(deletebtn2,SIGNAL(clicked()),this,SLOT(deleted()), Qt::UniqueConnection);
}
void gesfilm::deleted(){
    tempdb.movtable->setSortingEnabled(false);
    if(!(tempdb.deletemov(txtidmovie->text().toInt()))){
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
    tempdb.showmovietable();
    tempdb.movtable->setSortingEnabled(true);
    closeadd();
}
void gesfilm::show(){
    tempdb.movtable->setSortingEnabled(false);
    tempdb.showmovietable();
    tempdb.movtable->setSortingEnabled(true);
    returnbtn->setVisible(false);
}
void gesfilm::opendrawer(){
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
void gesfilm::closeadd(){
    addbtn2->setVisible(false);
    modifybtn2->setVisible(false);
    deletebtn2->setVisible(false);
    searchbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtidmovie->setVisible(false);
    txtlang->setVisible(false);
    txtlength->setVisible(false);
    txtmoviename->setVisible(false);
    txtmovietype->setVisible(false);

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
void gesfilm::onaddclicked(){
    opendrawer();
    addbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtmoviename->setVisible(true);
    txtlength->setVisible(true);
    txtlang->setVisible(true);
    txtmovietype->setVisible(true);
    txtidmovie->setVisible(true);
    txtidmovie->setEnabled(false);
    connect(addbtn2,SIGNAL(clicked()),this,SLOT(added()), Qt::UniqueConnection);
}
void gesfilm::added(){
    tempdb.movtable->setSortingEnabled(false);
    tempdb.addmovie(txtmoviename->text(),txtmovietype->text(),txtlength->text(),txtlang->text());
    tempdb.showmovietable();
    tempdb.movtable->setSortingEnabled(true);
    closeadd();
}
void gesfilm::onmodifyclicked(){
    opendrawer();
    modifybtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtmoviename->setVisible(true);
    txtmovietype->setVisible(true);
    txtlang->setVisible(true);
    txtlength->setVisible(true);
    txtidmovie->setVisible(true);
    txtidmovie->setEnabled(true);
    connect(modifybtn2,SIGNAL(clicked()),this,SLOT(modified()), Qt::UniqueConnection);
}
void gesfilm::modified(){
    tempdb.movtable->setSortingEnabled(false);
    if(!(tempdb.modifymovie(txtidmovie->text().toInt(),txtmoviename->text(),txtmovietype->text(),txtlength->text(),txtlang->text()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Movie modified successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    tempdb.showmovietable();
    tempdb.movtable->setSortingEnabled(true);
    closeadd();
}
void gesfilm::onsearchclicked(){
    opendrawer();
    searchbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtidmovie->setVisible(true);
    txtidmovie->setEnabled(true);
    connect(searchbtn2,SIGNAL(clicked()),this,SLOT(searched()), Qt::UniqueConnection);
}
void gesfilm::searched(){
   // tempdb.restable->clear();
    returnbtn->setVisible(true);
    if(!(tempdb.searchmov(txtidmovie->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Movie found successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    closeadd();
}
void gesfilm::onprintclicked(){
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFileName("movies.pdf");

    QTextDocument doc;

    QString text("<table><thead>");
    text.append("<tr>");
    for (int i = 0; i < tempdb.movtable->columnCount(); i++) {
        text.append("<th>").append(tempdb.movtable->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < tempdb.movtable->rowCount(); i++) {
        text.append("<tr>");
        for (int j = 0; j < tempdb.movtable->columnCount(); j++) {
            QTableWidgetItem *item = tempdb.movtable->item(i, j);
            if (!item || item->text().isEmpty()) {
                tempdb.movtable->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(tempdb.movtable->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
}
