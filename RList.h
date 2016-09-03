#ifndef RList_h
#define RList_h

#include <iostream>
using namespace std;
#include <string.h>
#include<istream>
#include<fstream>
#include<queue>
#include "Node.h"
class RList {
    Node *Rhead;
  public:
    RList() { Rhead = NULL; };
~RList(){};
    void Print();
    void Add(string name,float area,int doors,int xcord,int ycord,int status);
    void Delete(string name);
    void leastdistance(int pxcord,int pycord);
    void book(string rno);
void unbook(string rno);
void minirooms(int p);
 void printr(string name);
};
#endif
