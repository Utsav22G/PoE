# Importing libraries

import math as m
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import serial

# For Windows computers, the port is formatted like: "COM6"
# For Apple computers, the port is formatted like: "/dev/tty.usbmodemfa141"
#
arduinoComPort = '/dev/ttyACM0'
# arduinoComPort = "COM6"

#
# Set the baud rate
# NOTE1: The baudRate for the sending and receiving programs must be the same!
# NOTE2: For faster communication, set the baudRate to 115200 below
#        and check that the arduino sketch you are using is updated as well.
#
baudRate = 9600
serialPort = serial.Serial(arduinoComPort, baudRate, timeout=1)

r = []
psi = []
theta = []
while True:
# ask for a line of data from the serial port, the ".decode()" converts the
# data from an "array of bytes", to a string
    lineOfData = serialPort.readline().decode()

    if ('END') in (lineOfData):
        break

    # print(lineOfData)
    data = lineOfData.split(',')
    # print(data)
    if (len(data) == 3):
        r.append(float(data[0]))
        psi.append(int(data[1]))
        theta.append(int(data[2]))

for i in range(len(theta)):
    theta[i] = theta[i]*2*m.pi/180
    psi[i] = psi[i]*2*m.pi/180

x = []; y = []; z = []
for i in range(len(r)):
    x.append(r[i]*m.sin(psi[i])*m.cos(theta[i]))
    y.append(r[i]*m.sin(psi[i])*m.sin(theta[i]))
    z.append(r[i]*m.cos(psi[i]))

fig = plt.figure()
ax = plt.axes(projection = '3d')

ax.scatter3D(x, y, z, 'gray')
