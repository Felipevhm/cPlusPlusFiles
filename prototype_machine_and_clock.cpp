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

// Cherno's code    -   https://www.youtube.com/watch?v=wXBcwHwIt_I
static bool s_end=false;

void fnn(){
	using namespace std::chrono;
	int t=0;
	while(!s_end){
		std::this_thread::sleep_for(std::chrono::seconds(1));
		system("cls");
		
		
		// inicio menu
		
		cout<<"--------- Vending Machine ---------"<<endl;
		cout<<"Autor: Felipe Vianna Hissa Manhaes"<<endl;
		
		cout<<"-----------------------------------"<<endl;
		cout<<"1 - Adiciona R$0,25;\n"<<"2 - Adiciona R$0,50;\n"<<"3 - Adiciona R$1,00;\n"
			<<"\n4 - Devolve moeda;\n"<<"\n5 - Meet;\n"<<"6 - Etirps;\n"<<"\n7 - Ajuda;\n"<<"\n8 - Admin;\n";
		cout<<"-----------------------------------\n"<<endl;
	//	saldo();
	
	std:cout<<"Relogio:"<<t<<"\n";
		cout<<"-----------------------------------\n"<<endl;
		cout<<"Escolha uma opcao: ";
		
		//fim menu
		
		
	//	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	//	std::this_thread::sleep_for(1);
	t++;
	}
};

int main(){ 
	int a;
	std::thread work(fnn);
	std::cin>>a;
	
	s_end=true;
		work.join();
		
	cout<<"finished, valor de 'a' == "<<a<<endl;

	std::cin.get();
	
	
	
}
	
	












/*
void cs(int b){
	
	while (b==9){
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
			cout<<"...\n"<<endl;
	}

}



int main(){
int b=9;
	thread t1(cs,b);
	//t1.join();
cin>>b;
//if (b=="k"){
	
//	return 0;
//}
	
	return 0;
}
*/
