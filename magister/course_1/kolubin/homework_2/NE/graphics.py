#!/bin/env python
import numpy
import matplotlib.pyplot as plt
# my modules
from kinematics import *
from trajectory import *
from dynamics import *
from init import *


def plotMany(interval, lables, *vectors2xN):
    line_styles = ['r-', 'k:', 'b--', 'g-.', 'c.', 'm,', 'ko']
    time = numpy.arange(interval[0], interval[1] + interval[2], interval[2])
    plt.figure()
    for i in range(0, len(vectors2xN)):
        plt.subplot(211)
        plt.plot(time, vectors2xN[i][0], line_styles[i], label=lables[i], linewidth=2)
        plt.xlabel('t, [sec]')
        plt.legend(loc='upper left', shadow=True, fontsize='x-small')
        plt.grid(True)
        plt.subplot(212)
        plt.plot(time, vectors2xN[i][1], line_styles[i], label=lables[i], linewidth=2)
        plt.xlabel('t, [sec]')
        plt.legend(loc='upper left', shadow=True, fontsize='x-small')
        plt.grid(True)
    plt.show()

# must call plt.show() after call it function
def plotTrajectory(q, dq, ddq, time, num_figure=0, color="r"):
    title = "Generalized coordinate q%s" % (num_figure)
    plt.figure(title)
    plt.subplot(311)
    plt.plot(time, q, color)
    plt.ylabel('q, [rad]')
    plt.xlabel('t, [sec]')
    plt.grid(True)
    plt.subplot(312)
    plt.plot(time, dq, color)
    plt.ylabel('dq, [rad/sec]')
    plt.xlabel('t, [sec]')
    plt.grid(True)
    plt.subplot(313)
    plt.plot(time, ddq, color)
    plt.ylabel('ddq, [rad/sec^2]')
    plt.xlabel('t, [sec]')
    plt.grid(True)
    print('[WARNING] Should call plt.show()')


# after call must be call plt.show()
def plotTrajectories(Q, dQ, ddQ, interval):
    time = numpy.arange(interval[0], interval[1]+interval[2], interval[2])
    for i in range(0, len(Q)):
        plotTrajectory(Q[i], dQ[i], ddQ[i], time, i+1)
    #plt.show()



def plotAllDynamics():
    q, q2, q3 = getTrajectories(trajectory.initQ,
                                trajectory.initDotQ,
                                trajectory.initDDotQ,
                                trajectory.interval)
    time = numpy.arange(trajectory.interval[0],
                        trajectory.interval[1],
                        trajectory.interval[2])
    qty_times = len(time)
    ks = Kinematics(robot.a, robot.alpha, robot.d, robot.theta)

    Omega = zeros((robot.N, qty_times))
    DOmega = zeros((robot.N, qty_times))
    A = zeros((robot.N, qty_times))
    Ac = zeros((robot.N, qty_times))
    F = zeros((robot.N, qty_times))
    Tau = zeros((robot.N, qty_times))
    U = zeros((robot.N, qty_times))

    for k in range(0, qty_times):
        omega, dOmega, a, ac, f, tau, u = NE(q[:, k], q2[:, k], q3[:, k], ks)
        #print(f)
        Omega[0, k] = omega[2, 1]
        Omega[1, k] = omega[2, 2]
        DOmega[0, k] = dOmega[2, 1]
        DOmega[1, k] = dOmega[2, 2]
        A[0, k] = a[2, 1]
        A[0, k] = a[2, 2]
        Ac[1, k] = ac[2, 1]
        Ac[1, k] = ac[2, 2]
        F[0, k] = f[2, 1]
        F[1, k] = f[2, 2]
        Tau[0, k] = tau[2, 1]
        Tau[1, k] = tau[2, 2]
        U[0, k] = u[2, 1]
        U[1, k] = u[2, 2]

    plt.figure("Omega and dot Omega")
    plt.subplot(211)
    plt.plot(time, Omega[0], "b")
    plt.plot(time, DOmega[0], "g--")
    plt.grid(True)
    plt.subplot(212)
    plt.plot(time, Omega[1], "b")
    plt.plot(time, DOmega[1], "g--")
    plt.grid(True)

    plt.figure("a and ac")
    plt.subplot(211)
    plt.plot(time, A[0], "b")
    plt.plot(time, Ac[0], "g--")
    plt.grid(True)
    plt.subplot(212)
    plt.plot(time, A[1], "b")
    plt.plot(time, Ac[1], "g--")
    plt.grid(True)

    plt.figure("f, tau and u")
    plt.subplot(211)
    plt.plot(time, F[0], "b", label='force')
    plt.plot(time, Tau[0], "k--", label='torque')
    plt.plot(time, U[0], "r-.", label='u')
    plt.legend(loc='upper right', shadow=True, fontsize='x-small')
    plt.grid(True)
    plt.subplot(212)
    plt.plot(time, F[1], "b", label='force')
    plt.plot(time, Tau[1], "k--", label='torque')
    plt.plot(time, U[1], "r-.", label='u')
    plt.legend(loc='upper right', shadow=True, fontsize='x-small')
    plt.grid(True)
    #plt.show()
    plotTrajectories(q, q2, q3, trajectory.interval)