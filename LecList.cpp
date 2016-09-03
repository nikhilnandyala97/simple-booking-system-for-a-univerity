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



void LecList::book(string rno){
      Node *temp =Lechead;
if (temp==NULL){
     cout<<"lechall not present"<<endl;
         return;}
      while(temp!=NULL){
         if(rno.compare(temp->Name())==0){
          break;}
temp=temp->Next();
        }
   if (temp==NULL){
      cout<<"lechall not present"<<endl;
         return;}
   if (temp->Bookstatus() ==0){
     cout<<"booked"<<endl;
     temp->setbook(1);
    }
    else{
      cout<<"this is already booked "<< endl;
    }
}
void LecList::unbook(string rno){
      Node *temp =Lechead;
if (temp==NULL){
     cout<<"lechall not present"<<endl;
         return;}
      while(temp!=NULL){
         if(rno.compare(temp->Name())==0){
          break;}
temp=temp->Next();
        }
   if (temp==NULL){
      cout<<"lechall not present"<<endl;
         return;}
   if (temp->Bookstatus() ==1){
     cout<<"unbooked"<<endl;
     temp->setbook(0);
    }
    else{
      cout<<"you have never booked this lechall "<< endl;
    }
}
void LecList::Add(string name,float area,int doors,int xcord,int ycord,int chairs,int status) {

 
    Node* newNode = new Node();
    newNode->setarea(area);
newNode->setdoors(doors);
newNode->setx(xcord);
newNode->sety(ycord);
newNode->setchair(chairs);
newNode->setname(name);
newNode->setbook(status);
    newNode->SetNext(NULL);

 
    Node *temp = Lechead;

    if ( temp != NULL ) {
 
    while ( temp->Next() != NULL ) {
        temp = temp->Next();
    }

 
    temp->SetNext(newNode);
    }
    else {
 
    Lechead = newNode;
    }
}

void LecList:: givenstudents(int s){
    Node *temp = Lechead;
     if(temp==NULL){
cout<< "no lec present"<<endl;
return;
}

  if ( temp->Next() == NULL ) {
    if(temp->Nchair() >=s){
   cout<<temp->Name()<<endl;
return;}
     else{
      cout<< "no lec present"<<endl;
      return;
 
   }
  }
    else{
   while(true){
           if(temp==NULL)
             {   cout << "no lecture halls present"<<endl;
             break;
              }
         if(temp->Nchair() >=s){
              
         break;
         }
        
       temp=temp->Next();
   
}
if(temp->Next()==NULL){
   cout<<temp->Name()<<endl;
return;}
Node* curr;
curr =temp;
temp=temp->Next();
 
do{
   if(temp->Nchair()<=curr->Nchair() && temp->Nchair()>=s){
   curr=temp;
    }
temp=temp->Next();
}
while(temp!=NULL);
  cout<< curr->Name()<<endl;
return;
}
}
void LecList::Print() {
ofstream tout;
 tout.open ("LEC.txt");
    Node *temp = Lechead;

 
    if ( temp == NULL ) {
    cout << "EMPTY" << endl;
    return;
    }

 
    if ( temp->Next() == NULL ) {
        tout << temp->Name()<<" ";
        tout << temp->Area()<<" ";
        tout << temp->Doors()<<" ";
        tout << temp->Xcord()<<" ";
        tout << temp->Ycord()<<" ";
        tout << temp->Nchair()<<" ";
        tout<< temp->Bookstatus()<<endl;
    }
    else {
 
    do {tout << temp->Name()<<" ";
        tout << temp->Area()<<" ";
        tout << temp->Doors()<<" ";
        tout << temp->Xcord()<<" ";
        tout << temp->Ycord()<<" ";
        tout << temp->Nchair()<<" ";
        tout<< temp->Bookstatus()<<endl;
        
        temp = temp->Next();
    }
    while ( temp != NULL );

    cout << "NULL" << endl;
    }
tout.close();
}
void LecList::Delete(string Rname){

 
    Node *tmp = Lechead;

 
    if ( tmp == NULL )
    return;

 
    if ( tmp->Next() == NULL ) {
    delete tmp;
    Lechead = NULL;
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
void LecList::printr(string Rname){

 
    Node *tmp = Lechead;

 
    if ( tmp == NULL )
    return;

 
    if ( tmp->Next() == NULL ) {
    delete tmp;
    Lechead = NULL;
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
        cout<<tmp->Nchair()<<endl;
        cout<<tmp->Bookstatus()<<endl;

 
    delete tmp;
    }
}
