#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pigpio.h>
#include <sched.h>
#include <math.h>
#define SUCCESS 0
#define pwm_range 255
#define wmax 1400
#define mass 1.5
#define g 9.81
#define k 206e-9
#define motor1 1
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
