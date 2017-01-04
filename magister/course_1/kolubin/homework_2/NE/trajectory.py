#!/bin/env python
import numpy
from numpy import zeros
from math import factorial
import warnings
warnings.filterwarnings("ignore", category=numpy.VisibleDeprecationWarning)


# Calculation value of polynomial h(t) for itself order
#   coefficients = (a0, a1, a2 etc.)
def calculatePolynom(order, coefficients, time, derivative=0):
    h = 0
    for i in range(derivative, order + 1):
        h += (factorial(i) / factorial(i - derivative)) * coefficients[i] * time**(i - derivative)
    return h

# returns coefficients for our polynom
def getCoefficients(iqs, idqs, iddqs, iqe, idqe, iddqe):
    # x = A^(-1) b
    # x = transpose([a3, a4, a5])
    A = [
        [1, 1, 1],
        [3, 4, 5],
        [6, 12, 20]
    ]
    b = [
        [iqe - iqs - idqs - iddqs / 2],
        [idqe - iqs - iddqs],
        [iddqe - iddqs]
    ]
    x = numpy.linalg.solve(A, b)
    # a0, a1, a2, a3, a4, a5
    coefficients = [iqs, idqs, iddqs, x[0], x[1], x[2]]
    return coefficients


# relative time from absolute
# tau \in [real_time1, real_time2];
# j -- real time;
# i -- number of part trajectory (npt) (for multypolynomal traj.)
def get_t(tau, j, i):
    return (j - tau[i - 1]) / (tau[i] - tau[i - 1])


def getTrajectory(iq, idq, iddq, tau, step=0.1, npt=1):
    time = numpy.arange(tau[0], tau[1]+step, step)
    qty_time = len(time)
    q = zeros(qty_time, numpy.float)
    dq = zeros(qty_time, numpy.float)
    ddq = zeros(qty_time, numpy.float)
    coefficients = getCoefficients(iq[0], idq[0], iddq[0],
                                   iq[1], idq[1], iddq[1])
    for i in range(0, len(time)):
        isEndTrajectory = lambda x: 1 if x == len(time)-1 else 1
        t = get_t(tau, time[i], npt)
        q[i] = calculatePolynom(5, coefficients, t)
        dq[i] = calculatePolynom(5, coefficients, t, 1)
        ddq[i] = calculatePolynom(5, coefficients, t, 2)
    return q, dq, ddq


def getTrajectories(initQ, initDotQ, initDDotQ, interval):
    qty_links = len(initQ)
    qty_times = (interval[1] - interval[0]) / interval[2] + 1
    Q = zeros((qty_links, qty_times), numpy.float)
    dQ = zeros((qty_links, qty_times), numpy.float)
    ddQ = zeros((qty_links, qty_times), numpy.float)
    for i in range(0, len(initQ)):
        qi, dqi, ddqi = getTrajectory(initQ[i], initDotQ[i], initDDotQ[i], (interval[0], interval[1]), interval[2])
        Q[i] = qi
        dQ[i] = dqi
        ddQ[i] = ddqi
    return Q, dQ, ddQ
