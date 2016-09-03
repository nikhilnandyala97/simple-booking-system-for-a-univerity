#ifndef LecList_h
#define LecList_h
#include <iostream>
using namespace std;
#include <string.h>
#include<istream>
#include<fstream>
#include<queue>
#include "RList.h"
#include "LabList.h"
#include "Node.h"
class LecList: public LabList {
     Node *Lechead;
     public :
LecList(){ Lechead=NULL;};
~LecList(){};
void Add(string name,float area,int doors,int xcord,int ycord,int chairs,int status);
void Print();
void givenstudents(int s);
void book(string rno);
void unbook(string rno);
 void Delete(string name);
void printr(string name);
};
#endif
