#include <pigpio.h>
#include <sched.h>
#include <math.h>
#include "control_v2.h"
#include "stdint.h"
#include "sensing.h"
#include "Angular_PIDS.h"
#define Kp 1
#define Ki 1
#define Kd 1
#define pi 3.14
int intialise1, intialise2, intialise3, intialise4; //intalise value for the recuressive control functions
double uu1 ,uu2 ,uu3 ,uu4;
double err1 , err2, err3, err4 ;
unsigned int delta_t1 ,delta_t2 , delta_t3 ,delta_t4;
unsigned int time_old1 ,time_old2, time_old3, time_old4;
double error_old1,error_old2,error_old3,error_old4;
double diff_term1,diff_term2,diff_term3,diff_term4;
double inte_term1,inte_term2,inte_term3,inte_term4;
double E1,E2,E3,E4;
double e_dot1,e_dot2,e_dot3,e_dot4;
double volatile	u1offest=mass*g;
// values above for the recurrsive function operation decrlaring it
/*
u1 altitude controll , this function usally return the throttle but in case
of landing or rising z has a value that activates the function with
altitude from ultarsonic and pressure
Retrun value : throttle
Input value : z alifation usually 0
*/
double u1 ( double z ){

	  if(z==0){return u1offest ;} //deactivate the function
			   else{ //enter the function
err1=z/*-altitude*/;
			if(intialise1!=1){ //check for first time intialistion
delta_t1=0;
time_old1=0;
error_old1 =0 ;diff_term1 =0 ;inte_term1=0 ; E1=0 ;e_dot1=0;
intialise1=1;}
//calculate sample time
	delta_t1=gpioTick()-time_old1;
	E1=E1+err1*delta_t1; //sum the error for integrtion
	e_dot1=err1-error_old1;  //deffrentiate the error
	if (delta_t1 !=0){ diff_term1=e_dot1/delta_t1 ;} //check for value
  else {diff_term1=0;}
  inte_term1=E1*delta_t1; //the integration
 uu1 = Kp*err1 + Ki*inte_term1 + Kd*diff_term1 ; //the pid
time_old1=gpioTick(); //refrech time
			return (uu1+u1offest);   }}


double u2 (double pitch_desired){
err2=pitch_desired-pitch ;//start with the err2 value
	if(intialise2!=1){
delta_t2=0;
time_old2=0;
error_old2=0, diff_term2 =0, inte_term2=0 , E2=0, e_dot2=0;
intialise2=1;}
	delta_t2=gpioTick()-time_old2;
	E2=E2+err2*delta_t2;
	e_dot2=err2-error_old2;
	if (delta_t2 !=0){ diff_term2=e_dot2/delta_t2 ;}
  else {diff_term2=0;}
  inte_term2=E2*delta_t2;
uu2 = Kppr*err2 +Kipr*inte_term2+Kdpr*diff_term2;
time_old2=gpioTick();
return uu2;
}
double u3 (double roll_desired){
 err3=roll_desired-roll;
	if(intialise3!=1){
delta_t3=0;
 time_old3=0;
 error_old3 =0; diff_term3 =0; inte_term3=0 ;  E3=0; e_dot3=0; intialise3=1;
}
	delta_t3=gpioTick()-time_old3;
	E3=E3+err3*delta_t3;
	e_dot3=err3-error_old3;
	if (delta_t3 !=0){
	 diff_term3=e_dot3/delta_t3 ;
	 }
  else {
  diff_term3=0;
  }
  inte_term3=E3*delta_t3;
   uu3 = Kppr*err3 +Kipr*inte_term3+Kdpr*diff_term3;
time_old3=gpioTick();
return uu3;
}
double u4 (double yaw_desired){
err4=yaw_desired-yaw;
	if(intialise4!=1){
delta_t4=0;
time_old4=0;
error_old4 =0; diff_term4 =0; inte_term4=0 ; E4=0; e_dot4=0;
intialise4=1;
}
	delta_t4=gpioTick()-time_old4;
	E4=E4+err4*delta_t4;
	e_dot4=err4-error_old4;
	if (delta_t4 !=0){
	 diff_term4=e_dot4/delta_t4 ;
	 }
  else {
  diff_term4=0;
  }
  inte_term4=E4*delta_t4;
   uu4 = Kpy*err4 +Kiy*inte_term4+Kdy*diff_term4;
time_old4=gpioTick();
return uu4;
}
 double U_time (double desired_distance, double angle )	{
	//this is a function to calculate the need pitch or roll to travel a desired distance
	return (sqrt((2*desired_distance)/(g*sin(angle*pi/180))));
	// t=1083 for 1 meter , 766 for 0.5 for 10 angle
}

