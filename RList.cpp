#include <iostream>
using namespace std;
#include <string.h>
#include<istream>
#include<fstream>
#include<queue>
#include "RList.h"
#include "LabList.h"
#include "Node.h"
#include "LecList.h"




void RList::book(string rno){
      Node *temp =Rhead;
if (temp==NULL){
     cout<<"roomhall not present"<<endl;
         return;}
      while(temp!=NULL){
         if(rno.compare(temp->Name())==0){
          break;}
temp=temp->Next();
        }
   if (temp==NULL){
      cout<<"roomhall not present"<<endl;
         return;}
   if (temp->Bookstatus() ==0){
     cout<<"booked"<<endl;
     temp->setbook(1);
    }
    else{
      cout<<"this room is already booked "<< endl;
    }
}



void RList::unbook(string rno){
      Node *temp =Rhead;
if (temp==NULL){
     cout<<"roomhall not present"<<endl;
         return;}
      while(temp!=NULL){
         if(rno.compare(temp->Name())==0){
          break;}
temp=temp->Next();
        }
   if (temp==NULL){
      cout<<"roomhall not present"<<endl;
         return;}
   if (temp->Bookstatus() ==1){
     cout<<"unbooked"<<endl;
     temp->setbook(0);
    }
    else{
      cout<<"you have never booked this room "<< endl;
    }
}
void RList::minirooms(int p){
Node* tmp=Rhead;
int r=0;
int u=0;

   std::priority_queue<int> qu;
while(tmp!=NULL){
if(tmp->Bookstatus() == 0){
qu.push((tmp->Area()/30));
}
tmp=tmp->Next();

}

while(r<p && !qu.empty()){

  r=r+qu.top();
qu.pop();
u=u+1;
}
if(qu.empty()){
cout<<"you cant fit that many persons in the rooms"<<endl;}
else{
cout<<u<<endl;}
return;
}
void RList::Print() {
ofstream rout;
 rout.open ("ROOM.txt");
    Node *tmp = Rhead;

 
    if ( tmp == NULL ) {
    cout << "EMPTY" << endl;
    return;
    }

 
    if ( tmp->Next() == NULL ) {
        rout << tmp->Name()<<" ";
        rout << tmp->Area()<<" ";
        rout << tmp->Doors()<<" ";
        rout << tmp->Xcord()<<" ";
        rout << tmp->Ycord()<<" ";
        rout<<tmp->Bookstatus()<<endl;
    }
    else {
 
    do { rout << tmp->Name()<<" ";
        rout << tmp->Area()<<" ";
        rout << tmp->Doors()<<" ";
        rout << tmp->Xcord()<<" ";
        rout << tmp->Ycord()<<" ";
        rout<<tmp->Bookstatus()<<endl;
       
        tmp = tmp->Next();
    }
    while ( tmp != NULL );

    cout << "NULL" << endl;
    }
rout.close();
}


void RList::Add(string name,float area,int doors,int xcord,int ycord,int status) {

 
    Node* newNode = new Node();
    newNode->setarea(area);
newNode->setdoors(doors);
newNode->setx(xcord);
newNode->sety(ycord);
 newNode->setname(name);
newNode->setbook(status);
   newNode->SetNext(NULL);

 
    Node *tmp = Rhead;

    if ( tmp != NULL ) {
 
    while ( tmp->Next() != NULL ) {
        tmp = tmp->Next();
    }

 
    tmp->SetNext(newNode);
    }
    else {
 
    Rhead = newNode;
    }
}
 void RList:: leastdistance(int pxcord,int pycord){
    Node *temp = Rhead;
     if(temp==NULL){
cout<< "no rooms present"<<endl;
return;
}

  if ( temp->Next() == NULL ) {
   cout<<temp->Name()<<endl;
return;
 
   }
    else {
temp=temp->Next();
  Node* curr;
curr =Rhead;
do{int c=((curr->Xcord()-pxcord)*(curr->Xcord()-pxcord) +(curr->Ycord()-pycord)*(curr->Ycord()-pycord)  );
   int d=((temp->Xcord()-pxcord)*(temp->Xcord()-pxcord) +(temp->Ycord()-pycord)*(temp->Ycord()-pycord)  );
   if(c>d){
   curr=temp;
    }
temp=temp->Next();
}
while(temp!=NULL);
  cout<< curr->Name()<<endl;
return;
}
}

void RList::Delete(string Rname){

 
    Node *tmp = Rhead;

 
    if ( tmp == NULL )
    return;

 
    if ( tmp->Next() == NULL ) {
    delete tmp;
    Rhead = NULL;
    }
    else {
  
 
    Node *prev;
    do {
        if ( tmp->Name()==Rname ) break;
        prev = tmp;
        tmp = tmp->Next();
    } while ( tmp != NULL );

 
    prev->SetNext(tmp->Next());

 
    delete tmp;
    }
}void RList::printr(string Rname){

 
    Node *tmp = Rhead;

 
    if ( tmp == NULL )
    return;

 
    if ( tmp->Next() == NULL ) {
    delete tmp;
    Rhead = NULL;
    }
    else {
  
 
    Node *prev;
    do {
        if ( tmp->Name()==Rname ) break;
        prev = tmp;
        tmp = tmp->Next();
    } while ( tmp != NULL );

 cout << tmp->Name()<<endl;
        cout << tmp->Area()<<endl;
        cout << tmp->Doors()<<endl;
        cout << tmp->Xcord()<<endl;
        cout << tmp->Ycord()<<endl;
        cout << tmp->Bookstatus()<< endl;

 
    delete tmp;
    }
}

