#include "sensing.h"
#include "sensehat.h"
#include "RTIMULibDrive11.h"
#include ""
#include "RTIMULib.h"
double pitch , yaw , roll ; 
double xdotdot,ydotdot, zdotdot; 
ObtenirOrientation(float &pitch, float &roll, float & yaw);
//functions that will be used const RTVector3& getMeasuredPose() { return m_fusion->getMeasuredPose(); }
/*
    const RTVector3& getGyro() { return m_imuData.gyro; }   // gets gyro rates in radians/sec
    const RTVector3& getAccel() { return m_imuData.accel; } // get accel data in gs
    const RTVector3& getCompass() { return m_imuData.compass; } // gets compass data in uT

*/
//get data like 
   /* RTIMU_DATA imuData = imu->getIMUData();
   get_accel();
    humidite->humidityRead(imuData);
return imuData.humidity;
*/
   /* from sense_hat import SenseHat

sense = SenseHat()
raw = sense.get_accelerometer_raw()
print("x: {x}, y: {y}, z: {z}".format(**raw))
*/
/*

   data = Hat->get_accel();
   while (!data.valid)
   {
      delay(100);
      data = Hat->get_accel();
   }
std::cout << "Accel: {" << data.x << "," << data.y << "," << data.z << "}" << std::endl;
*/

