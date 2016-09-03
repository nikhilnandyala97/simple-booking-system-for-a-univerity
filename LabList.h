#ifndef LabList_h
#define LabList_h
#include <iostream>
using namespace std;
#include <string.h>
#include<istream>
#include<fstream>
#include<queue>
#include "RList.h"
#include "Node.h"
class LabList: public RList {
     Node *Labhead;
     public :
LabList(){ Labhead=NULL;};
~LabList(){};
void Add(string name,float area,int doors,int xcord,int ycord,int coms,int status);
void Print();
virtual void emulator();
void leastdensity();
void book(string rno);
void unbook(string rno);
void update(string rno,int p);
 void Delete(string name);
void printr(string name);
};
#endif
