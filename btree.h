#ifndef BTREE_H
#define BTREE_H
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<sstream>
#include<ctype.h>
#include<bits/stdc++.h>
#include <QApplication>
#include <QAbstractTableModel>
using namespace std;

extern int a;
class delimtextbuffer;
class car
{public:
    char id[20];
    char name[20];
    char DLno[20];
    char cartype[20];
    char Bdate[20];
    friend class delimtextbuffer;
};
class delimtextbuffer
{
public:
    char buffer[160];
    char delim;
    void pack(car& p);
    void unpack(car& p);
    void Read(fstream& fs);
    int Write(char const* filename);
    delimtextbuffer();
};
struct getvalues {
    string idd;
    int offsett;
};
struct searchqt{
    char i[20];
    char n[20];
    char d[20];
    char c[20];
    char b[20];

};

class operations
{

    char const *recordfilename;

public:

    operations(char const *recordfile);
    searchqt search(int offset);
    getvalues insert(car& p);
};

class node
{
public:
int a[4];
node * next[4];
node * parent;
int addr[4];
int size;
node();
};

class btree
{
public:
node * root;
node* findLeaf(int key,int &level);
void updateKey(node *p,node *c,int newKey);
int search(int key);
void insert(int key,int offset);
void insertIntoNode(node *n,int key,int offset,node *address);
void promote(node *n,int key,int offset,node *address);
node* split(node *n);
void traverse(node *ptr);
QList<searchqt> traversed(node *ptr);
btree();
friend class operations;
};

#endif // BTREE_H
