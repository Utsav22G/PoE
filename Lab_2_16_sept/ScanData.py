
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

arduinoComPort = '/dev/ttyACM0'
# arduinoComPort = "COM3"


#
# Set the baud rate
# NOTE1: The baudRate for the sending and receiving programs must be the same!
# NOTE2: For faster communication, set the baudRate to 115200 below
#        and check that the arduino sketch you are using is updated as well.
#
baudRate = 115200


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
    print(lineOfData)

    data = lineOfData.split(',')

    if len(data) == 4:
        r.append(float(data[0]))
        psi.append(int(data[1]))
        theta.append(int(data[2]))
        if(int(data[3]) == 1):
            break

    #
    # elif (len(data) == 1) and (float(data[0]) == 0) and (len(r)>5):
    #     break

  #
  # check if data was received
  #
spherical = open('data/sphere_coords_A.txt', 'w')
spherical.write(str(r) + '\n')
spherical.write(str(psi) + '\n')
spherical.write(str(theta) + '\n')
