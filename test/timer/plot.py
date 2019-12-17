#!/usr/bin/python2
import matplotlib.pyplot as plt
import numpy as np
import csv
import sys
from matplotlib import rcParams
from scipy import signal
import scipy

def read_trans(filename):
    return np.transpose(np.loadtxt(open(filename),delimiter=','))


def plot(xdata, xname, ydata, yname, figname, legend_loc='default'):
	#rcParams.update({'figure.autolayout': True})
    plt.clf()
    font = {'size': 18}
    plt.rc('font', **font)  # pass in the font dict as kwargs
    #plt.tight_layout()
    plt.xlabel(xname)
    plt.ylabel(yname)
    plt.plot(xdata, ydata, "-k")
    if legend_loc != 'default':
        plt.legend(loc=legend_loc)
    plt.savefig(figname+'.png', format='png', bbox_inches = "tight")
    plt.clf()
    print figname+'.png'

def plotfunc(func):
    filename = "timer"+func+".csv"
    figname = func
    data = read_trans(filename)
    xname = "Data Size"
    yname = "Time/ns"
    plot(data[0], xname, data[1], yname, figname)

if __name__ == '__main__':
    plotfunc("Amplitude")
    plotfunc("Multiplication")
    plotfunc("TransformTo")
