// Node.h

#ifndef TD_H
#define TD_H

#include <iostream>
#include <string>
using namespace std;
#include "structContexto.h"
#include "structDatetime.h"

class Td {
  Contexto cx;
  int key;
  int keycounter;
  int data;
  string str;
  Td * next;
  Td * previous;
  dttime dt;
  
    public:
  Td();
  Td(int k, int d);
  Td(int k, string st);
  Td(int k, string st, dttime dtt);
  
  Contexto context();
  dttime getdt();
  void setdt(dttime dtt);

 
 // --------------------------------
  
  //key
  int getkey();
  void setkey(int newkey);
  
   //data
  int getdata();
  void setdata(int newdata);
  
  //next
  Td* getnext();
  void  setnext(Td* newnext);
  
   //previous
  Td* getprev();
  void  setprev(Td* newprev);
  
  // string str
  string getstr();
  void  setstr(string newstr);
  
 // thread name
  string getthreadname();
  void  setthreadname(string newthreadname);
  
  
};

#endif
