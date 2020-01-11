#include "search.h"
#include "ui_search.h"
#include "btree.h"
#include "QMessageBox"

search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
}

search::~search()
{
    delete ui;
}


void search::on_search_2_clicked()
{   searchqt s;
    btree b;
    int key;
    fstream file;
    delimtextbuffer buff;
    char filename[20]="name.txt";
    operations o(filename);
    file.open("rr.txt",ios::in);
    if(!file.fail())
    {
        ifstream infile("rr.txt");
        int byteid,byteoffset;
        while(infile>>byteid>>byteoffset)
        {
            b.insert(byteid,byteoffset);
        }
    }
    QString key1=ui->lineEdit->text();
    key=key1.toInt();
    int off=b.search(key);
    s=o.search(off);
    if(off==-1){
       QMessageBox::about(this,"Search","Record not found!!");
       return;
    }

    ui->lineEdit_2->insert(s.i);
    ui->lineEdit_3->insert(s.n);
    ui->lineEdit_4->insert(s.d);
    ui->lineEdit_5->insert(s.c);
    ui->lineEdit_6->insert(s.b);
}


void search::on_pushButton_clicked()
{
    ui->lineEdit_2->clear();
   ui->lineEdit_3->clear();
   ui->lineEdit_4->clear();
   ui->lineEdit_5->clear();
   ui->lineEdit_6->clear();
   ui->lineEdit->clear();
}

void search::on_pushButton_2_clicked()
{
    close();
}
