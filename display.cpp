#include "display.h"
#include "ui_display.h"
#include "btree.h"
#include <QAbstractTableModel>
#include "QTableView"
#include "QMessageBox"
//int num;
display::display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);
}

display::~display()
{
    delete ui;
}

void display::on_display_2_clicked()
{   searchqt data;
    btree b;
    car p;
    operations o("name.txt");
    delimtextbuffer buff;
    fstream file3;
    file3.open("rr.txt",ios::in);
    if(!file3.fail())
    {
        ifstream infile("rr.txt");
        int byteid,byteoffset;
        while(infile>>byteid>>byteoffset && !infile.eof())
        {
            b.insert(byteid,byteoffset);

        }

    }
    ui->plainTextEdit->appendPlainText("Cus Id\tCus Name\tDL No.\t\tCar Type\tBooking Date");
    fstream file1("name.txt", ios::in);
    int byteid,byteoffset;
    ifstream infilee("rr.txt");
    if(file3.fail())
    {
        QMessageBox::about(this,"Display","File does not exist");
    }
    while(infilee>>byteid>>byteoffset)
    {
        file1.seekg(byteoffset, ios::beg);
        data=o.search(byteoffset);
        QString final;
        final.append(data.i);
        final.append("\t");
        final.append(data.n);
        final.append("\t");
        final.append(data.d);
        final.append("\t\t");
        final.append(data.c);
        final.append("\t");
        final.append(data.b);
        final.append("\t");
        ui->plainTextEdit->appendPlainText(final);


    }
//    data=b.traversed(b.root);
//    if(strcmp(data[0].i," ")==0){
//        QMessageBox::about(this,"try","File doesnot exists!!");
//    }
//   QString s=QString::number(data.size());
//   ui->plainTextEdit->appendPlainText(s);
//    ui->plainTextEdit->insertPlainText("Id\tname\tDLno.\tcar type\tbooking date");
//    for(int i=0;i<data.size();i++){
//        QString final;
//        final.append(data.at(i).i);
//        final.append("\t");
//        final.append(data.at(i).n);
//        final.append("\t");
//        final.append(data.at(i).d);
//        final.append("\t");
//        final.append(data.at(i).c);
//        final.append("\t");
//        final.append(data.at(i).b);
//        final.append("\t");
//        ui->plainTextEdit->appendPlainText(final);
//       // ui->plainTextEdit->appendPlainText(data.at(i).n);
//        //ui->plainTextEdit->appendPlainText(data.at(i).d);
//        //ui->plainTextEdit->appendPlainText(data.at(i).c);
//        //ui->plainTextEdit->appendPlainText(data.at(i).b);

    }



void display::on_pushButton_clicked()
{
    close();
}
