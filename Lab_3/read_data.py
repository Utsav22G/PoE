import matplotlib.pyplot as plt
import ast


file_name = 'data/test_data.txt'
file = open(file_name, mode='r')

time = ast.literal_eval(file.readline())
left_sensor = ast.literal_eval(file.readline())
right_sensor = ast.literal_eval(file.readline())
left_motor = ast.literal_eval(file.readline())
right_motor = ast.literal_eval(file.readline())


fig, axs = plt.subplots(2, 1)
axs[0].plot(time, left_sensor, label = 'Left Sensor', c = 'b', marker = '.')
axs[0].plot(time, right_sensor, label = 'Right Sensor', c = 'g', marker = '.')
axs[1].plot(time, left_motor, label = 'Left Motor', c = 'b', marker = '*')
axs[1].plot(time, right_motor, label = 'Right Motor', c = 'g', marker = '*')
axs[0].set_xlabel('Time (in ms)')
axs[0].set_ylabel('Sensor Reading (0 to 1023)')
axs[1].set_xlabel('Time (in ms)')
axs[1].set_ylabel('Motor Speed (0 to 255)')
axs[0].set_title("Sensor Values vs Time")
axs[1].set_title("Motor Commands vs Time")
axs[0].legend()
axs[1].legend()
plt.grid(True)
plt.show()
