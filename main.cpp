	  			  /*cout<<" __      __            _ _               __  __            _     _             "<<endl;      
				 	cout<<" \ \    / /           | |_|             |  \/  |          | |   |_|            "<<endl;            
					cout<<"  \ \  / /__ _ __   __| |_ _ __   __ _  | \  / | __ _  ___| |__  _ _ __   ___  "<<endl; 
					cout<<"   \ \/ / _ \ '_ \ / _` | | '_ \ / _` | | |\/| |/ _` |/ __| '_ \| | '_ \ / _ \ "<<endl; 
					cout<<"    \  /  __/ | | | |_| | | | | | |_| | | |  | | |_| | |__| | | | | | | |  __/ "<<endl; 
					cout<<"     \/ \___|_| |_|\__,_|_|_| |_|\__, | |_|  |_|\__,_|\___|_| |_|_|_| |_|\___| "<<endl; 
					cout<<"                                  __/ |                                        "<<endl; 
					cout<<"                                 |___/                                         "<<endl; */
	

//                                         Projeto Final - Felipe Manhães ---------- MAIN -------------
#include "structDatetime.h"
#include "Maquina.cpp"
#include "Clock.cpp"
#include "Calendar.cpp"
#include "Node.cpp"


#include "interface.cpp"
#include "ClockCalendar.cpp"
#include "Log.cpp"
using namespace std;
int main(){
	
	int ans=0;
	Maquina maq= Maquina(2019, 6, 30, 11, 59, 55, true);

	maq.mainmaq();

	return(0);
}
