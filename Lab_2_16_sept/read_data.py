import math as m


for i in range(len(theta)):
    theta[i] = theta[i]*2*m.pi/180
    psi[i] = psi[i]*2*m.pi/180

x = []
y = []
z = []

for i in range(len(r)):
    x.append(r[i]*m.sin(psi[i])*m.cos(theta[i]))
    y.append(r[i]*m.sin(psi[i])*m.sin(theta[i]))
    z.append(r[i]*m.cos(psi[i]))

from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt

fig = plt.figure()
ax = plt.axes(projection = '3d')

ax.scatter3D(x, y, z, 'gray')
