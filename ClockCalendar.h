#ifndef CLOCKCALENDAR
#define CLOCKCALENDAR

#include <iostream>
#include "Clock.h"
#include "Calendar.h"
#include "Td.h"

#include <time.h>
#include <iomanip>
#include "structContexto.h"


using namespace std;

class ClockCalendar : public Clock, public Calendar,public Td {
	public:
		ClockCalendar (unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec, bool isPM);
		~ClockCalendar ();
		void advance ();
		void run(int counter);
		void loadcontext(){}
		Contexto savecontext(){
		Contexto cn;
        }
		
};

#endif		// CLOCKCALENDAR
