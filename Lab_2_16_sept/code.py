#   Importing libraries
import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


calib_data = np.array([[20, 522], [30, 405], [40, 306], [50, 249], [60, 209]])
X_calib = calib_data[:,0]
Y_calib = calib_data[:,1]

# dist = 118.686 * e^(-0034606*y)

d = []
for i in range(len(Y_calib)):
    d.append(118.686 * math.exp(-0.003406*Y_calib[i]))

plt.plot(X_calib, Y_calib, 'bo', label='Data Points')
plt.plot(d, Y_calib, 'g-', label='Calibration Curve')
plt.legend(loc='upper left')
plt.title('Calibration Curve')
plt.xlabel('Distance (in cm)')
plt.ylabel('Analog Voltage Level')
plt.show()

test_data = np.array([[15, 17.6], [25, 24.7], [35, 35.6], [46, 46.2], [55, 54.4]])
x = np.linspace(0, 100, num=100)

plt.plot(test_data[:,0], test_data[:,1], 'b-', label='Ratio of Measured vs Actual distance')
plt.plot(x, 'k:', label='Y=X')
plt.xlim(15, 55)
plt.ylim(15, 55)
plt.xlabel('Actual distance  (in cm)')
plt.ylabel('Measured distance (in cm)')
plt.legend(loc='upper left')
plt.title('Comparing Actual and Measured distance')
plt.show()
