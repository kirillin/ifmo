#!/bin/env python
import numpy
from numpy import pi, transpose, dot, eye, zeros, cross
# my modules
from init import *


# returns tensor of inertia for center of mass of a link
# m - mass; l = length; r -- radius of link (cylinder!)
def I(m, l, r):
    Icf = zeros((3, 3))
    Icf[0, 0] = m * r**2 / 2
    Icf[1, 1] = m * (3 * r**2 + l**2) / 12
    Icf[2, 2] = Icf[1, 1]
    return Icf


# returns tensor of inertia for offset d = (x, y, z)
def J(Icf, m, d):
    kronecker = lambda x, y: 1 if x == y else 0
    Jff = zeros((3, 3))
    for i in range(0, 3):
        for j in range(0, 3):
            Jff[i, j] = Icf[i, j] + m * (dot(d, d) * kronecker(i, j) + d[i] * d[j])
    return Jff


# returns transormation matrix
#   ^iH_j
# !!! the i must be less then j
# ks -- object of class Kinematics
def H(ks, q, i, j):
    H0i = ks.forward(q, i)
    H0j = ks.forward(q, j)
    Hij = transpose(H0i).dot(H0j)
    return Hij


# returns rotation matrix
# ^iR_j
# !!! the i must be less then j
# ks -- object of class Kinematics
def R(ks, q, i, j):
    return H(ks, q, i, j)[:3, :3]


# inverse problem.
# RNEA
# ks -- object of class Kinematics
def NE(q, dq, ddq, ks, G=9.81):
    # initialisation empty arrays
    omega = zeros((3, robot.N + 1))
    dOmega = zeros((3, robot.N + 1))
    a = zeros((3, robot.N + 1))
    ac = zeros((3, robot.N + 1))
    f = zeros((3, robot.N + 2))
    tau = zeros((3, robot.N + 2))
    u = zeros((3, robot.N + 2))
    # initialisation gravitation vector
    a[:, 0] = [0, G, 0]
    for i in range(1, robot.N + 1):
        transposedR = transpose(R(ks, q, i-1, i))
        omega[:, i] = transposedR.dot(omega[:, i-1] + dq[i-1] * robot.z[:, i-1])
        dOmega[:, i] = transposedR.dot(dOmega[:, i-1] + ddq[i-1] * robot.z[:, i-1] +
                                               cross(dq[i-1] * omega[:, i-1], robot.z[:, i-1]))
        # vec_r[:, i-1] because len(vec_r) == 2 and index of first element is equals to 0 and i start from 1
        a[:, i] = transposedR.dot(a[:, i-1] + cross(dOmega[:, i], robot.vec_r[:, i-1]) +
                                  cross(omega[:, i], cross(omega[i], robot.vec_r[:, i-1])))
        ac[:, i] = a[:, i] + cross(dOmega[i], robot.vec_rc[:, i-1]) + \
               cross(omega[i], cross(omega[i], robot.vec_rc[:, i-1]))

    for i in range(robot.N, 0, -1):
        Icf = I(robot.m[i-1], robot.l[i-1], robot.diameter[i-1] / 2)
        # vector for tensor inertia in fixed frame
        vec_offset = [-robot.r[i-1], 0, 0]
        Jff = J(Icf, robot.m[i-1], vec_offset)
        f[:, i] = f[:, i-1] + robot.m[i-1] * (ac[:, i] - 0 * robot.g[i-1])
        tau[:, i] = tau[:, i+1] - \
                    cross(f[:, i], (robot.vec_r[:, i-1] + robot.vec_rc[:, i-1])) + \
                    cross(f[:, i+1], robot.vec_rc[:, i-1]) + \
                    Jff.dot(dOmega[i]) + cross(omega[i], (Jff.dot(omega[i])))
        u[:, i] = transpose(tau[:, i]) * robot.z[:, i-1] + robot.nu[i-1] * dq[i-1]
        #print(u)
    return u[2][1:3]


