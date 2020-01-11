#include "insert.h"
#include "ui_insert.h"
#include <QMessageBox>
#include "btree.h"
#include<iostream>
#include<sstream>
//extern int num=0;
insert::insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert)
{
    ui->setupUi(this);
}

insert::~insert()
{
    delete ui;
}



void insert::on_insert_2_clicked()
{   car p;
    btree b;
    getvalues value;
    int key;
    fstream file2,file3;
    delimtextbuffer buff;
    char filename[20]="name.txt";
    operations o(filename);
    file3.open("rr.txt",ios::in);
    if(!file3.fail())
    {
        ifstream infile("rr.txt");
        int byteid,byteoffset;
        while(infile>>byteid>>byteoffset)
        {
            b.insert(byteid,byteoffset);
        }
    }
    QString id1=ui->l1->text();
    QString name1=ui->l2->text();
    QString DLno1=ui->l3->text();
    QString cartype1=ui->l4->text();
    QString Bdate1=ui->l5->text();
    char id[20],name[20],DLno[20],cartype[20],Bdate[20];
    string id2=id1.toStdString();
    string name2=name1.toStdString();
    string DLno2=DLno1.toStdString();
    string cartype2=cartype1.toStdString();
    string Bdate2=Bdate1.toStdString();
    strcpy(id,id2.c_str());
    strcpy(name,name2.c_str());
    strcpy(DLno,DLno2.c_str());
    strcpy(cartype,cartype2.c_str());
    strcpy(Bdate,Bdate2.c_str());
    strcpy(p.id,id);
    strcpy(p.name,name);
    strcpy(p.DLno,DLno);
    strcpy(p.cartype,cartype);
    strcpy(p.Bdate,Bdate);
    value=o.insert(p);
    stringstream geek(value.idd);
    key=0;
    geek>>key;
    b.insert(key,value.offsett);
    if(a==0){
        buff.pack(p);
        fstream os(filename, ios::out | ios::app);
        os.write(buff.buffer, strlen(buff.buffer));
        file2.open("rr.txt", ios::out | ios::app);
        file2 << value.idd << " " << value.offsett << endl;
        os.close();
        file2.close();
        //num++;
        QMessageBox::about(this,"Insert","Record Inserted!!");
    }
    else if(a==1){

         QMessageBox::about(this,"Insert","Duplicate Record!!");
    }
    ui->l1->clear();
    ui->l2->clear();
    ui->l3->clear();
    ui->l4->clear();
    ui->l5->clear();
    file3.close();

}

void insert::on_pushButton_2_clicked()
{

}

void insert::on_pushButton_clicked()
{
    close();
}
