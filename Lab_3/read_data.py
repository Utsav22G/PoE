import matplotlib.pyplot as plt
import ast


file_name = 'data/sphere_coords_A.txt'
file = open(file_name, mode='r')

t = ast.literal_eval(file.readline())
left_sensor = ast.literal_eval(file.readline())
right_sensor = ast.literal_eval(file.readline())
left_motor = ast.literal_eval(file.readline())
right_motor = ast.literal_eval(file.readline())


fig = plt.figure()
plt.scatter(t, left_sensor, label = 'Left Sensor')
plt.scatter(t, right_sensor, label = 'Right Sensor')
plt.scatter(t, left_motor, label = 'Left Motor')
plt.scatter(t, left_sensor, label = 'Right Motor')
plt.show()
