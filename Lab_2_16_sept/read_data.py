import math as m
import numpy as np
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import seaborn as sns
import ast

file_name = 'data/sphere_coords_A.txt'
file = open(file_name, mode='r')

r = ast.literal_eval(file.readline())
psi = ast.literal_eval(file.readline())
theta = ast.literal_eval(file.readline())


for i in range(len(theta)):
    theta[i] = np.radians(theta[i])
    psi[i] = np.radians(psi[i])

x = []
y = []
z = []

for i in range(len(r)):
    if (r[i] < 48) and (r[i] > 30):
        x.append(r[i]*m.sin(theta[i])*m.cos(psi[i]))
        y.append(r[i]*m.sin(theta[i])*m.sin(psi[i]))
        z.append(r[i]*m.cos(theta[i]))

fig = plt.figure()
ax = fig.gca(projection = '3d')
ax.set_xlabel('X-axis (in cm)')
ax.set_ylabel('Y-axis (in cm)')
ax.set_zlabel('Z-axis (in cm)')
ax.scatter3D(x, y, z, label='Scatterplot of H, 35cm away')
plt.show()
