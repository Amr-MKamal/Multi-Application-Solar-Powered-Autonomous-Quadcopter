#include "driver.h"

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
    if (gpioInitialise() < 0) cout<<"GPIO Not Initialised\n";
    else
    {
        for (g=1; g<5; g++)
        {
            gpioServo(E[g], MIN_WIDTH);
            cout <<g<<"is initialized"<<endl;
        }
    }


    time_sleep(0.5);
}

//Changing The ESC Speed
//ESC : the ESC's Number
//speed : the ESC's percentage
void pwm (int ESC, int speed)
{
    int w;
    if(ESC<1 || ESC>4) cout<<"invalid ESC num\n";
    else
    {
        w = (speed*10)+1000;
        gpioServo(E[ESC], w);
        cout <<ESC<<"is"<<speed<<"%"<<endl;
    }
}

//Stopping the 4 ESC's
void stop ()
{
    int g;
    for (g=1; g<5; g++)
    {
            gpioServo(E[g], 0);
            cout <<g<<"is Stopped"<<endl;
    }
    gpioTerminate();
    time_sleep(0.5);
}
