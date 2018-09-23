import serial

arduinoComPort = '/dev/ttyACM0'
# arduinoComPort = "COM3"

baudRate = 115200
serialPort = serial.Serial(arduinoComPort, baudRate, timeout=1)

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
