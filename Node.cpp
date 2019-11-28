#ifndef NODECPP
#define NODECPP

#include "Node.h"
#include "structDatetime.h"

  Node::Node(){
    key = 0;
    data = 0;
    str=" ";
    next = NULL;
    previous = NULL;
  };
  Node::Node(int k, int d) {
    key = k;
    data = d;
    str=" ";
    next = NULL;
    previous = NULL;
  };
    Node::Node(int k, string st) {
    key = k;
    data=0;
    str = st;
    next = NULL;
    previous = NULL;
  };

  Node::Node(int k, string st, dttime dtt) {
    key = k;
    data=0;
    str = st;
    next = NULL;
    previous = NULL;
    dt=dtt;
  };

  
  // --------------------------------
  // datetime
    dttime Node::getdt(){
  	return dt;  	
  };
    void Node::setdt(dttime dtt){
    	dt=dtt;
	};
  
  
    //key
  int Node::getkey(){
  	return key;  	
  };
  
  void Node::setkey(int newkey){
  	key=newkey;
  	
  };
  
// --------------------------------
  
   //data
  int Node::getdata(){
  	return data;
  };
  
  void Node::setdata(int newdata){
  	data=newdata;
  	
  };
  
  // --------------------------------
  
  //next
  Node* Node::getnext(){
  	return next;  	
  };
  
  void  Node::setnext(Node* newnext){
  	next=newnext;  	
  };
  
  // --------------------------------
  
   //previous
  Node* Node::getprev(){
  	return previous;
  };
  
  void  Node::setprev(Node* newprev){
  	previous=newprev;
  };
  
     //string str
  string Node::getstr(){
  	return str;
  };
  
  void  Node::setstr(string newstr){
  	str=newstr;
  };
  
  #endif


