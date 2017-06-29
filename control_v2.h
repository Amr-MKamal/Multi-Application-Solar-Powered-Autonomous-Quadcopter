#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pigpio.h>
#include <sched.h>
#include <math.h>
#define SUCCESS 0
#define wmax 16100   //motor max
#define mass 1.5 //mass
#define g 9.81 //gravity
#define Kf 206e-9 //f=kw^2
#define Km 10// motor gain
#define Ixx //moment of inertia calculated value
#define Iyy
#define Izz
#define motor1 4  //it's actually 7 https://pinout.xyz/#
#define motor2 17 //actuall 11 , and 9 is a ground
#define motor3 18 //actuall 12
#define motor4 27 // actuall 13 and 14 is a ground
//sense hat pins 2,3,16,18,22,24
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
