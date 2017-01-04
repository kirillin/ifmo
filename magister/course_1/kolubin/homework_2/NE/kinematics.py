#!/bin/env python
# solving forward and inverse kinematics problems
import numpy
from numpy import identity, dot, transpose
from math import pi, cos, sin, atan2, sqrt
# my modules
from transformations import *


class Kinematics:

    def __init__(self, a, alpha, d, theta):
        self.a = a
        self.alpha = alpha
        self.d = d
        self.theta = theta

    def set_dh_parameters(self, a, alpha, d, theta):
        self.a = a
        self.alpha = alpha
        self.d = d
        self.theta = theta

    def get_dh_d(self):
        return self.d

    def get_dh_theta(self):
        return self.theta

    # forward kinematics
    def forward(self, q, n=6):
        h = identity(4)
        for i in range(0, n):
            rz = rotation_matrix(q[i] + self.theta[i], (0, 0, 1))
            tz = translation_matrix((0, 0, self.d[i]))
            tx = translation_matrix((self.a[i], 0, 0))
            rx = rotation_matrix(self.alpha[i], (1, 0, 0))
            a = concatenate_matrices(rz, tz, tx, rx)
            h = concatenate_matrices(h, a)
        return h

    # inverse kinematics
    def inverse(self, o, r06):
        eps = numpy.finfo(numpy.float).eps
        q = numpy.zeros(24)     # 24, because 4 solves
        q.shape = (4, 6)

        d6 = self.d[5]
        a2 = self.a[1]
        a3 = 2 * self.a[1]

        oc = o - dot(d6 * r06, [0, 0, 1])
        xc, yc, zc = oc

        # position problem
        s = zc - self.d[0]
        r = sqrt(xc**2 + yc**2)
        d = (s**2 + r**2 - a2**2 - a3**2) / (2 * a2 * a3)
        # theta 1
        q[0, 0] = q[2, 0] = atan2(yc, xc)
        q[1, 0] = q[3, 0] = pi + atan2(yc, xc)
        # theta 3
        q[0, 2] = q[1, 2] = atan2(sqrt(abs(1 - d**2)), d)
        q[2, 2] = q[3, 2] = atan2(-sqrt(abs(1 - d**2)), d)
        # theta 2
        q[0, 1] = atan2(s, r) - atan2(2 * a2 * sin(q[0, 2]), a2 + a3 * cos(q[0, 2]))
        q[1, 1] = pi - atan2(s, r) - atan2(2 * a2 * sin(q[0, 2]), a2 + a3 * cos(q[0, 2]))
        q[2, 1] = atan2(s, r) + atan2(2 * a2 * sin(q[1, 2]), a2 + a3 * cos(q[1, 2]))
        q[3, 1] = pi - atan2(s, r) + atan2(2 * a2 * sin(q[1, 2]), a2 + a3 * cos(q[1, 2]))

        # orientation problem
        # i - is one of four solves for position problem
        def solve_orientation(r36, i=0, select_solve=0):
            if abs(r36[0, 2]) > 10 * eps or abs(r36[1, 2]) > 10 * eps:
                if select_solve == 0:
                    q[i, 4] = atan2(sqrt(abs(1 - r36[2, 2]**2)), r36[2, 2])
                    q[i, 3] = atan2(r36[1, 2], r36[0, 2])
                    q[i, 5] = atan2(r36[2, 1], -r36[2, 0])
                elif select_solve == 1:
                    q[i, 4] = atan2(-sqrt(abs(1 - r36[2, 2]**2)), r36[2, 2])
                    q[i, 3] = atan2(-r36[1, 2], -r36[0, 2])
                    q[i, 5] = atan2(-r36[2, 1], r36[2, 0])
            else:
                # TODO both - theta 3 and theta 5 - must be found from matrix R36
                if r36[2, 2] > 0:
                    if select_solve == 0:
                        q[i, 4] = 0
                        # any
                        q[i, 3] = atan2(r36[1, 0], r36[0, 0])
                        q[i, 5] = 0
                    else:
                        q[i, 4] = 0
                        # any
                        q[i, 3] = 0
                        q[i, 5] = atan2(r36[1, 0], r36[0, 0])
                else:
                    if select_solve == 0:
                        q[i, 4] = pi
                        # any
                        q[i, 3] = atan2(r36[1, 0], r36[0, 0])
                        q[i, 5] = 0
                    else:
                        q[i, 4] = pi
                        # any
                        q[i, 3] = 0
                        q[i, 5] = atan2(r36[1, 0], r36[0, 0])

        # finding orientation matrix for one of configurations
        #   first tree angles
        # each configuration have two orientation
    # for 0 (from matrix q)
        h03 = self.forward(q[0], n=3)
        r03 = h03[:3, :3]
        r36 = dot(transpose(r03), r06)
        solve_orientation(r36, 0, select_solve=0)
    # for 1 (from matrix q)
        h03 = self.forward(q[1], n=3)
        r03 = h03[:3, :3]
        r36 = dot(transpose(r03), r06)
        solve_orientation(r36, 1, select_solve=1)
    # for 2 (from matrix q)
        h03 = self.forward(q[2], n=3)
        r03 = h03[:3, :3]
        r36 = dot(transpose(r03), r06)
        solve_orientation(r36, 2, select_solve=0)
    # for 3
        h03 = self.forward(q[3], n=3)
        r03 = h03[:3, :3]
        r36 = dot(transpose(r03), r06)
        solve_orientation(r36, 3, select_solve=1)
        return q

