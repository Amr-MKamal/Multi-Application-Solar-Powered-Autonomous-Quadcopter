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
#include "stdafsx.h"
#include <fstream>
#include <string>
#include <sstream>
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
int airborn=0; 
int ison=0; 
using namespace std;
int main(){
	cpu_set_t  mask;
	CPU_ZERO(&mask);
	CPU_SET(3, &mask);
	(void) sched_setaffinity(0, sizeof(mask), &mask); //make it void
	int volatile button=42;
	init();
    fstream ofile;
	//open readings.tx/var/www/html/text.txtt
    string line;
while (1){
	 ofile.open("/home/pi/Desktop/webips.txt", ios::in );

	//read data from file readings.txt
    getline(ofile, line) ;
    button=atoi(line.c_str());
	//close file
	ofile.close();
	//open file again and clear its previos contents
	ofile.open("/home/pi/Desktop/webips.txt", ios::out|ios::trunc);
	//write data to the file
    ofile << "42";
	//close the file
    ofile.close();

	switch (button){
// get button from php to call this code and execute the function
	case 1 :
if(ison){standard_forward();}
	 if(!airborn){airborn=1;}
	 break;
	case 2 :	
if(ison){standard_left();}
	 if(!airborn){airborn=1;}break;
	case 3 :
if(ison){standard_right();}
			
	 if(!airborn){airborn=1;}break;
	case 4 :
if(ison){standard_backward();}
	 if(!airborn){airborn=1;}break;	
case 5 :
if(ison){standard_yaw();}
	 if(!airborn){airborn=1;}break;	
case 6 :
if(ison){standard_up();}
	 if(!airborn){airborn=1;}break;
case 7 :
if(ison){standard_down();}
	 if(!airborn){airborn=1;}break;
case 8 :
testincrease();break;
case 9 :
testdecrease();break;

case 10 :
//changing range	
global_pwmhov=(get_pwmR()*global_pwmhov)/100;
set_motorSettings(100);
break;
case 11 :
//changing range	
global_pwmhov=(get_pwmR()*global_pwmhov)/255;
set_motorSettings(255);
break;
case 12 :
//changing range	
global_pwmhov=(get_pwmR()*global_pwmhov)/1000;
set_motorSettings(1000);
break;
case 13:
ison=1;break;
case 14:
	ison=0;
 if(airborn)
 {
	 land_q();
 airborn=0;
 }
			break;
			
		case 42:
			break;
	}
	

}
	return 0;
}
