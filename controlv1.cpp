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

#include "control_v0.h"
#include "sensing.h"

//http://abyz.co.uk/rpi/pigpio/cif.html
//http://arma.sourceforge.net/docs.html
//http://eigen.tuxfamily.org/index.php?title=Main_Page
//http://www.simunova.com/node/33
using namespace std;
int global_pwmhov ;
int pwm_range=255;
#define default_pwm 255
(void) gpioInitialise();
void hover_q(void){
 (void)	gpioPWM(motor1,global_pwmhov);
 (void)	gpioPWM(motor2,global_pwmhov);
 (void)	gpioPWM(motor3,global_pwmhov);
 (void)	gpioPWM(motor4,global_pwmhov);
}
void standard_forward(void){
	//x=0 , y=1 , z=0 
	ydddesired=kdi*ydot+kpi*(yin-y)+kii*(yininter-yinter)
	
	
		(void)gpioPWM(motor1,global_pwmhov+1); //set time duration 0.4T
		(void)gpioPWM(motor3,global_pwmhov-1);
		gpioSleep(0,0,4000);
		hover_q();
		gpioSleep(0,0,1000);
		(void)gpioPWM(motor1,global_pwmhov+1);
		(void)gpioPWM(motor3,global_pwmhov-1);
		gpioSleep(0,0,1500);
		hover_q();
		gpioSleep(0,0,1500);
		(void)gpioPWM(motor1,global_pwmhov+1);
		(void)gpioPWM(motor3,global_pwmhov-1);
		gpioSleep(0,0,2000);
		hover_q();

// the next version will calculate distance
}
void standard_backward(void){
	(void)gpioPWM(motor3,global_pwmhov+1); //set time duration 0.4T
		(void)gpioPWM(motor1,global_pwmhov-1);
		gpioSleep(0,0,4000);
		hover_q();dd
		gpioSleep(0,0,1000);
		(void)gpioPWM(motor3,global_pwmhov+1);
		(void)gpioPWM(motor1,global_pwmhov-1);
		gpioSleep(0,0,1500);
		hover_q();
		gpioSleep(0,0,1500);
		(void)gpioPWM(motor3,global_pwmhov+1);
		(void)gpioPWM(motor1,global_pwmhov-1);
		gpioSleep(0,0,2000);
		hover_q();


}
void standard_right(void){
	(void)gpioPWM(motor2,global_pwmhov+1); //set time duration 0.4T
		(void)gpioPWM(motor4,global_pwmhov-1);
		gpioSleep(0,0,4000);
		hover_q();
		gpioSleep(0,0,1000);
		(void)gpioPWM(motor2,global_pwmhov+1);
		(void)gpioPWM(motor4,global_pwmhov-1);
		gpioSleep(0,0,1500);
		hover_q();
		gpioSleep(0,0,1500);
		(void)gpioPWM(motor2,global_pwmhov+1);
		(void)gpioPWM(motor4,global_pwmhov-1);
		gpioSleep(0,0,2000);
		hover_q();

}
void standard_left(void){
	(void)gpioPWM(motor4,global_pwmhov+1); //set time duration 0.4T
		(void)gpioPWM(motor2,global_pwmhov-1);
		gpioSleep(0,0,4000);
		hover_q();
		gpioSleep(0,0,1000);
		(void)gpioPWM(motor4,global_pwmhov+1);
		(void)gpioPWM(motor2,global_pwmhov-1);
		gpioSleep(0,0,1500);
		hover_q();
		gpioSleep(0,0,1500);
		(void)gpioPWM(motor4,global_pwmhov+1);
		(void)gpioPWM(motor2,global_pwmhov-1);
		gpioSleep(0,0,2000);
		hover_q();
}
void standard_yaw(void){
	(void)gpioPWM(motor1,global_pwmhov+1);
	(void)gpioPWM(motor2,global_pwmhov-1);
	(void)gpioPWM(motor3,global_pwmhov+1);
	(void)gpioPWM(motor3,global_pwmhov-1);
		gpioSleep(0,0,4000);
		hover_q();
		gpioSleep(0,0,1000);
		(void)gpioPWM(motor1,global_pwmhov+1);
			(void)gpioPWM(motor2,global_pwmhov-1);
			(void)gpioPWM(motor3,global_pwmhov+1);
			(void)gpioPWM(motor3,global_pwmhov-1);
		gpioSleep(0,0,1500);
		hover_q();
		gpioSleep(0,0,1500);
		(void)gpioPWM(motor1,global_pwmhov+1);
			(void)gpioPWM(motor2,global_pwmhov-1);
			(void)gpioPWM(motor3,global_pwmhov+1);
			(void)gpioPWM(motor3,global_pwmhov-1);
		gpioSleep(0,0,2000);
		hover_q();
}
void standard_up(void){
	//calculate maths
	//output 4 speeds for the motors
   //current pmw of all ++;
	    (void)gpioPWM(motor1,global_pwmhov+1);
		(void)gpioPWM(motor2,global_pwmhov+1);
		(void)gpioPWM(motor3,global_pwmhov+1);
		(void)gpioPWM(motor3,global_pwmhov+1);
		gpioSleep(0,0,4000);
		hover_q();
			gpioSleep(0,0,1000);
			(void)gpioPWM(motor1,global_pwmhov+1);
			(void)gpioPWM(motor2,global_pwmhov+1);
			(void)gpioPWM(motor3,global_pwmhov+1);
			(void)gpioPWM(motor3,global_pwmhov+1);
			gpioSleep(0,0,4000);
			hover_q();

}
void standard_down(void){
	//calculate maths
	//output 4 speeds for the motors
	 (void)gpioPWM(motor1,global_pwmhov-1);
			(void)gpioPWM(motor2,global_pwmhov-1);
			(void)gpioPWM(motor3,global_pwmhov-1);
			(void)gpioPWM(motor3,global_pwmhov-1);
			gpioSleep(0,0,4000);
			hover_q();
				gpioSleep(0,0,1000);
				(void)gpioPWM(motor1,global_pwmhov-1);
				(void)gpioPWM(motor2,global_pwmhov-1);
				(void)gpioPWM(motor3,global_pwmhov-1);
				(void)gpioPWM(motor3,global_pwmhov-1);
				gpioSleep(0,0,4000);
				hover_q();


}
void get_motorSettings(void){

	//f=cons mg ;
		//k^w2=mg
	//Kf 6.11*10^-8
		//Km 1.5*10-9
		int w=sqrt(mass*g/4*k);;
	global_pwmhov=w/wmax * pwm_range;
}
void set_motorSettings(int pwm_r){
	pwm_range=pwm_r;
	 gpioSetPWMrange(motor_pins,pwm_range]);  // to set the resulation , do it 4 times 
	gpioSetMode(motor_pins,PI_OUTPUT); // set direction
}
void land_q(void){
(void)	gpioPWM(motor1,global_pwmhov--);
 (void)	gpioPWM(motor2,global_pwmhov--);
 (void)	gpioPWM(motor3,global_pwmhov--);
 (void)	gpioPWM(motor4,global_pwmhov--);
gpioSleep(0,0,4000);
(void)	gpioPWM(motor1,global_pwmhov-2);
 (void)	gpioPWM(motor2,global_pwmhov-2);
 (void)	gpioPWM(motor3,global_pwmhov-2);
 (void)	gpioPWM(motor4,global_pwmhov-2);
}
void fullstop(void){
(void)	gpioPWM(motor1,0);
 (void)	gpioPWM(motor2,0);
 (void)	gpioPWM(motor3,0);
 (void)	gpioPWM(motor4,0);
}
void testincrease(void) {global_pwmhov++;}
void testdecrease(void) {global_pwmhov--;}
int get_pwmR(void){return pwm_range;}

}
