// testando lista com clock, maquina, Log,IO(Maquina in/ interface out)
#include <iostream>
#include <string>

#include "structDatetime.h"
#include "Maquina.cpp"
#include "Clock.cpp"
#include "Calendar.cpp"
#include "Node.cpp"


#include "interface.cpp"
#include "interface_pc.cpp"
#include "ClockCalendar.cpp"
#include "Log.cpp"

#include "Td.cpp"
#include "Lt.cpp"
#include <chrono>
#include <thread>

using namespace std;

int main(){
	int b=3;
		
	Maquina* m=new Maquina(2019, 6, 30, 11, 59, 55, true);
	//m= Maquina(2019, 6, 30, 11, 59, 55, true);
	
	ClockCalendar* c=new ClockCalendar(2019, 6, 30, 11, 59, 55, true);
//	ClockCalendar* c(2019, 6, 30, 11, 59, 55, true);;
	Interface* i;
	i=new Interface_pc();
	
	
	// ----- setando propriedades de nodo nos objetos
    i->setthreadname("interface azul");
    i->setkey(128);
    
    c->setthreadname("clock calendar amarelo");
    c->setkey(47);
    
    m->setthreadname("maquina marrom");
    m->setkey(11);
    // fim de ----- setando propriedades de nodo nos objetos
  
  	Lt lt;
 	Td*  th=new Td(b,"Thread Generica A");
	lt.addNodo(th);
	
	Td*  th2=new Td(b*2,"Thread Generica B");
	lt.addNodo(th2);
	
	lt.printList();
	
	cout<<"\n\n";
	
	lt.addNodo(i);
	lt.addNodo(c);
	lt.addNodo(m);
	
	
	
	lt.printList();

	
	return 0;
}
