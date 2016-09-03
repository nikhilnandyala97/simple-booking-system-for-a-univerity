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




int main()
{
 
    RList Roomlist;
   LabList list2;
   LecList list3;

 ifstream infile("ROOM.txt");
  string roname,entname;
  float roarea,entarea;
 int rod,xi,yj,op,entd,ex,ey,enc,es,bs;
char r;
 while(infile>>roname>>roarea>>rod>>xi>>yj>>bs){

    Roomlist.Add(roname,roarea,rod,xi,yj,bs);
 }
  ifstream lafile("LAB.txt");
 int ncompos;
 while(lafile>>roname>>roarea>>rod>>xi>>yj>>ncompos>>bs){

list2.Add(roname,roarea,rod,xi,yj,ncompos,bs);
    
 }
  // list2.Print();
ifstream lefile("LEC.txt");
 int nchairos;
 while(lefile>>roname>>roarea>>rod>>xi>>yj>>nchairos>>bs){

list3.Add(roname,roarea,rod,xi,yj,nchairos,bs);
    
 }
 while(true){
   cout<<" press 1- to add rooms, labs, or lecture halls"<<endl;
   cout<<"press 2-to remove a room, lab, or lecture hall"<<endl;
    cout<<"press 3-to book a room, lab, or lecture hall"<<endl;
cout<<"press 4-the minimum number of rooms required to accommodate given number of persons"<<endl;
   cout<<"press 5-to find the smallest lecture hall that can accommodate the given number of students"<<endl;
  cout<<"press 6-to find the lab with least equipment density and increase the equipment in a lab"<<endl;
  cout<<"press 7-Find a room nearest to the given location"<<endl;
  cout<<"press 8-to  unbook a room, lab, and lecture hall"<<endl;
cout<< "press 9- to  print all details of the given room, lab, and lecture hall"<<endl;
cout<<"press 10- to exit for the program"<<endl;
cin>>op;
if(op==1){
cout<<"to add rooms press-r"<<endl;
cout<< "to add labs press-l"<<endl;
cout<<"to add lec halls press-h"<<endl;
cin>>r;
 if(r=='r'){
  cout<<"enter room name"<<endl;
  cin>> entname;
   cout<<"enter area"<<endl;
  cin>>entarea;
cout<<"enter no fo doors"<<endl;
 cin>>entd;
  cout<<"enter x cordinates and y coordinates"<<endl;
  cin>>ex;
cin>>ey;
 Roomlist.Add(entname,entarea,entd,ex,ey,0);
}
if(r=='l'){
  cout<<"enter lab name"<<endl;
  cin>> entname;
   cout<<"enter area"<<endl;
  cin>>entarea;
cout<<"enter no fo doors"<<endl;
 cin>>entd;
  cout<<"enter x cordinates and y coordinates"<<endl;
  cin>>ex;
cin>>ey;
cout<<"enter no fo computers"<<endl;
 cin>>enc;
 list2.Add(entname,entarea,entd,ex,ey,enc,0);
}
if(r=='h'){
  cout<<"enter lec hall name"<<endl;
  cin>> entname;
   cout<<"enter area"<<endl;
  cin>>entarea;
cout<<"enter no fo doors"<<endl;
 cin>>entd;
  cout<<"enter x cordinates and y coordinates"<<endl;
  cin>>ex;
cin>>ey;
cout<<"enter no fo chairss"<<endl;
 cin>>enc;
 list2.Add(entname,entarea,entd,ex,ey,enc,0);
}
}

if(op==2){
cout<<"to remove rooms press-r"<<endl;
cout<< "to remove labs press-l"<<endl;
cout<<"to remove lec halls press-h"<<endl;
cin>>r;
 if(r=='r'){
  cout<<"enter room name"<<endl;
cin>>entname;
Roomlist.Delete(entname);
}
if(r=='l'){
cout<<"enter labname"<<endl;
cin>>entname;
list2.Delete(entname);


}
if(r=='h'){
cout<<"enter labname"<<endl;
cin>>entname;
list3.Delete(entname);

}
}
if(op==3){
cout<<"to book  rooms press-r"<<endl;
cout<< "to book  labs press-l"<<endl;
cout<<"to book  lec halls press-h"<<endl;
cin>>r;

if(r=='r'){
  cout<<"enter room name"<<endl;
cin>>entname;
Roomlist.book(entname);
}
if(r=='l'){
cout<<"enter labname"<<endl;
cin>>entname;
list2.book(entname);


}
if(r=='h'){
cout<<"enter labname"<<endl;
cin>>entname;
list3.book(entname);

}


}
if(op==8){
cout<<"to  unbook rooms press-r"<<endl;
cout<< "to  unbook labs press-l"<<endl;
cout<<"to  unbook lec halls press-h"<<endl;
cin>>r;

if(r=='r'){
  cout<<"enter room name"<<endl;
cin>>entname;
Roomlist.unbook(entname);
}
if(r=='l'){
cout<<"enter labname"<<endl;
cin>>entname;
list2.unbook(entname);


}
if(r=='h'){
cout<<"enter labname"<<endl;
cin>>entname;
list3.unbook(entname);

}


}
if(op==5){
cout<<"enter no of students"<<endl;
cin>>es;
list3.givenstudents(es);
}
if(op==4){cout<<"enter no of students"<<endl;
cin>>es;
Roomlist.minirooms(es);
}
if(op==6){
cout<<"to find lab with least density press- l";
cout<<"to update the lab equipment of any lab press-r";
cin>>r;
if(r=='l'){

cout<<"the lab with least density is";
list2.leastdensity();}
if(r=='r'){
cout<<"enter the lab name"<<endl;
cin>>entname;
cout<<"enter the updated equipment number"<<endl;
cin>>es;
cout<<"equipment updated"<<endl;
}
}
if(op==7){

cout<<"enter the x and y cordinates of the given location"<<endl;
cin>>ex;
cin>>ey;

Roomlist.leastdistance(ex,ey);
}
if(op==9){

cout<<"to print room details press-r"<<endl;
cout<< "to print lab details press-l"<<endl;
cout<<"to print lec halls details press-h"<<endl;
cin>>r;

if(r=='r'){
  cout<<"enter room name"<<endl;
cin>>entname;
Roomlist.printr(entname);
}
if(r=='l'){
cout<<"enter labname"<<endl;
cin>>entname;
list2.printr(entname);


}
if(r=='h'){
cout<<"enter labname"<<endl;
cin>>entname;
list3.printr(entname);


}

}
if(op==10){
cout<<"exiting the program"<<endl;
list3.Print();
list2.Print();
Roomlist.Print();
break;

}






}

  //list3.Print();    

 
}
