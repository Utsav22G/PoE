import math as m
import numpy as np
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import seaborn as sns
import ast

file_name = 'data/sphere_coords_H.txt'
file = open(file_name, mode='r')

r = ast.literal_eval(file.readline())
psi = ast.literal_eval(file.readline())
theta = ast.literal_eval(file.readline())

psi_horiz = []
theta_horiz = []
r_horiz = []


for i in range(len(theta)):
    if (theta[i] == 93):# and r[i] < 50:
        r_horiz.append(r[i])
        theta_horiz.append(np.radians(theta[i]))
        psi_horiz.append(np.radians(psi[i]))

x = []
y = []

for i in range(len(r_horiz)):
    if (r[i] < 48) and (r[i] > 30):
        x.append(r_horiz[i]*m.cos(psi_horiz[i]))
        y.append(r_horiz[i]*m.sin(psi_horiz[i]))

plt.figure()
plt.xlabel('X-axis (in cm)')
plt.ylabel('Y-axis (in cm)')
plt.title('2D Scan of H')
plt.scatter(x, y)
plt.show()
