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

#include "control_v2.h"
#include "sensing.h"
#include "Angular_PIDS.h"
#include "ESCdriver.h"
#include "math.h"
//http://abyz.co.uk/rpi/pigpio/cif.html
//http://arma.sourceforge.net/docs.html
//http://eigen.tuxfamily.org/index.php?title=Main_Page
//http://www.simunova.com/node/33
using namespace std;
double U1, U2, U3 , U4 ;
double w1,w2,w3,w4;
int tolerance=42; //yah magical number 
int pwm1,pwm2,pwm3 , pwm4;
//define default_pwm 10000
//function to intialise with minmum
void hover_q(void){
	tolerance=42;
	while(tolerance >2){
	U1=u1(0);
	U2=u2(0);
	U3=u3(0);
	U4=u4(0); //yaw should not be controllred
	w1=sqrt((U1/(4*Kf) + U3/(2*Kf) + U4/(4*Km))); //control equations 
	w2=sqrt(U1/(4*Kf) - U2/(2*Kf) - U4/(4*Km) );
	w3=sqrt(U1/(4*Kf) - U3/(2*Kf) + U4/(4*Km) );
        w4=sqrt(U1/(4*Kf) + U2/(2*Kf) - U4/(4*Km) );
		 pwm(E1,w1); //apply new omegas
		 pwm(E2,w2); //written in this way to simplify the understanding of equations
		 pwm(E3,w3);
		 pwm(E4,w4);
		tolerance=(int)sqrt(pitch*pitch+yaw*yaw); //minimize the control error with torllence less than 1.1%
		usleep(3000); //2 ms for sensor refresh + 1 ms for operations and effects to take order
	}
	
		
}
void standard_forward(void){
	//roll=0 , pitch=10 , yaw=0 ,z=0 10.1>pitch
	tolerance=42; //restting the value
while (tolerance>1)
{ 
	//actually this not very accurate , roll should be controlled too , PID is not very smart
	U1=u1(0);
	U2=u2(10);
	U3=u3(0);
	U4=u4(0);
	applychanges(U1,U2,U3,U4);
	usleep(3000);  
	tolerance= (int)(sqrt((pitch-10)*(pitch-10)*10); 
  }
			

}
void standard_backward(void){
	//roll=0 , pitch=-10 , yaw=0 ,z=0
	tolerance=42;
while (tolerance>1)
{ 
	U1=u1(0);
	U2=u2(10);
	U3=u3(0);
	U4=u4(0);
	applychanges(U1,-U2,U3,U4);
		usleep(3000);
	tolerance= (int)(sqrt((pitch+10)*(pitch+10)*10); //make sure pitch can take negative values
  }
}
void standard_right(void){
	//roll=10 , pitch=0 , yaw=0 ,z=0
	tolerance=42;
	while (tolerance>1)
{ 
	U1=u1(0);
	U2=u2(0);
	U3=u3(10);
	U4=u4(0);
applychanges(U1,U2,U3,U4);
	usleep(3000);
	tolerance= (int)(sqrt((roll-10)*(roll-10)*10); 
			  }
}
void standard_left(void){
	//roll=-10 , pitch=0 , yaw=0 ,z=0
	tolerance=42;
while (tolerance>1)
	U1=u1(0);
	U2=u2(0);
	U3=u3(10);
	U4=u4(0);
	applychanges(U1,U2,-U3,U4);
	usleep(3000);
	tolerance= (int)(sqrt((roll+10)*(roll+10)*10); 
}
void standard_yaw(void){
	//roll=0 , pitch=0 , yaw=45 ,z=0
	torlerance=42;
while (tolerance>1){
	U1=u1(0);
	U2=u2(0);
	U3=u3(0);
	U4=u4(90);
	applychanges(U1,U2,U3,U4);
	usleep(3000);
	tolerance= (int)(sqrt((yaw-45)*(yaw-45)*10); 
	
}
			 }
void standard_up(void){
		//roll=0 , pitch=0 , yaw=0 ,z=10
 //no loops needed here , ( no control )
	U1=u1(0)*1.1;
	U2=u2(0);
	U3=u3(0);
	U4=u4(0);
	applychanges(U1,U2,U3,U4);
	usleep(3000);
		 
}
void standard_down(void){
		//roll=0 , pitch=0 , yaw=0 ,z=10

	U1=u1(0)*0.9;
	U2=u2(0);
	U3=u3(0);
	U4=u4(0);
	applychanges(U1,U2,U3,U4);
	usleep(3000);

}

void land_q(void){
//under devlopment still
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
		gpioSleep(0,0,2000); //2ms sleep
		fullstop();

}
void applychanges(double cont1,double cont2,double cont3,double cont4){
	
	w1=sqrt(cont1/(4*Kf)+ cont3/(2*Kf) + cont4/(4*Km) ); //THE OMEGA EQUATIONS FOR THE QUAD DYNAMICS
	w2=sqrt(cont1/(4*Kf) - cont2/(2*Kf) - cont4/(4*Km) );
	w3=sqrt(cont1/(4*Kf) - cont3/(2*Kf) + cont4/(4*Km) );
        w4=sqrt(cont1/(4*Kf) + cont2/(2*Kf) - cont4/(4*Km) );
	         pwm(E1,w1);
		 pwm(E2,w2);
		 pwm(E3,w3);
		 pwm(E4,w4);
	
}
