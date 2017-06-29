#ifndef ESC_H_INCLUDED
#define ESC_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pigpio.h>

#define NUM_GPIO 32
#define MIN_WIDTH 1000
#define MAX_WIDTH 2000

#define E1 4
#define E2 23
#define E3 24
#define E4 25

void init ();
void pwm (int ESC, double w);
void stop();

#endif // ESC_H_INCLUDED

