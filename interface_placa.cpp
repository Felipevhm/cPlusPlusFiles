// interface_placa


#ifndef INTERFACEPLACACPP
#define INTERFACEPLACACPP

#include "interface_placa.h"
Log Interface_placa::getlog(){
	return lg;
};

void Interface_placa::addlistavendas(Node* nodo){  

	listavendas.addNodo(nodo);
	listavendas.printList();

	
};


void Interface_placa::solve(string str){

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
			registralog(str,"R$1,50");
				
		}
		else if (str=="etirps") {
			system ("CLS");
			cout<< "\n\n---------- 1 REFRIGERANTE - ETIRPS - _Liberado_ ----------\n"<<endl;
			registralog(str,"R$1,50");
					
		}
		else {
        cout << str << endl;	
		}
	};

#endif
