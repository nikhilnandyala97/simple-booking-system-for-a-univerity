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




void LabList::book(string rno){
      Node *temp =Labhead;
if (temp==NULL){
     cout<<"lab not present"<<endl;
         return;}
      while(temp!=NULL){
         if(rno.compare(temp->Name())==0){
          break;}
temp=temp->Next();
        }
   if (temp==NULL){
      cout<<"lab not present"<<endl;
         return;}
   if (temp->Bookstatus() ==0){
     cout<<"booked"<<endl;
     temp->setbook(1);
    }
    else{
      cout<<"this is already booked "<< endl;
    }
}
void LabList::unbook(string rno){
      Node *temp =Labhead;
if (temp==NULL){
     cout<<"lab not present"<<endl;
         return;}
      while(temp!=NULL){
         if(rno.compare(temp->Name())==0){
          break;}
temp=temp->Next();
        }
   if (temp==NULL){
      cout<<"lab not present"<<endl;
         return;}
   if (temp->Bookstatus() ==1){
     cout<<"unbooked"<<endl;
     temp->setbook(0);
    }
    else{
      cout<<"you have never booked this lab "<< endl;
    }
}
void LabList::update(string rno,int p){
      Node *temp =Labhead;
if (temp==NULL){
     cout<<"lab not present"<<endl;
         return;}
      while(temp!=NULL){
         if(rno.compare(temp->Name())==0){
          break;}
temp=temp->Next();
        }
   if (temp==NULL){
      cout<<"lab not present"<<endl;
         return;}
  temp->setcomp(p);
}
void LabList::Add(string name,float area,int doors,int xcord,int ycord,int coms,int status) {

 
    Node* newNode = new Node();
    newNode->setarea(area);
newNode->setdoors(doors);
newNode->setx(xcord);
newNode->sety(ycord);
newNode->setcomp(coms);
newNode->setname(name);
newNode->setbook(status);
    newNode->SetNext(NULL);

 
    Node *tmp = Labhead;

    if ( tmp != NULL ) {
 
    while ( tmp->Next() != NULL ) {
        tmp = tmp->Next();
    }

 
    tmp->SetNext(newNode);
    }
    else {
 
    Labhead = newNode;
    }
}
void LabList::Print() {
ofstream lout;
 lout.open("LAB.txt");
    Node *tmp = Labhead;

 
    if ( tmp == NULL ) {
    cout << "EMPTY" << endl;
    return;
    }

 
    if ( tmp->Next() == NULL ) {
        lout << tmp->Name()<<" ";
        lout << tmp->Area()<<" ";
        lout << tmp->Doors()<<" ";
        lout << tmp->Xcord()<<" ";
        lout << tmp->Ycord()<<" ";
        lout << tmp->Ncomp()<<" ";
        lout << tmp->Bookstatus()<<endl;
   }

    else {
 
    do {lout << tmp->Name()<<" ";
        lout << tmp->Area()<<" ";
  
        lout << tmp->Doors()<<" ";
        lout << tmp->Xcord()<<" ";
        lout << tmp->Ycord()<<" ";
        lout << tmp->Ncomp()<<" ";
        lout << tmp->Bookstatus()<<endl;
        
        tmp = tmp->Next();
    }
    while ( tmp != NULL );

    cout << "NULL" << endl;
    }
lout.close();
}
void LabList:: leastdensity(){
    Node *temp = Labhead;
     if(temp==NULL){
cout<< "no labs present"<<endl;
return;
}

  if ( temp->Next() == NULL ) {
   cout<<temp->Name()<<endl;
return;
 
   }
    else {
temp=temp->Next();
  Node* curr;
curr =Labhead;
do{
   if((curr->Ncomp()/curr->Area())>=(temp->Ncomp()/temp->Area())){
   curr=temp;
    }
temp=temp->Next();
}
while(temp!=NULL);
  cout<< curr->Name()<<endl;
return;
}
}
   
    

void LabList::Delete(string Rname){

 
    Node *tmp = Labhead;

 
    if ( tmp == NULL )
    return;

 
    if ( tmp->Next() == NULL ) {
    delete tmp;
    Labhead = NULL;
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
}
void LabList::printr(string Rname){

 
    Node *tmp = Labhead;

 
    if ( tmp == NULL )
    return;

 
    if ( tmp->Next() == NULL ) {
    delete tmp;
    Labhead = NULL;
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
        cout<<tmp->Ncomp()<<endl;
        cout<<tmp->Bookstatus()<<endl;

 
    delete tmp;
    }
}
