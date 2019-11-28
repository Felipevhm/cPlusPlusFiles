// interface_pc.cpp

#ifndef INTERFACEPC_CPP
#define INTERFACEPC_CPP

#include "structDatetime.h"
#include "interface_pc.h"


Log Interface_pc::getlog(){
	return lg;
};

void Interface_pc::addlistavendas(Node* nodo){  

	listavendas.addNodo(nodo);
	listavendas.printList();

};

void Interface_pc::registralog(unsigned int ano,unsigned int mes,unsigned int dia,unsigned int hora,unsigned int minuto,unsigned int segundo,bool epm,string addbebida,string addpreco){ // Registra venda em nível de Interface
	
	generico=lg.registravenda(ano,mes,dia,hora,minuto,segundo,epm,addbebida,addpreco);
	
	addlistavendas(generico);
	};
	
	
	
void Interface_pc::solve(string str,ClockCalendar cc){
		unsigned int h, min, sec;
		bool ispm;
		unsigned int y, mnth,d;
		cc.readCalendar(y,mnth,d);
		cc.readClock(h,min,sec,ispm);
		

		if (str=="dev025"){
			system("CLS");
			cout<< "\n\n----------R$ 0,25 devolvidos----------\n"<<endl;
			
		}
		else if (str=="dev050"){
			system ("CLS");
			cout<< "\n\n----------R$ 0,50 devolvidos----------\n"<<endl;
			
		}
		else if (str=="dev075"){
			system ("CLS");
			cout<< "\n\n----------R$ 0,75 devolvidos----------\n"<<endl;
			
		}
		else if (str=="dev100"){
			system ("CLS");
			cout<< "\n\n----------R$ 1,00 devolvidos----------\n"<<endl;
			
			
		}
		else if (str=="dev125"){
			system ("CLS");
			cout<< "\n\n----------R$ 1,25 devolvidos----------\n"<<endl;
					
		}
		else if (str=="dev150"){
			system ("CLS");
			cout<< "\n\n----------R$ 1,50 devolvidos----------\n"<<endl;
					
		}
		else if (str=="meet"){
			system ("CLS");
			cout<< "\n\n---------- 1 REFRIGERANTE - MEET - _Liberado_ ----------\n"<<endl;
			registralog(y,mnth,d,h,min,sec,ispm,str,"R$1,50");
				
		}
		else if (str=="etirps") {
			system ("CLS");
			cout<< "\n\n---------- 1 REFRIGERANTE - ETIRPS - _Liberado_ ----------\n"<<endl;
			registralog(y,mnth,d,h,min,sec,ispm,str,"R$1,50");
			
					
		}
		else {
        cout << str << endl;	
		}
	};
	
#endif



