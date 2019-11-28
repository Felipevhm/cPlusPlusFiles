// log.h


#ifndef LOG
#define LOG

#include <iostream>
#include <time.h>
#include <iomanip>
#include <string> 
#include <sstream> 
#include "structDatetime.h"
#include "ClockCalendar.cpp"
#include "Clock.cpp"
#include "Calendar.cpp"
#include "ListaDE.cpp"



class Log{
	    protected:
		unsigned int loghour, logmin, logsec;
		bool logisPM;
		int logyear, logmonth, logday,totalsold,totalmeet,totaletirps,timeslist[24],max;
		string refri,preco,datahora;
		
		ListaDE lst;
		public:
	     Log();
		void cc_dream();
		
		void registerlogcc();
		
		Node* registravenda(unsigned int ano,unsigned int mes, unsigned int dia,unsigned int hora,unsigned int minuto, unsigned int segundo,bool epm,string addbebida,string addpreco);
		
		
		int getmax();
		void setmax(unsigned int newmax);
		int gettimeslist(int gotoindex);
		void settimeslist(int gotoindex,int newtimeslist);
		
		
		
		int getlogyear();
	    void setlogyear(unsigned int newlogyear);
		
		int getlogmonth();
		void setlogmonth(unsigned int newlogmonth);
	
	    int getlogday();
		void setlogday(unsigned int newlogday);
	
		unsigned int getloghour();
		void setloghour(int newloghour);
	
		unsigned int getlogmin();
		void setlogmin(int newlogmin);
	
		unsigned int getlogsec();
		void setlogsec(int newlogsec);
	
		bool getlogisPM();
		void setlogisPM(bool newlogisPM);
		
		int gettotalmeet();
		int gettotaletirps();
		int gettotalsold();
	

};

#endif


