import serial

arduinoComPort = '/dev/ttyUSB0'

baudRate = 115200
serialPort = serial.Serial(arduinoComPort, baudRate, timeout=1)

time = []
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
        time.append(float(data[0]))
        left_sensor.append(float(data[1]))
        right_sensor.append(float(data[2]))
        left_motor.append(float(data[3]))
        right_motor.append(float(data[4]))
        if(int(data[5]) == 1):
            break

speeds = open('data/test_data.txt', 'w')

speeds.write(str(time) + '\n')
speeds.write(str(left_sensor) + '\n')
speeds.write(str(right_sensor) + '\n')
speeds.write(str(left_motor) + '\n')
speeds.write(str(right_motor) + '\n')
