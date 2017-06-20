import time 
import sys
from sense_hat import SenseHat
sense = SenseHat()
# msleep or time.sleep
sense.set_imu_config(True, True, True)
while(True)
{
  #open file readings.txt.."w+"Overwrites the existing file if the file exists.
  #If the file does not exist, creates a new file for reading and writing.
 f=open("readings.txt","w+")
orientation = sense.get_orientation()
yaw=orientation['yaw']
roll=orientation['roll']
pitch=orientation['pitch'] #all in degrees
myfile.write("%s\n" % yaw)
#Add (yaw,roll,pitch) to readings.txt
f.writelines("%s\t" %yaw)
f.writelines("%s\t" %roll)
f.writelines("%s\n" %pitch)
#myfile.writelines or target.write
#or    myfile.writelines('Mage')[1]
#https://stackoverflow.com/questions/4719438/editing-specific-line-in-text-file-in-python
#accel data in g
raw = sense.get_accelerometer_raw()
xdotdot= acceleration['x']
ydotdot= acceleration['y']
zdotdot= acceleration['z']
#Add (xdotdot,ydotdot,zdotdot) to readings.txt
f.writelines("%s\t" %xdotdot)
f.writelines("%s\t" %ydotdot)
f.writelines("%s\n" %zdotdot)
#angular velocity in rad/sec
raw = sense.get_gyroscope_raw()
xp = raw['x']
yr= raw['y']
zy= raw['z']
#Add (xp,yr,zy) to readings.txt
f.writelines("%s\t" %xp)
f.writelines("%s\t" %yr)
f.writelines("%s\n" %zy)
#north direction as yaw angle in degrees 
north = sense.get_compass()
#Add north to readings.txt
f.write("%s\n" %north)
humidity = sense.get_humidity()
temp = sense.get_temperature()
pressure = sense.get_pressure()
sea_pressure=1013.25 #in milibars
T0=288.15
(T0-((pressure/sea_pressure)^(0.190266436)))/0.0065=h0 
#function for altitude as following this all could be wrong it needs data from a weather station 
deltaH=(temp-((pressure/old_pressure)^(0.190266436)))/0.0065 +h0
#or here https://github.com/RobertCL/ArdulogAltitudeLogger/blob/master/ardulog/ardulog.ino#L118
#name all the above as a function called readings 
#intalize it for one time to save data 
#put it inside a function inside a loop and write the data to a file 
#calculate angular accel from accel 
#function a = acceleration(inputs, angles, xdot, m, g, k, kd)
    gravity = [0; 0; -g];
    R = rotation(angles);
    T = R * thrust(inputs, k);
    Fd = -kd * xdot;
    a = gravity + 1 / m * T + Fd;
end

function omegadot = angular_acceleration(inputs, omega, I, L, b, k)
    tau = torques(inputs, L, b, k);
    omegaddot = inv(I) * (tau - cross(omega, I * omega));
    #close file readings.txt
    f.close()
    #delay for 2ms
    time.sleep(2/1000.0);
#end
}
