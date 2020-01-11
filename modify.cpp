#include "modify.h"
#include "ui_modify.h"
#include "btree.h"
#include <QMessageBox>
#include<string.h>

modify::modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify)
{
    ui->setupUi(this);
}

modify::~modify()
{
    delete ui;
}

void modify::on_pushButton_2_clicked()
{
    close();
}

void modify::on_pushButton_clicked()
{       char cvar[160],buff1[10];
        searchqt s;
        btree b;
        int key;
        car p;
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
        if(off==-1){
           QMessageBox::about(this,"Search","Record not found!!");
           return;
        }
        //cout<<"HELLO";
        char tname[]="temp.txt";
        fstream file3("name.txt",ios::in|ios::binary);
        fstream file4("temp.txt",ios::out|ios::app|ios::binary);
        cout<<"hello";

           {
           cout<<"HELLO";
           file3.getline(cvar,160,'*');
           int  len_field=strlen(cvar);
            cout<<cvar;

           strcpy(buff1,strtok(cvar,"|"));
           string keyy=key1.toStdString();
           char key[10];
           strcpy(key,keyy.c_str());
           if(strcmp(buff1,key)==0)
           {
               QString idd1=ui->lineEdit_2->text();
               QString namee1=ui->lineEdit_3->text();
               QString DLnoo1=ui->lineEdit_4->text();
               QString cartypee1=ui->lineEdit_5->text();
               QString Bdatee1=ui->lineEdit_6->text();
               char idd[20],namee[20],DLnoo[20],cartypee[20],Bdatee[20];
               string idd2=idd1.toStdString();
               string namee2=namee1.toStdString();
               string DLnoo2=DLnoo1.toStdString();
               string cartypee2=cartypee1.toStdString();
               string Bdatee2=Bdatee1.toStdString();
               strcpy(idd,idd2.c_str());
               strcpy(namee,namee2.c_str());
               strcpy(DLnoo,DLnoo2.c_str());
               strcpy(cartypee,cartypee2.c_str());
               strcpy(Bdatee,Bdatee2.c_str());
               file4<<idd<<"|"<<namee<<"|"<<DLnoo<<"|"<<cartypee<<"|"<<Bdatee<<"|"<<"*";
               file3.seekp(len_field,ios::beg);
           }
           else
               {


               file4.seekp(len_field,ios::beg);
               file3.seekp(len_field,ios::beg);

               }
           }
       }
//            buff.unpack(p);
//            int c=file3.tellg();
//            if(c==off)
//            {
//                QString idd1=ui->lineEdit_2->text();
//                QString namee1=ui->lineEdit_3->text();
//                QString DLnoo1=ui->lineEdit_4->text();
//                QString cartypee1=ui->lineEdit_5->text();
//                QString Bdatee1=ui->lineEdit_6->text();
//                char idd[20],namee[20],DLnoo[20],cartypee[20],Bdatee[20];
//                string idd2=idd1.toStdString();
//                string namee2=namee1.toStdString();
//                string DLnoo2=DLnoo1.toStdString();
//                string cartypee2=cartypee1.toStdString();
//                string Bdatee2=Bdatee1.toStdString();
//                strcpy(idd,idd2.c_str());
//                strcpy(namee,namee2.c_str());
//                strcpy(DLnoo,DLnoo2.c_str());
//                strcpy(cartypee,cartypee2.c_str());
//                strcpy(Bdatee,Bdatee2.c_str());
//               // for(int i=0;i<160;i++)
//                 //   buff1[i]=NULL;
//                strcpy(p.id,idd);
//                //strcat(buff1,"|");
//                strcpy(p.name,namee);
//                //strcat(buff1,"|");
//                strcpy(p.DLno,DLnoo);
//                //strcat(buff1,"|");
//                strcpy(p.cartype,cartypee);
//                //strcat(buff1,"|");
//                strcpy(p.Bdate,Bdatee);
//                //strcat(buff1,"|");
//                //strcat(buff1,"*");

//            }
//            buff.pack(p);
//            buff.Write(tname);
//            file3.close();
//            file4.close();
//            remove("name.txt");
//            rename(tname,"name.txt");
//            }
////        file3.seekg(off,ios::beg);
////        file3.getline(cvar,160,'*');
////        cout<<cvar;
////        int len_field;
////        len_field=strlen(cvar);
////        file3.seekp(off,ios::beg);
////        for(int j=0;j<len_field;j++)
////            file3<<'*';
////        file3.close();

////        file4<<buff1;
////        file4.close();


