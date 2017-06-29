#include "ESCdriver.h"

using namespace std;

//int run=1;
//int step[NUM_GPIO];

int E[5]={4,E1,E2,E3,E4};
int width[NUM_GPIO];
int used[NUM_GPIO];

//Initializing the 4 ESC's
void init ()
{
    int g;
    if (gpioInitialise() < 0) cout<<"GPIO Not Initialised\n"; //initalise the library at first
    else
    {
   for (g=1; g<5; g++)  {  gpioServo(E[g], MIN_WIDTH);  } //esc should be initalised with minmum value
    }
  usleep(20000);
}

//Changing The ESC Speed
//ESC : the ESC's Number
//speed : the ESC's percentage
void pwm (int ESC, double w)
{
  w= (w*MIN_WIDTH/wmax)+MIN_WIDTH
    int speed= int(w);
    if(ESC<1 || ESC>4) cout<<"invalid ESC num\n";
    else
    {
        gpioServo(E[ESC], speed);
    }
}

//Stopping the 4 ESC's
void stop ()
{
    int g;
    for (g=1; g<5; g++) {gpioServo(E[g], MIN_WIDTH); } //forcing full stop

}
