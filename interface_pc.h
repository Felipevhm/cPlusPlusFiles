// interface_pc.h


#ifndef INTERFACEPC_H
#define INTERFACEPC_H

#include "interface.cpp"
#include "ClockCalendar.cpp"
class Interface_pc: public Interface{
	
	
	public:
		Node* generico;

		void solve(string str, ClockCalendar cc);
		void registralog(unsigned int ano,unsigned int mes,unsigned int dia,unsigned int hora,unsigned int minuto,unsigned int segundo,bool epm,string addbebida,string addpreco);
		void addlistavendas(Node* nodo);
		Log getlog();
};

#endif
