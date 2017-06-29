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
#include <fstream>
#include <string>
#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pigpio.h>
#include <sched.h>
#include "control_v2.h"
#include "sensing.h"
#include "ESCdriver.h"

//http://abyz.co.uk/rpi/pigpio/cif.html
//http://arma.sourceforge.net/docs.html
//http://eigen.tuxfamily.org/index.php?title=Main_Page
//http://www.simunova.com/node/33
int airborn=0;
int ison=0;
using namespace std;
int main(){
	int volatile button=42;
	init();
	    fstream reader("/var/www/html/text.txt");
//flag to readings.txt called ofile
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
standard_forward();
usleep(760000); //sleeping for the time needed to travel 0.5 meter
	hover_q();
	 break;
	case 2 :
standard_left();
	usleep(760000);
	hover_q();
	break;
	case 3 :
standard_right();
usleep(760000);
	hover_q();
	break;
	case 4 :
  standard_backward();
  usleep(760000);
	hover_q();
	break;
case 5 :
standard_yaw();
		
	break;
case 6 :
standard_up();
usleep(76000); 
	hover_q();		
	break;
case 7 :
standard_down();
	usleep(76000);
	hover_q();
	break;
case 8 :
u1offest++;
hover_q();
usleep(10000); //overwrting protection remaining the control loop at frequency
			
break;
case 9 :
u1offest--;
hover_q();
usleep(10000);
break;
 /*case 10 :
//changing range
global_pwmhov=(get_pwmR()*global_pwmhov)/100;
set_motorSettings(100);
 break; */
/*case 11 :

break; */
/*case 12 :

break; */
case 13:
hover_q();
usleep(760000);
case 14:
stop();
break;

case 42:
break;
	}

}
	return 0;
}
