// Node.h

#ifndef NODE
#define NODE

#include <iostream>
#include <string>
using namespace std;

#include "structDatetime.h"

class Node {
  int key;
  int keycounter;
  int data;
  string str;
  Node * next;
  Node * previous;
  dttime dt;
  
    public:
  Node();
  Node(int k, int d);
  Node(int k, string st);
  Node(int k, string st, dttime dtt);
  
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
  Node* getnext();
  void  setnext(Node* newnext);
  
   //previous
  Node* getprev();
  void  setprev(Node* newprev);
  
  // string str
  string getstr();
  void  setstr(string newstr);
  
  
};

#endif
