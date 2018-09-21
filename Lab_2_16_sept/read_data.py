import math as m
import numpy as np
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import ast

file_name = 'data/sphere_coords.txt'
file = open(file_name, mode='r')

r = ast.literal_eval(file.readline())
psi = ast.literal_eval(file.readline())
theta = ast.literal_eval(file.readline())


for i in range(len(theta)):
    if r[i] > 30*2.54:
        r[i] = -5

    # theta[i] = -(93 - theta[i])*m.pi/180
    # psi[i] = (93 - psi[i])*m.pi/180
    theta[i] = np.radians(theta[i])
    psi[i] = np.radians(psi[i])

x = []
y = []
z = []

for i in range(len(r)):
    x.append(r[i]*m.sin(theta[i])*m.cos(psi[i]))
    y.append(r[i]*m.sin(theta[i])*m.sin(psi[i]))
    z.append(r[i]*m.cos(theta[i]))

fig = plt.figure()
ax = plt.axes(projection = '3d')

ax.scatter3D(x, y, z, 'gray')
plt.show()
