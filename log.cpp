#ifndef LOGCPP
#define LOGCPP

#include "log.h"
#include "Clock.cpp"



Log::Log(){
	
		loghour=8;
		logmin=27;
		logsec=05;
		logisPM=0;
		logyear=2019;
		logmonth=11;
		logday=7;
		totalsold=0;
		totalmeet=0;
		totaletirps=0;
		refri=preco=datahora=" ";
		max=0;
	
}

Node* Log::registravenda(unsigned int ano,unsigned int mes, unsigned int dia,unsigned int hora,unsigned int minuto, unsigned int segundo,bool epm,string addbebida,string addpreco)
{
	int max=0;
	int hh,i;
	stringstream output,datetime;
	dttime timedt; 
	
	timedt.year=ano;
	timedt.month=mes;
	timedt.day=dia;
	
	timedt.hour=hora;
	
	// ----------HORA COM MAIS VENDAS ------------
	
	for (i=0;i<24;i++){
		
		if (hora==i){
			if(!epm&&hora==12){
				hh=hora-12;
				cout<<"hora: "<<hh<<endl;
			}
				
			else if(!epm&&hora<12) {
				hh=hora;	
				cout<<"hora: "<<hh<<endl;
			}
			
			if(epm&&hora==12){
				hh=hora;
				cout<<"hora: "<<hh<<endl;
			}
				
			else if(epm&&hora<12) {hh=hora;
				hh=hora+12;
				cout<<"hora: "<<hh<<endl;
			}
			timeslist[hh]++;
			if (timeslist[hh]>max){
				max=hh;
			}
				
				
				
			
				
		   	
		}   }
	
	// ------FIM-------HORA COM MAIS VENDAS -----
	
	
	
	timedt.minute=minuto;
	timedt.second=segundo;
	timedt.pm=epm;
	
	datetime<< setw(2) << setfill('0') << dia<<"/"<<setw(2) << setfill('0') << mes<<"/"<<setw(4) << setfill('0') << ano<<
	" - "<< setw(2) << setfill('0') <<hora<< ":"<< setw(2) << setfill('0') << minuto<< ":"<< setw(2) << setfill('0') <<segundo
	<< (epm? " pm" : " am");
	
	datahora=datetime.str();
	
	refri=addbebida;
	preco=addpreco;
	
	output<<datahora<<"- Refrigerante:"<<addbebida<<"- Preco:"<<addpreco;
	totalsold++;
	
	if (addbebida=="meet"){
		totalmeet++;
	}
	
	else{
		totaletirps++;
	}
	cout<<"totalsold __ : "<<totalsold<<endl;
	Node* n1 = new Node(totalsold,output.str(),timedt);
	
	return n1;
};

int Log::gettotalmeet(){
	return totalmeet;
	
};

int Log::gettotaletirps(){
return totaletirps;
};

int Log::gettotalsold(){
return totalsold;
};

//max
int Log::getmax(){
	return max;
};

void Log::setmax(unsigned int newmax){
	max=newmax;
};

//times list
int Log::gettimeslist(int gotoindex){
	return timeslist[gotoindex];
};

void Log::settimeslist(int gotoindex,int newtimeslist){
	timeslist[gotoindex]=newtimeslist;
};


int Log::getlogyear(){
	return logyear;
};

void Log::setlogyear(unsigned int newlogyear){
	logyear=newlogyear;
};

int Log::getlogmonth(){
	return logmonth; 
};
void Log::setlogmonth(unsigned int newlogmonth){
	logmonth=newlogmonth;
};

//---------------------------------------
int Log::getlogday(){
	return logday;
};
void Log::setlogday(unsigned int newlogday){
	logday=newlogday;
};
//---------------------------------------
unsigned int Log::getloghour(){
	return loghour;
};
void Log::setloghour(int newloghour){
loghour=newloghour;
};
//---------------------------------------	
unsigned int Log::getlogmin(){
	return logmin;
};
void Log::setlogmin(int newlogmin){
	logmin=newlogmin;
};
//---------------------------------------
unsigned int Log::getlogsec(){
	return logsec;
};
void Log::setlogsec(int newlogsec){
	logsec=newlogsec;
};
//---------------------------------------
bool Log::getlogisPM(){
	return logisPM;
};
void Log::setlogisPM(bool newlogisPM){
	logisPM=logisPM;
};

#endif

