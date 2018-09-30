import serial

arduinoComPort = '/dev/ttyACM0'

baudRate = 115200
serialPort = serial.Serial(arduinoComPort, baudRate, timeout=1)

t = []
left_sensor = []
right_sensor = []
left_motor = []
right_motor = []

while True:
  #
  # ask for a line of data from the serial port, the ".decode()" converts the
  # data from an "array of bytes", to a string
  #
    lineOfData = serialPort.readline().decode()
    print(lineOfData)

    data = lineOfData.split(',')

    if len(data) == 6:
        t.append(float(data[0]))
        left_sensor.append(float(data[1]))
        right_sensor.append(int(data[2]))
        left_motor.append(int(data[3]))
        right_motor.append(int(data[4]))
        if(int(data[5]) == 1):
            break

speeds = open('data/sphere_coords_A.txt', 'w')

speeds.write(str(t), '\n')
speeds.write(str(left_sensor) + '\n')
speeds.write(str(right_sensor) + '\n')
speeds.write(str(left_motor) + '\n')
speeds.write(str(right_motor) + '\n')
