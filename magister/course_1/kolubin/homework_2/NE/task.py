import numpy
# my modules
from kinematics import *
from trajectory import *
from dynamics import *
from init import *
from graphics import *


# returns U
# where first row for first link
#       second row for second link
def invdyn(Q, dQ, ddQ, ks, G=9.81):
    U = zeros((robot.N, len(Q[0])))
    for i in range(0, len(Q[0])):
        u = NE(Q[:, i], dQ[:, i], ddQ[:, i], ks, G)
        U[:, i] = u
    return U


def main():
    ks = Kinematics(robot.a, robot.alpha, robot.d, robot.theta)
    Q, dQ, ddQ = getTrajectories(trajectory.initQ,
                                 trajectory.initDotQ,
                                 trajectory.initDDotQ,
                                 trajectory.interval)
    plotTrajectories(Q, dQ, ddQ, trajectory.interval)

    zero = zeros((robot.N, len(Q[0])))
    e = zero.copy()

    # (a) complete inverse dynamics
    U = invdyn(Q, dQ, ddQ, ks)
    # (b) gravity terms
    g = invdyn(Q, zero, zero, ks)

    # (c) centrifugal and Coriolis terms
    c = invdyn(Q, dQ, zero, ks, G=0)

    # (d) i-th column of the inertia matrix
    qty_elements = (trajectory.interval[1] - trajectory.interval[0]) / trajectory.interval[2] + 1
    MmatrixJoint1 = zeros((robot.N, qty_elements))
    MmatrixJoint2 = zeros((robot.N, qty_elements))
    Mcol = zeros((robot.N, robot.N))
    for j in range(1, robot.N + 1):
        e[:, :] = 1
        for i in range(0, robot.N):
            Mcol = invdyn(Q, zero, e, ks, G=0)
        MmatrixJoint1[j - 1] = Mcol[0]
        MmatrixJoint2[j - 1] = Mcol[1]

    # (e) generalized momentum
    Mt = invdyn(Q, zero, dQ, ks, G=0)

    lables = ('complete inverse dynamics',
              'gravity',
              'Coriolis/centrifugal',
              'inertia',
              'generalized momentum',)
    # drawing inertia matrix only first column
    plotMany(trajectory.interval, lables, U, g, c, (MmatrixJoint1[0], MmatrixJoint2[0]), Mt)
main()
