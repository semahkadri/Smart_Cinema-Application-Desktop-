#include "gesproduit.h"
#include <QDebug>


Gesproduit::Gesproduit(QWidget *parent) : QWidget(parent)
{

    gproduit = new QWidget(this);
    gproduit->setGeometry(QRect(0,0,600,480));
    gproduit->setStyleSheet("background-color: #696969");

    addbtn = new QtMaterialRaisedButton(this);
    addbtn->setText("Add Product");
    addbtn->setGeometry(QRect(10,20,120,30));
    addbtn->setHaloVisible(false);

    addpvbtn = new QtMaterialRaisedButton(this);
    addpvbtn->setText("Open P.Vente");
    addpvbtn->setGeometry(QRect(10,20,120,30));
    addpvbtn->setHaloVisible(false);

    deletebtn = new QtMaterialRaisedButton(this);
    deletebtn->setText("Remove Product");
    deletebtn->setGeometry(QRect(10,70,120,30));
    deletebtn->setHaloVisible(false);

    deletepvbtn = new QtMaterialRaisedButton(this);
    deletepvbtn->setText("Close P.Vente");
    deletepvbtn->setGeometry(QRect(10,70,120,30));
    deletepvbtn->setHaloVisible(false);

    modifybtn = new QtMaterialRaisedButton(this);
    modifybtn->setText("Modify Product");
    modifybtn->setGeometry(QRect(10,120,120,30));
    modifybtn->setHaloVisible(false);

    modifypvbtn = new QtMaterialRaisedButton(this);
    modifypvbtn->setText("Modify P.V");
    modifypvbtn->setGeometry(QRect(10,120,120,30));
    modifypvbtn->setHaloVisible(false);

    statbtn = new QtMaterialRaisedButton(this);
    statbtn->setText("Stats");
    statbtn->setGeometry(QRect(10,170,120,30));
    statbtn->setHaloVisible(false);


    print1pdf = new QtMaterialRaisedButton(this);
    print1pdf->setText("Print");
    print1pdf->setGeometry(QRect(10,170,120,30));
    print1pdf->setHaloVisible(false);



    pointvente = new QWidget(this);
    pointvente->setGeometry(QRect(10,230,120,200));
    pointvente->setStyleSheet("background-color: white;");
    pvtext = new QLabel(pointvente);
    pvtext->setGeometry(QRect(0,0,115,125));
    pvtext->setText("<span style='font-size:13pt; font-weight:600; color:#000000;'>Point vente:<br></span>"
                    "<span style='font-size:10pt; font-weight:600; color:#555453;'>Num:<br><br></span>"
                    "<span style='font-size:10pt; font-weight:400; color:#000000;'>N°Products:<br>"
                                                                                  "N°Food:<br>"
                                                                                  "N°Drink:</span>" );
    tempdb.selectpv = new QComboBox(pointvente);
    tempdb.selectpv->setGeometry(QRect(0,130,120,20));
    tempdb.selectpv->setEditable(false);

    tablewidget = new QWidget(this);
    tablewidget->setGeometry(160,20,400,410);
    tablewidget->setStyleSheet("background-color: white;"
                               "border-radius: 10px");
   /* frame = new QFrame(tablewidget);
    frame->setGeometry(-85,-65,400,400);
    frame->setVisible(false);

    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.2);
    series->append("popcorn",4.2);
    QPieSlice *slice = series->append("cola",6.8);
    slice->setExploded();
    slice->setLabelVisible();
    series->append("fanta",89);

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(frame);*/


    tempdb.fillcombobox();
    tempdb.table = new QTableWidget(100,6,tablewidget);
    tempdb.table->hideColumn(5);
    tempdb.table->setGeometry(0,10,447,400);
    tempdb.table->setStyleSheet("background:transparent");
    tempdb.table->verticalHeader()->setVisible(false);
    tempdb.table->setHorizontalHeaderLabels(QStringList() <<" ID" <<"P. Name" << "P. Type" << "Quantity" <<"Valid until" <<"PVente");
    tempdb.table->setColumnWidth(0,30);
    tempdb.table->setColumnWidth(3,80);
    tempdb.table->setVisible(false);
    tempdb.pvtable = new QTableWidget(100,2,tablewidget);
    tempdb.pvtable->setGeometry(0,10,447,200);
    tempdb.pvtable->setStyleSheet("background:transparent");
    tempdb.pvtable->verticalHeader()->setVisible(false);
    tempdb.pvtable->setHorizontalHeaderLabels(QStringList() <<"PVENTE ID" << "ROOM N°");
    tempdb.pvtable->setVisible(true);
    QHeaderView* header = tempdb.pvtable->horizontalHeader();
    header->setStretchLastSection(true);

    addbtn->setVisible(false);
    modifybtn->setVisible(false);
    deletebtn->setVisible(false);
    print1pdf->setVisible(false);
    tempdb.table->setSortingEnabled(false);
    tempdb.showtable(pvslot);
    tempdb.table->setSortingEnabled(true);
    tempdb.showpvtable();


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

    addpvbtn2 = new QtMaterialRaisedButton(customdrawer);
    addpvbtn2->setText("Add");
    addpvbtn2->setHaloVisible(false);
    addpvbtn2->setGeometry(QRect(45,420,120,30));

    addbtn3 = new QtMaterialRaisedButton(customdrawer);
    addbtn3->setText("Modify");
    addbtn3->setHaloVisible(false);
    addbtn3->setGeometry(QRect(45,420,120,30));

    modifypvbtn2 = new QtMaterialRaisedButton(customdrawer);
    modifypvbtn2->setText("Modify");
    modifypvbtn2->setHaloVisible(false);
    modifypvbtn2->setGeometry(QRect(45,420,120,30));

    deletebtn2 = new QtMaterialRaisedButton(customdrawer);
    deletebtn2->setText("Delete");
    deletebtn2->setHaloVisible(false);
    deletebtn2->setGeometry(QRect(45,420,120,30));

    deletepvbtn2 = new QtMaterialRaisedButton(customdrawer);
    deletepvbtn2->setText("Delete");
    deletepvbtn2->setHaloVisible(false);
    deletepvbtn2->setGeometry(QRect(45,420,120,30));

    cancelbtn = new QtMaterialRaisedButton(customdrawer);
    cancelbtn->setText("Cancel");
    cancelbtn->setHaloVisible(false);
    cancelbtn->setGeometry(QRect(175,420,120,30));

    txtid = new QtMaterialTextField(customdrawer);
    txtid->setTextColor("black");
    txtid->setInkColor("black");
    txtid->setLabelColor("red");
    txtid->setLabel("Product ID");
    txtid->setGeometry(QRect(50,0,250,60));

    txtname = new QtMaterialTextField(customdrawer);
    txtname->setTextColor("black");
    txtname->setInkColor("black");
    txtname->setLabel("Product Name");
    txtname->setGeometry(QRect(50,70,250,60));

    txtquantity = new QtMaterialTextField(customdrawer);
    txtquantity->setTextColor("black");
    txtquantity->setInkColor("black");
    txtquantity->setLabel("Quantity");
    txtquantity->setGeometry(QRect(50,280,250,60));

    txttype = new QtMaterialTextField(customdrawer);
    txttype->setTextColor("black");
    txttype->setInkColor("black");
    txttype->setLabel("Type");
    txttype->setGeometry(QRect(50,140,250,60));

    txtvalid = new QtMaterialTextField(customdrawer);
    txtvalid->setTextColor("black");
    txtvalid->setInkColor("black");
    txtvalid->setLabel("Valid until");
    txtvalid->setGeometry(QRect(50,210,250,60));

    txtpvid = new QtMaterialTextField(customdrawer);
    txtpvid->setTextColor("black");
    txtpvid->setInkColor("black");
    txtpvid->setLabelColor("red");
    txtpvid->setLabel("PVente ID");
    txtpvid->setGeometry(QRect(50,140,250,60));

    txtpvname = new QtMaterialTextField(customdrawer);
    txtpvname->setTextColor("black");
    txtpvname->setInkColor("black");
    txtpvname->setLabel("PVente Name");
    txtpvname->setGeometry(QRect(50,210,250,60));

    selectwarning = new QtMaterialSnackbar(tablewidget);
    connect(tempdb.selectpv,SIGNAL(activated(int)),this,SLOT(setpvente(int)), Qt::UniqueConnection);
    connect(modifybtn, SIGNAL(clicked()),this,SLOT(onmodifyclicked()), Qt::UniqueConnection);
    connect(addbtn,SIGNAL(clicked()),this, SLOT(onaddclicked()), Qt::UniqueConnection);
    connect(addbtn2,SIGNAL(clicked()),this,SLOT(addproduct()), Qt::UniqueConnection);
    connect(cancelbtn, SIGNAL(clicked()),this, SLOT(closeadd()), Qt::UniqueConnection);
    connect(deletebtn, SIGNAL(clicked()),this,SLOT(ondeleteclicked()), Qt::UniqueConnection);
    connect(addpvbtn, SIGNAL(clicked()),this,SLOT(onaddpvclicked()), Qt::UniqueConnection);
    connect(modifypvbtn,SIGNAL(clicked()),this,SLOT(onmodifypvclicked()), Qt::UniqueConnection);
    connect(deletepvbtn,SIGNAL(clicked()),this,SLOT(ondeletepvclicked()), Qt::UniqueConnection);
    connect(statbtn, SIGNAL(clicked()),this,SLOT(showstats()), Qt::UniqueConnection);
    connect(print1pdf, SIGNAL(clicked()),this,SLOT(onprintclicked()), Qt::UniqueConnection);

    deletepvbtn2->setVisible(false);
    modifypvbtn2->setVisible(false);
    txtpvid->setVisible(false);
    txtpvname->setVisible(false);
    addbtn3->setVisible(false);
    addbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtid->setVisible(false);
    txtname->setVisible(false);
    txttype->setVisible(false);
    txtquantity->setVisible(false);
    txtvalid->setVisible(false);
    addbtn3->setVisible(false);
    deletebtn2->setVisible(false);
    addpvbtn2->setVisible(false);

}
void Gesproduit::setpvente(int idx){
    pvslot = idx;
    if(pvslot==0){
        tempdb.showpvtable();
        tempdb.table->setVisible(false);
        tempdb.pvtable->setVisible(true);
        addbtn->setVisible(false);
        modifybtn->setVisible(false);
        deletebtn->setVisible(false);
        print1pdf->setVisible(false);
        addpvbtn->setVisible(true);
        modifypvbtn->setVisible(true);
        statbtn->setVisible(true);
        deletepvbtn->setVisible(true);
    }else{
    tempdb.table->setSortingEnabled(false);
    tempdb.showtable(pvslot);
    tempdb.table->setSortingEnabled(true);
    tempdb.table->setVisible(true);
    tempdb.pvtable->setVisible(false);
    addbtn->setVisible(true);
    modifybtn->setVisible(true);
    deletebtn->setVisible(true);
    statbtn->setVisible(false);
    print1pdf->setVisible(true);
    addpvbtn->setVisible(false);
    modifypvbtn->setVisible(false);
    deletepvbtn->setVisible(false);
    }
    QString text=("<span style='font-size:13pt; font-weight:600; color:#000000;'>Point vente:<br></span>"
                  "<span style='font-size:10pt; font-weight:600; color:#555453;'>Num:  "+QString::number(idx)+"<br><br></span>"
                  "<span style='font-size:10pt; font-weight:400; color:#000000;'>N°Products:<br>"
                                                                                "N°Food:<br>"
                                                                                "N°Drink:</span>");
    pvtext->setText(text);
}
void Gesproduit::onprintclicked(){
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFileName("products.pdf");

    QTextDocument doc;

    QString text("<table><thead>");
    text.append("<tr>");
    for (int i = 0; i < tempdb.table->columnCount(); i++) {
        text.append("<th>").append(tempdb.table->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < tempdb.table->rowCount(); i++) {
        text.append("<tr>");
        for (int j = 0; j < tempdb.table->columnCount(); j++) {
            QTableWidgetItem *item = tempdb.table->item(i, j);
            if (!item || item->text().isEmpty()) {
                tempdb.table->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(tempdb.table->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
}
void Gesproduit::opendrawer(){
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

void Gesproduit::onaddclicked(){
    opendrawer();
    txtid->setVisible(false);
    addbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtname->setVisible(true);
    txttype->setVisible(true);
    txtquantity->setVisible(true);
    txtvalid->setVisible(true);
}
void Gesproduit::onaddpvclicked(){
    opendrawer();
    cancelbtn->setVisible(true);
    addpvbtn2->setVisible(true);
    txtpvid->setVisible(true);
    txtpvid->setEnabled(false);
    txtpvname->setVisible(true);
    connect(addpvbtn2, SIGNAL(clicked()), this, SLOT(addpv()), Qt::UniqueConnection);
}
void Gesproduit::ondeletepvclicked(){
    opendrawer();
    cancelbtn->setVisible(true);
    txtpvid->setVisible(true);
    deletepvbtn2->setVisible(true);
    connect(deletepvbtn2,SIGNAL(clicked()),this,SLOT(deletepv()), Qt::UniqueConnection);
}
void Gesproduit::deletepv(){
    int id = txtpvid->text().toInt();
    if(!tempdb.deletepv(id))
    {
        selectwarning->addMessage("Please enter a valid ID");
        selectwarning->setTextColor("red");
        selectwarning->setBoxWidth(400);
        selectwarning->setGeometry(QRect(0,300,400,70));
        selectwarning->setBackgroundColor("black");
        selectwarning->show();}
    else {
        selectwarning->addMessage("PVente deleted successfully");
        selectwarning->setTextColor("green");
        selectwarning->setBoxWidth(400);
        selectwarning->setGeometry(QRect(0,300,400,70));
        selectwarning->setBackgroundColor("black");
        selectwarning->show();
    }
    tempdb.showpvtable();
    tempdb.selectpv->clear();
    tempdb.fillcombobox();
    closeadd();
}
void Gesproduit::addpv(){
    tempdb.addpvente(txtpvname->text());
    tempdb.selectpv->clear();
    tempdb.fillcombobox();
    tempdb.showpvtable();

    closeadd();
}
void Gesproduit::addproduct(){
   tempdb.table->setSortingEnabled(false);
   tempdb.addproduct(txtname->text(),txttype->text(),txtvalid->text(),txtquantity->text(),pvslot);
   tempdb.showtable(pvslot);
   tempdb.table->setSortingEnabled(true);
   closeadd();
}
void Gesproduit::closeadd(){
    txtpvid->setVisible(false);
    txtpvname->setVisible(false);
    addbtn3->setVisible(false);
    addbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtid->setVisible(false);
    txtname->setVisible(false);
    txttype->setVisible(false);
    txtquantity->setVisible(false);
    txtvalid->setVisible(false);
    addbtn3->setVisible(false);
    deletebtn2->setVisible(false);
    addpvbtn2->setVisible(false);
    modifypvbtn2->setVisible(false);
    deletepvbtn2->setVisible(false);

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
void Gesproduit::onmodifypvclicked(){
    opendrawer();
    modifypvbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtpvid->setVisible(true);
    txtpvid->setEnabled(true);
    txtpvname->setVisible(true);

    connect(modifypvbtn2,SIGNAL(clicked()),this,SLOT(pvmodified()), Qt::UniqueConnection);
}
void Gesproduit::pvmodified(){
    int id = txtpvid->text().toInt();

    if(!tempdb.modifypv(id,txtpvname->text()))
    {
        selectwarning->addMessage("Please enter a valid ID");
        selectwarning->setTextColor("red");
        selectwarning->setBoxWidth(400);
        selectwarning->setGeometry(QRect(0,300,400,70));
        selectwarning->setBackgroundColor("black");
        selectwarning->show();}
    else {
        selectwarning->addMessage("PVente updated successfully");
        selectwarning->setTextColor("green");
        selectwarning->setBoxWidth(400);
        selectwarning->setGeometry(QRect(0,300,400,70));
        selectwarning->setBackgroundColor("black");
        selectwarning->show();
    }
    closeadd();
    tempdb.selectpv->clear();
    tempdb.fillcombobox();
    tempdb.showpvtable();

}
void Gesproduit::onmodifyclicked(){
    opendrawer();
    addbtn3->setVisible(true);
    cancelbtn->setVisible(true);
    txtname->setVisible(true);
    txtid->setVisible(true);
    txtvalid->setVisible(true);
    txttype->setVisible(true);
    txtquantity->setVisible(true);
    connect(addbtn3,SIGNAL(clicked()),this,SLOT(productmodified()), Qt::UniqueConnection);
}
void Gesproduit::productmodified(){

    int id = txtid->text().toInt();
    if(!tempdb.updatetable(id,pvslot,txtname->text(),txttype->text(),txtvalid->text(),txtquantity->text()))
    {
        selectwarning->addMessage("Please enter a valid ID");
        selectwarning->setTextColor("red");
        selectwarning->setBoxWidth(400);
        selectwarning->setGeometry(QRect(0,300,400,70));
        selectwarning->setBackgroundColor("black");
        selectwarning->show();}
    else {
        selectwarning->addMessage("Product updated successfully");
        selectwarning->setTextColor("green");
        selectwarning->setBoxWidth(400);
        selectwarning->setGeometry(QRect(0,300,400,70));
        selectwarning->setBackgroundColor("black");
        selectwarning->show();
    }
    closeadd();
    tempdb.table->setSortingEnabled(false);
    tempdb.showtable(pvslot);
    tempdb.table->setSortingEnabled(true);
}
void Gesproduit::ondeleteclicked(){
    opendrawer();
    deletebtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtid->setVisible(true);
    txtid->setEnabled(true);
    connect(deletebtn2,SIGNAL(clicked()),this,SLOT(deleted()), Qt::UniqueConnection);
}
void Gesproduit::deleted(){

    int id = txtid->text().toInt();
    if(!tempdb.deletetable(id,pvslot))
    {
        selectwarning->addMessage("Please enter a valid ID");
        selectwarning->setTextColor("red");
        selectwarning->setBoxWidth(400);
        selectwarning->setGeometry(QRect(0,300,400,70));
        selectwarning->setBackgroundColor("black");
        selectwarning->show();}
    else {
        selectwarning->addMessage("Product deleted successfully");
        selectwarning->setTextColor("green");
        selectwarning->setBoxWidth(400);
        selectwarning->setGeometry(QRect(0,300,400,70));
        selectwarning->setBackgroundColor("black");
        selectwarning->show();
    }
    closeadd();
    tempdb.table->setSortingEnabled(false);
    tempdb.showtable(pvslot);
    tempdb.table->setSortingEnabled(true);

}
void Gesproduit::showstats(){   

  stats = new Statistics(this);
  stats->show();
}

