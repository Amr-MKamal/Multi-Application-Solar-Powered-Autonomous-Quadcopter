#include <pigpio.h>
#include <sched.h>
#include <math.h>
#include "control.h"
#include "sensing.h"
#define Kp
#define Ki
#define Kd
double u1 ( double z ){
	double whover=sqrt(mass*g/(Kf*4);
	u1offest=mass*g;
	  if(z==0){return u1offest ;}
			   else{
double err=z-altitude;
double U1=PID(err);
			if(intialise!=1){
uint_32 delta_t=0;
uint_32 time_old=0;
double error_old =0, diff_term =0,double inte_term=0 ,double aggresive=0, E=0, e_dot=0;
int intialise=1;}
	delta_t=gpioTick()-time_old;
	E=E+err*delta_t;
	e_dot=err-error_old
	if (delta_t !=0){ diff_term=e_dot/delta_t ;}
  else {diff_tem=0;}
  inte_term=E*delta_t;
  double u = Kp*error +Ki*inte_term+Kd*diff_term;
time_old=gpioTick();   
			   }
	return (u+u1offest);}
	
}
double u2 (double pitch_desired){
double err=pitch_desired-pitch
	if(intialise!=1){
uint_32 delta_t=0;
uint_32 time_old=0;
double error_old =0, diff_term =0,double inte_term=0 ,double aggresive=0, E=0, e_dot=0;
int intialise=1;}
	delta_t=gpioTick()-time_old;
	E=E+err*delta_t;
	e_dot=err-error_old
	if (delta_t !=0){ diff_term=e_dot/delta_t ;}
  else {diff_tem=0;}
  inte_term=E*delta_t;
  double u = Kppr*error +Kipr*inte_term+Kdpr*diff_term;
time_old=gpioTick();
return u;
}
double u3 (double roll_desired){
double err=roll_desired-roll
	if(intialise!=1){
uint_32 delta_t=0;
uint_32 time_old=0;
double error_old =0, diff_term =0,double inte_term=0 ,double aggresive=0, E=0, e_dot=0;
int intialise=1;}
	delta_t=gpioTick()-time_old;
	E=E+err*delta_t;
	e_dot=err-error_old
	if (delta_t !=0){ diff_term=e_dot/delta_t ;}
  else {diff_tem=0;}
  inte_term=E*delta_t;
  double u = Kppr*error +Kipr*inte_term+Kdpr*diff_term;
time_old=gpioTick();
return u;
}
double u4 (double yaw_desired){
double err=yaw_desired-yaw;
	if(intialise!=1){
uint_32 delta_t=0;
uint_32 time_old=0;
double error_old =0, diff_term =0,double inte_term=0 ,double aggresive=0, E=0, e_dot=0;
int intialise=1;}
	delta_t=gpioTick()-time_old;
	E=E+err*delta_t;
	e_dot=err-error_old
	if (delta_t !=0){ diff_term=e_dot/delta_t ;}
  else {diff_tem=0;}
  inte_term=E*delta_t;
  double u = Kpy*error +Kiy*inte_term+Kdy*diff_term;
time_old=gpioTick();
return u;
}
double U_time (double desired_distance, double angle )	{
	//this is a function to calculate the need pitch or roll to travel a desired distance 
	return (sqrt((2*desired_distance)/(g*sin(angle*pi/180))));
	// t=1083 for 1 meter , 766 for 0.5 for 10 angle
}
			   
			   
			   
			   /*double PID ( double err,double  ) {
if(intialise!=1){
uint_32 delta_t=0;
uint_32 time_old=0;
double error_old =0, diff_term =0,double inte_term=0 ,double aggresive=0, E=0, e_dot=0;
int intialise=1;}
	delta_t=gpioTick()-time_old;
	E=E+err*delta_t;
	e_dot=err-error_old
	if (delta_t !=0){ diff_term=e_dot/delta_t ;}
  else {diff_tem=0;}
  inte_term=E*delta_t;
  double u = Kp*error +Ki*inte_term+Kd*diff_term;
time_old=gpioTick();
return u ;
}*/
