import time 
import sys
from sense_hat import SenseHat
sense = SenseHat()
# msleep or time.sleep
sense.set_imu_config(True, True, True)
orientation = sense.get_orientation()
Yaw=orientation['yaw']
Roll=orientation['roll']
Pitch=orientation['pitch'] #all in degrees
raw = sense.get_accelerometer_raw()
xdotdot=raw['x']
ydotdot=raw['y']
zdotdot=raw['z']
north = sense.get_compass()
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
#end
