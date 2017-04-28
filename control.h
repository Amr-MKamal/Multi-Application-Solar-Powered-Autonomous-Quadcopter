#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pigpio.h>
#include <sched.h>
#include <math.h>
#define SUCCESS 0
#define pwm_range 255 //default but can change 
#define wmax 1400   //motor max
#define mass 1.5 //mass 
#define g 9.81 //gravity 
#define k 206e-9 //f=kw^2
#define Km // motor gain
#define Ixx //moment of inertia calculated value
#define Iyy
#define Izz
#define motor1 1  //input pins for pwm
#define motor2 3
#define motor3 5
#define motor4 7
void hover_q(void);
void standard_forward(void);
void standard_backward(void);
void standard_right(void);
void standard_left(void);
void standard_yaw(void);
void standard_up(void);
void standard_down(void);
void get_motorSettings(void);
void set_motorSettings(void);
void land_q(void);
void fullstop(void);
