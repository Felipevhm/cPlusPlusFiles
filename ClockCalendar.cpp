
#ifndef CLOCKCALENDARCPP
#define CLOCKCALENDARCPP


#include <iostream>
#include "ClockCalendar.h"
#include "Clock.cpp"
#include "Calendar.cpp"
#include "Td.cpp"
#include "structContexto.h"


using namespace std;

ClockCalendar::ClockCalendar (unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec, bool isPM)
	: Clock (hour, min, sec, isPM), Calendar (year, month, day) , Td(){

}

ClockCalendar::~ClockCalendar () { }

void ClockCalendar::advance () {
	bool wasPm = Clock::isPM; // save current pm.
	Clock::advance();
	if ((wasPm == true) && (Clock::isPM == false))
		Calendar::advance();
}

void ClockCalendar::run(int counter){
		int i=0;
	
		unsigned int year, month, day, hour, min, sec;
		bool isPM;
	
		bool secondAdvanced = false;
		time_t now, elapsed;
		double seconds;
		
		
	
		while (1) { //keeprun
		
			// ----PART 1 de 3 --- Condition checker
			secondAdvanced = false;
			time(&now);
			while (!secondAdvanced) {
				time(&elapsed);
				seconds = difftime(elapsed, now);
				if (seconds == 1) {
					secondAdvanced = true;
			// ----PART 2 de 3--- Advance
					advance();
			
		
					readCalendar(year, month, day);
					readClock(hour, min, sec, isPM);
					
			// ----PART 3 de 3 ---  Print da hora
					cout << setw(4) << setfill('0') << year;
					cout << "/";
					cout << setw(2) << setfill('0') << month;
					cout << "/";
					cout << setw(2) << setfill('0') << day;
					cout << " - ";
					cout << setw(2) << setfill('0') << hour;
					cout << ":";
					cout << setw(2) << setfill('0') << min;
					cout << ":";
					cout << setw(2) << setfill('0') << sec;
					cout << (isPM ? " pm" : " am") << endl;
					
					i++;
				}
			}
		}
		// buffer flush 
	    cout.flush ();
		
	
}
#endif
