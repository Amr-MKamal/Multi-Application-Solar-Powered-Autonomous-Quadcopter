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
#include "Angular_PIDS.h"
//http://abyz.co.uk/rpi/pigpio/cif.html
//http://arma.sourceforge.net/docs.html
//http://eigen.tuxfamily.org/index.php?title=Main_Page
//http://www.simunova.com/node/33
using namespace std;
int global_pwmhov ;
int pwm_range= 20000;
int pwm_rangemax=2000;
int pwm_rangemin=1000;
double U1, U2, U3 , U4 ;
double w1,w2,w3,w4;
int pwm1,pwm2,pwm3 , pwm4;
#define default_pwm 10000
(void) gpioInitialise();
//function to intialise with minmum
void hover_q(void){
	U1=u1(0);
	U2=u2(0);
	U3=u3(0);
	U4=u4(0);
	w1=sqrt(U1/(4*Kf)+ U3/(2*Kf) + U4/(4*Km) );
	pwm1=(int)((w1/wmax+1) *pwm_rangemin);
	w2=sqrt(U1/(4*Kf) - U2/(2*Kf) - U4/(4*Km) );
        pwm2=(int)((w2/wmax+1) *pwm_rangemin);
	w3=sqrt(U1/(4*Kf) - U3/(2*Kf) + U4/(4*Km) );
	pwm3=(int)((w3/wmax+1) *pwm_rangemin);
        w4=sqrt(U1/(4*Kf) + U2/(2*Kf) - U4/(4*Km) );
	pwm4=(int)((w4/wmax+1) *pwm_rangemin);
		(void)gpioPWM(motor1,pwm1); //set time duration 0.4T
		(void)gpioPWM(motor2,pwm2);
		(void)gpioPWM(motor3,pwm3);
		(void)gpioPWM(motor4,pwm4);
		gpioSleep(0,0,2000);
		hover_q();
}
void standard_forward(void){
	//roll=0 , pitch=10 , yaw=0 ,z=0

	U1=u1(0);
	U2=u2(10);
	U3=u3(0);
	U4=u4(0);
	w1=sqrt(U1/(4*Kf)+ U3/(2*Kf) + U4/(4*Km) );
	pwm1=(int)((w1/wmax+1) *pwm_rangemin);
	w2=sqrt(U1/(4*Kf) - U2/(2*Kf) - U4/(4*Km) );
        pwm2=(int)((w2/wmax+1) *pwm_rangemin);
	w3=sqrt(U1/(4*Kf) - U3/(2*Kf) + U4/(4*Km) );
	pwm3=(int)((w3/wmax+1) *pwm_rangemin);
        w4=sqrt(U1/(4*Kf) + U2/(2*Kf) - U4/(4*Km) );
	pwm4=(int)((w4/wmax+1) *pwm_rangemin);
		(void)gpioPWM(motor1,pwm1); //set time duration 0.4T
		(void)gpioPWM(motor2,pwm2);
		(void)gpioPWM(motor3,pwm3);
		(void)gpioPWM(motor4,pwm4);
		gpioSleep(0,0,2000);
		hover_q();
// the next version will calculate distance
}
void standard_backward(void){
	//roll=0 , pitch=-10 , yaw=0 ,z=0

	U1=u1(0);
	U2=u2(-10);
	U3=u3(0);
	U4=u4(0);
	w1=sqrt(U1/(4*Kf)+ U3/(2*Kf) + U4/(4*Km) );
	pwm1=(int)((w1/wmax+1) *pwm_rangemin);
	w2=sqrt(U1/(4*Kf) - U2/(2*Kf) - U4/(4*Km) );
        pwm2=(int)((w2/wmax+1) *pwm_rangemin);
	w3=sqrt(U1/(4*Kf) - U3/(2*Kf) + U4/(4*Km) );
	pwm3=(int)((w3/wmax+1) *pwm_rangemin);
        w4=sqrt(U1/(4*Kf) + U2/(2*Kf) - U4/(4*Km) );
	pwm4=(int)((w4/wmax+1) *pwm_rangemin);
		(void)gpioPWM(motor1,pwm1); //set time duration 0.4T
		(void)gpioPWM(motor2,pwm2);
		(void)gpioPWM(motor3,pwm3);
		(void)gpioPWM(motor4,pwm4);
	double err=-10-pitch;
	if (err>0.1 )
		gpioSleep(0,0,2000);
		hover_q();
}
void standard_right(void){
	//roll=10 , pitch=0 , yaw=0 ,z=0

	U1=u1(0);
	U2=u2(0);
	U3=u3(10);
	U4=u4(0);
	w1=sqrt(U1/(4*Kf)+ U3/(2*Kf) + U4/(4*Km) );
	pwm1=(int)((w1/wmax+1) *pwm_rangemin);
	w2=sqrt(U1/(4*Kf) - U2/(2*Kf) - U4/(4*Km) );
        pwm2=(int)((w2/wmax+1) *pwm_rangemin);
	w3=sqrt(U1/(4*Kf) - U3/(2*Kf) + U4/(4*Km) );
	pwm3=(int)((w3/wmax+1) *pwm_rangemin);
        w4=sqrt(U1/(4*Kf) + U2/(2*Kf) - U4/(4*Km) );
	pwm4=(int)((w4/wmax+1) *pwm_rangemin);
		(void)gpioPWM(motor1,pwm1); //set time duration 0.4T
		(void)gpioPWM(motor2,pwm2);
		(void)gpioPWM(motor3,pwm3);
		(void)gpioPWM(motor4,pwm4);
		gpioSleep(0,0,2000);
		hover_q();
}
void standard_left(void){
	//roll=-10 , pitch=0 , yaw=0 ,z=0

	U1=u1(0);
	U2=u2(0);
	U3=u3(-10);
	U4=u4(0);
	w1=sqrt(U1/(4*Kf)+ U3/(2*Kf) + U4/(4*Km) );
	pwm1=(int)((w1/wmax+1) *pwm_rangemin);
	w2=sqrt(U1/(4*Kf) - U2/(2*Kf) - U4/(4*Km) );
        pwm2=(int)((w2/wmax+1) *pwm_rangemin);
	w3=sqrt(U1/(4*Kf) - U3/(2*Kf) + U4/(4*Km) );
	pwm3=(int)((w3/wmax+1) *pwm_rangemin);
        w4=sqrt(U1/(4*Kf) + U2/(2*Kf) - U4/(4*Km) );
	pwm4=(int)((w4/wmax+1) *pwm_rangemin);
		(void)gpioPWM(motor1,pwm1); //set time duration 0.4T
		(void)gpioPWM(motor2,pwm2);
		(void)gpioPWM(motor3,pwm3);
		(void)gpioPWM(motor4,pwm4);
		gpioSleep(0,0,2000);
		hover_q();
}
void standard_yaw(void){
	//roll=0 , pitch=0 , yaw=10 ,z=0

	U1=u1(0);
	U2=u2(0);
	U3=u3(0);
	U4=u4(10);
	w1=sqrt(U1/(4*Kf)+ U3/(2*Kf) + U4/(4*Km) );
	pwm1=(int)((w1/wmax+1) *pwm_rangemin);
	w2=sqrt(U1/(4*Kf) - U2/(2*Kf) - U4/(4*Km) );
        pwm2=(int)((w2/wmax+1) *pwm_rangemin);
	w3=sqrt(U1/(4*Kf) - U3/(2*Kf) + U4/(4*Km) );
	pwm3=(int)((w3/wmax+1) *pwm_rangemin);
        w4=sqrt(U1/(4*Kf) + U2/(2*Kf) - U4/(4*Km) );
	pwm4=(int)((w4/wmax+1) *pwm_rangemin);
		(void)gpioPWM(motor1,pwm1); //set time duration 0.4T
		(void)gpioPWM(motor2,pwm2);
		(void)gpioPWM(motor3,pwm3);
		(void)gpioPWM(motor4,pwm4);
		gpioSleep(0,0,2000);
		hover_q();
}
void standard_up(void){
		//roll=0 , pitch=0 , yaw=0 ,z=10

	U1=u1(0);
	U2=u2(0);
	U3=u3(0);
	U4=u4(0);
	w1=sqrt(U1/(4*Kf)+ U3/(2*Kf) + U4/(4*Km) );
	pwm1=(int)((w1/wmax+1) *pwm_rangemin);
	w2=sqrt(U1/(4*Kf) - U2/(2*Kf) - U4/(4*Km) );
        pwm2=(int)((w2/wmax+1) *pwm_rangemin);
	w3=sqrt(U1/(4*Kf) - U3/(2*Kf) + U4/(4*Km) );
	pwm3=(int)((w3/wmax+1) *pwm_rangemin);
        w4=sqrt(U1/(4*Kf) + U2/(2*Kf) - U4/(4*Km) );
	pwm4=(int)((w4/wmax+1) *pwm_rangemin);
		(void)gpioPWM(motor1,pwm1+10); //set time duration 0.4T
		(void)gpioPWM(motor2,pwm2+10);
		(void)gpioPWM(motor3,pwm3+10);
		(void)gpioPWM(motor4,pwm4+10);
		gpioSleep(0,0,2000);
		hover_q();

}
void standard_down(void){
		//roll=0 , pitch=0 , yaw=0 ,z=10

	U1=u1(0);
	U2=u2(0);
	U3=u3(0);
	U4=u4(0);
	w1=sqrt(U1/(4*Kf)+ U3/(2*Kf) + U4/(4*Km) );
	pwm1=(int)((w1/wmax+1) *pwm_rangemin);
	w2=sqrt(U1/(4*Kf) - U2/(2*Kf) - U4/(4*Km) );
        pwm2=(int)((w2/wmax+1) *pwm_rangemin);
	w3=sqrt(U1/(4*Kf) - U3/(2*Kf) + U4/(4*Km) );
	pwm3=(int)((w3/wmax+1) *pwm_rangemin);
        w4=sqrt(U1/(4*Kf) + U2/(2*Kf) - U4/(4*Km) );
	pwm4=(int)((w4/wmax+1) *pwm_rangemin);
		(void)gpioPWM(motor1,pwm1-10); //set time duration 0.4T
		(void)gpioPWM(motor2,pwm2-10);
		(void)gpioPWM(motor3,pwm3-10);
		(void)gpioPWM(motor4,pwm4-10);
		gpioSleep(0,0,2000);
		hover_q();

}
/*void get_motorSettings(void){

	//f=cons mg ;
		//k^w2=mg
	//Kf 6.11*10^-8
		//Km 1.5*10-9
		int w=sqrt(mass*g/4*k);;
	global_pwmhov=w/wmax * pwm_range;
} */
/*void set_motorSettings(int pwm_r){
	pwm_range=pwm_r;
	 gpioSetPWMrange(motor_pins,pwm_range]);  // to set the resulation , do it 4 times 
	gpioSetMode(motor_pins,PI_OUTPUT); // set direction
} */
void land_q(void){

	U1=u1(4); //in cm
	U2=u2(0);
	U3=u3(0);
	U4=u4(0);
	w1=sqrt(U1/(4*Kf)+ U3/(2*Kf) + U4/(4*Km) );
	pwm1=(int)((w1/wmax+1) *pwm_rangemin);
	w2=sqrt(U1/(4*Kf) - U2/(2*Kf) - U4/(4*Km) );
        pwm2=(int)((w2/wmax+1) *pwm_rangemin);
	w3=sqrt(U1/(4*Kf) - U3/(2*Kf) + U4/(4*Km) );
	pwm3=(int)((w3/wmax+1) *pwm_rangemin);
        w4=sqrt(U1/(4*Kf) + U2/(2*Kf) - U4/(4*Km) );
	pwm4=(int)((w4/wmax+1) *pwm_rangemin);
		(void)gpioPWM(motor1,pwm1); //set time duration 0.4T
		(void)gpioPWM(motor2,pwm2);
		(void)gpioPWM(motor3,pwm3);
		(void)gpioPWM(motor4,pwm4);
		gpioSleep(0,0,2000);
		fullstop();

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

