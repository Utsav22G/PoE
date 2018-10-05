import matplotlib.pyplot as plt
import ast


file_name = 'data/test_data.txt'
file = open(file_name, mode='r')

time = ast.literal_eval(file.readline())
left_sensor = ast.literal_eval(file.readline())
right_sensor = ast.literal_eval(file.readline())
left_motor = ast.literal_eval(file.readline())
right_motor = ast.literal_eval(file.readline())


fig = plt.figure()
plt.scatter(time, left_sensor, label = 'Left Sensor')
plt.scatter(time, right_sensor, label = 'Right Sensor')
plt.scatter(time, left_motor, label = 'Left Motor')
plt.scatter(time, left_sensor, label = 'Right Motor')
plt.show()
