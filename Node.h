#ifndef Node_h
#define Node_h
#include <iostream>
using namespace std;
#include <string.h>
#include<istream>
#include<fstream>
#include<queue>

class Node {
    float area;
  int doors;
int xcord;
int ycord;
int comps;
string name;
int chairs;
 int status;
 Node* next;


 
  
  public:
    Node() {};
void setname( string nname){name=nname;};
    void setarea(float aarea) { area = aarea; };
 void setdoors(int adoors) { doors = adoors; };
void setx(int ax) { xcord = ax; };
void sety(int ay) { ycord = ay; };
void setcomp(int c) { comps = c; };
void setchair(int ch) { chairs = ch; };
void setbook(int b){ status=b;};
void SetNext(Node* aNext) { next = aNext; };
 
   float Area() { return area; };
int Doors() { return doors; };
int Xcord() { return xcord; };
int Ycord() { return ycord; };
int Ncomp() { return comps; };
int Nchair() { return chairs; };
int Bookstatus(){return status;};
string Name(){return name;};
    Node* Next() { return next; };
};


#endif
