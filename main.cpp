//============================================================================
// Name        : Quad.cpp
// Author      : Amr Mohammed Kamal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// using 9 buttons the quad will move foreward backward right left , up and down
	// eac resolution is 20 Cm , also roll pitch yaw with 10 degree resoultion
	//https://github.com/metachris/RPIO/tree/master/source/c_pwm
//the fork() Function. The fork() function is used to create a new process by duplicating the existing process
//from which it is called. The existing process from which this function is called
//becomes the parent process and the newly created process becomes the child process
//============================================================================

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pigpio.h>
#include <sched.h>
#include "control_v0.h"

//http://abyz.co.uk/rpi/pigpio/cif.html
//http://arma.sourceforge.net/docs.html
//http://eigen.tuxfamily.org/index.php?title=Main_Page
//http://www.simunova.com/node/33
using namespace std;
int main(int argc){
	cpu_set_t  mask;
	CPU_ZERO(&mask);
	CPU_SET(3, &mask);
	(void) sched_setaffinity(0, sizeof(mask), &mask); //make it void
	gpioInitialise();
	get_motorSettings();
	set_motorsettings();
while (1){
	switch (argc){
// get button from php to call this code and execute the function
	case 1 :
 //starting off
 hover_q(); break;
	case 2 :
		standard_forward();break;
	case 3 :
   standard_backward();break;
	case 4 :
standard_right();break;
	case 5 :
standard_left();break;
case 6 :
standard_up();break;
case 7 :
standard_down();break;
case 8 :
standard_yaw();break;
case 9 :
land_q();break;
case 10 :
fullstop();break;

	}

}
	return 0;
}
