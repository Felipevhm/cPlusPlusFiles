// Maquina.cpp

#include <string>
#include "Maquina.h"
#include "interface.h"
#include "interface_placa.cpp"
#include "interface_pc.cpp"
#include "ClockCalendar.h"
#include "Interface.cpp"

#include <chrono>
#include <thread>
//#define raspberry

#define Computer

using namespace std;

Maquina::Maquina(unsigned int year, unsigned int month, unsigned int day, 
	unsigned int hour, unsigned int min, unsigned int sec, bool isPM)
    :clk(year,month,day,hour,min,sec,isPM)
{
	#ifdef Computer
	 itfc=new Interface_pc();
	#endif
	
	#ifdef Placa
	 itfc=new Interface_placa();
	#endif
	
    input = "zero";
    out = "d000";
    state = 0;
   
    display_out=0;
};

void Maquina::mainmaq(){
	char answer;
	while(1){
		
	printmenu();
	cin>>answer;
	maqout(answer);

	system("CLS");
	}
	
};

void Maquina::printmenu(){
	
    cout<<"--------- Vending Machine ---------"<<endl;
	cout<<"Autor: Felipe Vianna Hissa Manhaes"<<endl;
	
	cout<<"-----------------------------------"<<endl;
		cout<<"1 - Adiciona R$0,25;\n"<<"2 - Adiciona R$0,50;\n"<<"3 - Adiciona R$1,00;\n"
		<<"\n4 - Devolve moeda;\n"<<"\n5 - Meet;\n"<<"6 - Etirps;\n"<<"\n7 - Ajuda;\n"<<"\n8 - Admin;\n";
	cout<<"-----------------------------------\n"<<endl;
	saldo();
	cout<<"-----------------------------------\n"<<endl;
	cout<<"Escolha uma opcao: ";
	};

void Maquina::maqout(char ans){
	
		switch(ans){
		case '1':
			change_input("m025");
			sell();
			break;
		case '2':
			change_input("m050");
			sell();
			
			break;
		case '3':
			change_input("m100");
			sell();
			
			break;
			
		case '4':       
			change_input("dev");
			sell();
			
			
			break;
		case '5':
			change_input("meet");
			sell();
		
			
			break;
		case '6':
			change_input("etirps");
			sell();
			
			break;
			
		case '7':
			system("CLS");
			cout<<"\n\n\n ------------- Area em desenvolvimento ------------- \n\n\n";
			system ("PAUSE");
			system("CLS");
			
			break;
		case '8':
			runadmin();
		
		default:
			break;
	}
};



void Maquina::change_state(int newstate){
	state=newstate;	
}
void Maquina::change_input(string newin){
	input=newin;
}

void Maquina::saldo(){
	cout.precision(2);
	cout<<"\nSaldo: R$"<<fixed<<(float) state/100<<"    ------------------\n\n"<<endl;
}

int Maquina::get_state(){
	return state;
}
string Maquina::get_input(){
	return input;
}
bool Maquina::get_display_out(){
	return display_out;	
}

void Maquina::runadmin(){
	int contadordelete=0;
	int ans,i,hmax;
	int max=0;
	do{
	system("CLS");
	cout<<"------------Menu Admin-------------"<<endl;
	cout<<"1 - Listar valor total de vendas;\n\n"<<"2 - Relacao de vendas por refrigerante;\n\n"<<"3 - Listar o periodo do dia com mais vendas;\n\n"
	<<"4 - Sair do Admin;\n";
	
	cout<<"-----------------------------------\n"<<endl;
	cout<<"Escolha uma opcao: ";
	cin>>ans;
	
	switch(ans){
		
		case 1:
			cout<< "\n\n---------- Opcao 1 - Listar valor total de vendas; ----------\n"<<endl;
			
			cout<<"\n\nTotal de Meet: R$"<< fixed<<(float) (itfc->getlog().gettotalmeet())*1.5<<endl;
			cout<<"\n\nTotal de Etirps: R$"<<fixed<<(float) (itfc->getlog().gettotaletirps())*1.5<<endl;
			cout<<"-----------------------------------\n"<<endl;
			cout<<"\nTotal ganhos: R$"<<fixed<<(float) (itfc->getlog().gettotalsold())*1.5<<"\n\n";
			system("pause");
			break;
		
		case 2:
			cout<< "\n\n---------- Opcao 2 - Relacao de vendas por refrigerante; ----------\n"<<endl;
			cout<<"\n\nTotal de Meet: "<<itfc->getlog().gettotalmeet()<<endl;
			cout<<"Total de Etirps: "<<itfc->getlog().gettotaletirps()<<endl;
			system("pause");
			break;
		case 3:
			cout<< "\n\n---------- Opcao 3 - Listar o periodo do dia com mais vendas; ----------\n"<<endl;
			
			for (i=0;i<24;i++){
		
				if(itfc->getlog().gettimeslist(i)>max){
				max=itfc->getlog().gettimeslist(i);
				hmax=i;
				}
				cout<<i<<" hora(s): "<<itfc->getlog().gettimeslist(i)<<" vendas;"<<endl;
			}
			cout<<"-------------------------"<<endl;
			cout<<"O horario com mais vendas e':"<<hmax<<" horas"<<", com "<<max<<" venda(s)."<<endl;
			system("pause");
			break;
		
		case 5:
			{ unsigned int h,m,s;
			 bool ispm;
			clk.readClock(h,m,s,ispm);
			cout<<"Horario anterior:"<<endl;
			cout<<"Horas== "<<h<<" | Minutos== "<<m<<"| Segundos=="<<s<<endl;

			clk.advance();
			contadordelete++;
			
			clk.advance();
			contadordelete++;
			
			clk.advance();
			contadordelete++;
			
			clk.advance();
			contadordelete++;
			
			clk.advance();
			contadordelete++;
			
			clk.advance();
			contadordelete++;
			
			clk.advance();
			contadordelete++;
		
			cout<<"\n\n ClockC avancado "<< contadordelete<<" vez(es)!\n"<<endl;
	
			clk.readClock(h,m,s,ispm);
			cout<<"Horario atual:"<<endl;
			cout<<"Horas== "<<h<<" | Minutos== "<<m<<"| Segundos=="<<s<<endl;
			system ("PAUSE");
			
			break;
	}	
		
		default:
     	cout << "Input invalido " << endl;
	
	}	
	
		
	}while(ans!=4);
	  
    
	
};

void Maquina::sell(){
	switch(state){
	
		case (0):
			if (input=="m025"){
					state+=25;
				}
			else if (input=="m050"){
					state+=50;
				}
			else if (input=="m100"){
					state+=100;
				}
				cout<<state<<endl;
			break;
			
		case (25):
			if (input=="m025"){
				state+=25;
			}
	 		else if (input=="m050"){
				state+=50;
			}
			else if (input=="m100"){
				state+=100;
			}
			else if(input=="dev"){
			out="dev025";
			state=0;
			display_out=1;
			input="zero";
			}
		
			break;
				
		case (50):
				if (input=="m025"){
				state+=25;
				}
			else if (input=="m050"){
				state+=50;
			}
			else if (input=="m100"){
				state+=100;
			}
			else if(input=="dev"){
			out="dev050";
			state=0;
			display_out=1;
			input="zero";
		}
			
			break;
				
		case (75):
			if (input=="m025"){
				state+=25;
			}
			else if (input=="m050"){
				state+=50;
			}
			else if (input=="m100"){
				state+=75;
				out="dev025";
				display_out=1;
				input="zero";
			}
	 		else if(input=="dev"){
			out="dev075";
	 		state=0;
			display_out=1;
			input="zero";
			}
			
			
					break;
				
		case (100):
			if (input=="m025"){
				state+=25;
			}
			else if (input=="m050"){
				state+=50;
			}
			else if (input=="m100"){
				state+=50;
				out="dev050";
				display_out=1;
				input="zero";
			}
	 		else if(input=="dev"){
			out="dev100";
	 		state=0;
			display_out=1;
			input="zero";
			}
			
			break;
				
		case (125):
			if (input=="m025"){
				state+=25;
			}
			else if (input=="m050"){
				state+=25;
				out="dev025";
				display_out=1;
				input="zero";
			}
			else if (input=="m100"){
				state+=25;
				out="dev075";
				display_out=1;
				input="zero";
			}
	 		else if(input=="dev"){
			out="dev125";
	 		state=0;
			display_out=1;
			input="zero";
			}
			
			break;
				
		case (150):
			if (input=="m025"){
				out="dev025";
				display_out=1;
				input="zero";
			}
			else if (input=="m050"){
				out="dev050";
				display_out=1;
				input="zero";
			}
			else if (input=="m100"){
				out="dev100";
				display_out=1;
				input="zero";
			}
			
	 		else if(input=="dev"){
			out="dev150";
			state=0;
			display_out=1;
			input="zero";
			}
			
			else if(input=="meet"){
			out="meet";
			state=0;
			display_out=1;
			input="zero";
			}
			else if(input=="etirps"){
			out="etirps";
			state=0;
			display_out=1;
			input="zero";
			}
			
			break;
			
			
		default:
			
			break;
				}

	if (display_out==1){
	itfc->solve(out,clk);
	display_out=0;
    system ("PAUSE");
	system("CLS");
	
	}
}




