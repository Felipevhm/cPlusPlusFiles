#ifndef MAQUINA
#define MAQUINA

#include <iostream>
#include <string>

#include "Td.cpp"
#include "Interface_pc.cpp"
#include "structDatetime.h"
#include "Interface.cpp"
#include "Interface_pc.cpp"




using namespace std;
class Maquina : public Td{
	Interface* itfc;
	string input;
	string out;
	int state;
	bool display_out;
	ClockCalendar clk;
   
    public:
   	
   	Maquina(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec, bool isPM);
    void sell();
    void change_state(int newstate);
    void change_input(string newin);
    int get_state();
    string get_input();
    void saldo();
    bool get_display_out();
    void runadmin();
    
    void mainmaq();
    void printmenu();
    void maqout(char ans);
    
};

#endif
