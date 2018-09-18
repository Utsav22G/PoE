from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Importing dataset
dataset = np.array([[522, 20], [405, 30], [306, 40], [249, 50], [209, 60]])
X = dataset[:, 0]
y = dataset[:, 1]

# Linear Regression model
lin_reg = LinearRegression()
lin_reg.fit(X, y)

# Polynomial Regression model
poly_reg = PolynomialFeatures(degree = 5)
X_poly = poly_reg.fit_transform(X)
lin_reg_poly = LinearRegression()
lin_reg_poly.fit(X_poly, y)

# Visualising the models
fig = plt.figure()
fig.add_subplot(2,1,1)
plt.scatter(X, y, color = 'red', label = 'Data')
plt.plot(X, lin_reg.predict(X), color = 'blue', label = 'Linear Regression')
plt.title('Linear Regression')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.legend(loc = 'best')

""" Incrementing the steps by 0.1 to increase the resolution
and smoothen the curves."""
X_grid = np.arange(min(X), max(X), 0.1)
X_grid = X_grid.reshape(len(X_grid), 1)

fig.add_subplot(2,1,2)
plt.scatter(X, y, color = 'red',label = 'Data')
plt.plot(X_grid, lin_reg_poly.predict(poly_reg.fit_transform(X_grid)), color = 'blue', label = 'Polynomial Regression')
plt.title('Polynomial Regression')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.legend(loc = 'best')
plt.show()

# Using np.polyfit to create a polynomial model
# m, n, o, p = np.polyfit(X[:, 0], y, 3)
# print("m = ", m, ", n = ", n)

# Predicting new results with Linear Regression
lvl = 6.5
salary = lin_reg.predict(lvl)
print("Linear Regression result:")
print("Salary at Level ", lvl, " is ", salary[0], "\n")

# Predicting new results with Polynomial Regression
lvl = 6.5
salary = lin_reg_poly.predict(poly_reg.fit_transform(lvl))
print("Polynomial Regression result:")
print("Salary at Level ", lvl, " is ", salary[0])
