
#      ******************************************************************
#      *                                                                *
#      *                                                                *
#      *    Example Python program that receives data from an Arduino   *
#      *                                                                *
#      *                                                                *
#      ******************************************************************


import serial

#
# Note 1: This python script was designed to run with Python 3.
#
# Note 2: The script uses "pyserial" which must be installed.  If you have
#         previously installed the "serial" package, it must be uninstalled
#         first.
#
# Note 3: While this script is running you can not re-program the Arduino.
#         Before downloading a new Arduino sketch, you must exit this
#         script first.
#


#
# Set the name of the serial port.  Determine the name as follows:
#	1) From Arduino's "Tools" menu, select "Port"
#	2) It will show you which Port is used to connect to the Arduino
#
# For Windows computers, the name is formatted like: "COM6"
# For Apple computers, the name is formatted like: "/dev/tty.usbmodemfa141"
#
arduinoComPort = "COM3"


#
# Set the baud rate
# NOTE1: The baudRate for the sending and receiving programs must be the same!
# NOTE2: For faster communication, set the baudRate to 115200 below
#        and check that the arduino sketch you are using is updated as well.
#
baudRate = 9600


#
# open the serial port
#
serialPort = serial.Serial(arduinoComPort, baudRate, timeout=1)



#
# main loop to read data from the Arduino, then display it
#

r = []
psi = []
theta = []
while True:
  #
  # ask for a line of data from the serial port, the ".decode()" converts the
  # data from an "array of bytes", to a string
  #
    lineOfData = serialPort.readline().decode()
    
    if 'END' in lineOfData:
        break
        
    print(lineOfData)
    data = lineOfData.split(',')
    print(data)
    if len(data) ==3:
        r.append(float(data[0]))
        psi.append(int(data[1]))
        theta.append(int(data[2]))

  #
  # check if data was received
  #
print(r)


import math as m


for i in range(len(theta)):
    theta[i] = theta[i]*2*m.pi/180
    psi[i] = psi[i]*2*m.pi/180

x = []
y = []
z = []

for i in range(len(r)):
    x.append(r[i]*m.sin(psi[i])*m.cos(theta[i]))
    y.append(r[i]*m.sin(psi[i])*m.sin(theta[i])) 
    z.append(r[i]*m.cos(psi[i]))

from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt

fig = plt.figure()
ax = plt.axes(projection = '3d')

ax.scatter3D(x, y, z, 'gray')