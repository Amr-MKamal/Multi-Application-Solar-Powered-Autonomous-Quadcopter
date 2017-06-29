
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <unistd.h>
#include <stdlib.h>
using namespace std ;
double volatile pitch , yaw , roll ;
double volatile xdotdot,ydotdot, zdotdot;
double volatile pitchdot , yawdot , rolldot;
int main()
{
	string readerline;
	 string myArray[12];
   while(1)
    {

	ifstream reader("/home/pi/Desktop/readings.txt");
        //check if the file exist
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

	//add the contents of the readings.txt to an array"myArray"
	for(int i = 0; i < 12; ++i)
        {
			reader >> myArray[i];
			//cout<<myArray[i]<<endl;
        }
      //use the contents of the array


	}
yaw= strtod(myArray[0].c_str(),NULL);
roll=strtod(myArray[1].c_str(),NULL);
pitch=strtod(myArray[2].c_str(),NULL);
xdotdot=strtod(myArray[3].c_str(),NULL);
ydotdot=strtod(myArray[4].c_str(),NULL);
zdotdot=strtod(myArray[5].c_str(),NULL);
pitchdot=strtod(myArray[6].c_str(),NULL);
rolldot=strtod(myArray[7].c_str(),NULL);
yawdot=strtod(myArray[8].c_str(),NULL);
        //delay for 2ms
         usleep(10000);
    }
}


