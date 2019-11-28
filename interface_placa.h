// interface_placa.h
#ifndef INTERFACEPLACAH
#define INTERFACEPLACAH

#include "interface.cpp"

class Interface_placa: public Interface{
	
	
	public:
	//	Interface_pc();
		void solve(string str);
		void registralog(string addbebida,string addpreco){
		}
		void addlistavendas(Node* nodo);
		
		Log getlog();
		
};

#endif
