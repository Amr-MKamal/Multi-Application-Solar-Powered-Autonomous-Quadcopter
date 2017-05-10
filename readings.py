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
#name all the above as a function called readings 
#intalize it for one time to save data 
#put it inside a function inside a loop and write the data to a file 
#calculate angular accel from accel 
