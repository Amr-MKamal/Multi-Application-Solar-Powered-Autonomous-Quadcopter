#include "sensing.h"
#include "sensehat.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<conio.h>
using namespace std ;

double volatile pitch , yaw , roll ; 
double volatile xdotdot,ydotdot, zdotdot; 
double volatile pitchdot, yawdot , rolldot;
int main()
{
	string readerline;
	string read[16];
    while(True)
    {
        
	ifstream reader("/home/pi/Desktop/readings.txt");
        #check if the file exist
	if(!reader)
	{
		cout<<"there was a problem openning the file..press any key to close";
		cin.get();
		return 0;
	}
	int i=0;
    //store reads in array while outputting, skipping blank lines
	while(reader.good())
	{
		getline(reader,readerline,' ');

		if(readerline!="")
		{
			read[i]=readerline;
			cout<<read[i]<<endl;
			i++;
		}
		
	}
        yaw=strtod(read[0].c_str(),NULL);
        roll=strtod(read[1].c_str(),NULL);
        pitch=strtod(read[2].c_str(),NULL);
        xdotdot=strtod(read[3].c_str(),NULL);
	ydotdot=strtod(read[4].c_str(),NULL);
	zdotdot=strtod(read[5].c_str(),NULL);
        pitchdot=strtod(read[6].c_str(),NULL);
        rolldot=strtod(read[7].c_str(),NULL);
	yawdot=strtod(read[8].c_str(),NULL);
        #delay for 2ms
         time.sleep(2/1000.0);
    }
}



