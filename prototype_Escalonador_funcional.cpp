#include <iostream>
#include <string>
#include "structContexto.h"

using namespace std;

typedef struct contexto{
   int enabled;
   string stts;
   int prgs;
		
	}contexto;
	
	class Thread{
		protected:
    bool reponse;
	string threadname="<A>";
	contexto ctx1;

	string status;
	int enabled=1;
	int progress=1;
		
			
		public:
		
	};	

string change_status(string sts,string newstatus){
	
	if (newstatus=="blocked"){
	sts="blocked";
	}
	else 
	if (newstatus=="ready"){
	sts="ready";
	}
	
	return sts;
	
}

contexto fcn(contexto ctx,int enabled,string threadname){
	int progress;
	string status;
	
	progress=ctx.prgs;
	status=ctx.stts;
	
	
	while (enabled){
		
		 if(status=="blocked"){
	 		cout<<"\n!NOTIFICATION!: Thread esta bloqueada\n"<<endl;
	 	
	 		ctx.prgs=progress;
	  	    ctx.stts="blocked_notified";
	  	    return ctx;
	  	    break;
	    
	 	}
	 
		
		switch(progress){
			
			case 1:
				cout<< "Linha de codigo 1 de 3 executada com sucesso!\n"<<endl;
				break;
			case 2:
				cout<< "Linha de codigo 2 de 3 executada com sucesso!\n"<<endl;
				break;
			case 3:
				cout<< "Linha de codigo 1 de 3 executada com sucesso!\n"<<endl;
				break;
			default:
				progress=0;
				break;
			
		}
		
		cout<< "saiu do switch "<<endl;
		progress++;
		status=change_status(status,"blocked");	
		
		if (status=="blocked"){
			break;
		}
	}
	
	cout<< "saiu do while "<<endl;
	cout<<"escalonador terminou etapa "<<ctx.prgs<<" da thread "<<threadname<<endl;
	
	ctx.prgs=progress;
	ctx.stts=status;
	
	return ctx;
	
}

int main(){
	// thread 
	bool reponse;
	string threadname="<A>";
	contexto ctx1;
	ctx1.prgs=1;
	ctx1.stts="ready";
	
	string status;
	int enabled=1;
	int progress=1;
	
	
	while(progress<4){
		cout<< "------------------- parte "<<ctx1.prgs<<" de 3 ------------------ "<<endl;
		ctx1=fcn(ctx1,enabled,threadname);
		cout<< "saiu da subthread\n "<<endl;
		
		if (ctx1.prgs==4){     //condicao de parada 
			cout << "Thread "<<threadname<<" concluida em suas 3 parcelas."<<endl;
			break;
		}
		
		cout<< "progress== "<<ctx1.prgs<<endl;
		cout<< "status== "<<ctx1.stts<<endl;
		
		if(ctx1.stts=="blocked_notified"){
			cout<<"Gostaria de desbloquear a thread "<<threadname<<"?"<<endl;
			cout<<"0 - nao | 1 - sim"<<endl;	
			
			cin>>reponse;
			if (reponse ==1){
				ctx1.stts="ready";}
				
			else{
			//	system("cls");
			ctx1.stts="blocked";
			}
				
			
		}
	
	//check priority()

	}
		
	return 0;
}
