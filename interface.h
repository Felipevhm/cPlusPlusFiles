// Interface.h

#ifndef INTERFACE
#define INTERFACE

#include <iostream>
#include <string>
#include "Log.cpp"
//#include "Clock.cpp"
#include "Calendar.cpp"
#include "ClockCalendar.cpp"

class Interface: public Td{
	protected:
	string in;
	
	Log lg;
	ListaDE listavendas;
	
	public:
	virtual	void  solve(string str,ClockCalendar cc); 
	virtual void addlistavendas();
	virtual Log getlog();
	
	
	//	string getin(); 
};

#endif


