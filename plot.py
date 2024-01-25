#!/usr/bin/env python
# coding: utf-8
'''
Created on Di 24 Jan 2017 17:46:39 CET


@author: Stefan Wallner
'''


# std includes
import os
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d
import numpy as np




def main():

	if os.path.exists("grid.txt"):
		data = np.loadtxt("grid.txt");
		x = np.linspace(0,1,data.shape[0])
		y = np.linspace(0,1,data.shape[1])
		X,Y = np.meshgrid(x,y)


		fig = plt.figure()
		ax = fig.add_subplot(1, 1, 1, projection='3d')
		ax.plot_wireframe(X, Y, data, rstride=10, cstride=10)
		plt.xlabel("X")
		plt.ylabel("Y")
		ax.set_zlabel("U")


	plt.show()
	exit(0)


if __name__ == '__main__':
	main()
