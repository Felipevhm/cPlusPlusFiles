#ifndef TD_CPP
#define TD_CPP

#include "Td.h"
#include "structDatetime.h"

  Td::Td(){
    key = 0;
    data = 0;
    str=" ";
    next = NULL;
    previous = NULL;
    
	cx.key=0;
	cx.enabled=0;
	cx.stuts="";
	cx.prgss=0;
	cx.reponse=0;
	cx.threadname="< >";
	cx.status="created";
	cx.enabled=1;
	cx.progress=1;
  };
  Td::Td(int k, int d) {
    key = k;
    data = d;
    str=" ";
    next = NULL;
    previous = NULL;
    
	cx.key=0;
	cx.enabled=0;
	cx.stuts="";
	cx.prgss=0;
	cx.reponse=0;
	cx.threadname="< >";
	cx.status="created";
	cx.enabled=1;
	cx.progress=1;
  };
    Td::Td(int k, string st) {
    key = k;
    data=0;
    str = st;
    next = NULL;
    previous = NULL;
    
	cx.key=0;
	cx.enabled=0;
	cx.stuts="";
	cx.prgss=0;
	cx.reponse=0;
	cx.threadname=st;
	cx.status="created";
	cx.enabled=1;
	cx.progress=1;
  };

  Td::Td(int k, string st, dttime dtt) {
    key = k;
    data=0;
    str = st;
    next = NULL;
    previous = NULL;
    dt=dtt;
  };

// -----------------------------
Contexto Td::context(){
		return cx;
	};
  
// --------------------------------
  // datetime
    dttime Td::getdt(){
  	return dt;  	
  };
    void Td::setdt(dttime dtt){
    	dt=dtt;
	};
  
  
    //key
  int Td::getkey(){
  	return key;  	
  };
  
  void Td::setkey(int newkey){
  	key=newkey;
  	
  };
  
// --------------------------------
  
   //data
  int Td::getdata(){
  	return data;
  };
  
  void Td::setdata(int newdata){
  	data=newdata;
  	
  };
  
  // --------------------------------
  
  //next
  Td* Td::getnext(){
  	return next;  	
  };
  
  void  Td::setnext(Td* newnext){
  	next=newnext;  	
  };
  
  // --------------------------------
  
   //previous
  Td* Td::getprev(){
  	return previous;
  };
  
  void  Td::setprev(Td* newprev){
  	previous=newprev;
  };
  
     //string str
  string Td::getstr(){
  	return str;
  };
  
  void  Td::setstr(string newstr){
  	str=newstr;
  };
  
//THREAD name
  string Td::getthreadname(){
  	return cx.threadname;
  };
  
  void  Td::setthreadname(string newthreadname){
  	cx.threadname=newthreadname;
  };
  
  #endif


