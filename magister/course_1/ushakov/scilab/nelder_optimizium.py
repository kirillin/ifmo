#!/usr/bin env python3
""" see example below """
import scipy.linalg
import numpy.linalg
import scipy.optimize
from scipy.linalg import norm, solve_sylvester
from numpy import poly, roots, real, imag
from scipy import matrix
import scipy.optimize
from scipy.linalg import norm, solve_sylvester, eig
from numpy.linalg import cond
from numpy import poly, roots, real, imag
from intervalium_arithmeticum import *

from matrix_coefficientium import getCoefs, geta, getaLevere
from scipy import matrix

q1 = q2 = q3 = q4 = q5 = q6 = q7 = [-0.2, 0.2]

# коэффициенты передаточной функции (ПФ)
b1 = div(plus(1, q1), mul(4., mul(plus(1., q3), plus(1., q6))))
b2 = div(plus(1, q2), mul(30., mul(plus(1., q3), plus(1., q6))))
a1 = mul(-1, div(plus(mul(20., mul(plus(1., q3), plus(1., q7))), mul(3.6, mul(plus(1., q4), plus(1., q6)))), mul(12., mul(plus(1., q3), plus(1., q6)))))
a2 = mul(-1, div(mul(plus(1., q4), plus(1., q7)), mul(2., mul(plus(1., q3), plus(1., q6)))))

# запись векторно-матричного представления в канонической наблюдаемой форме
A = [[0, a2],
     [1, a1]]
B = [[b2],
     [b1]]
C = [0, 1]

"I -- пункт алгоритма 3.1 и пятое задание, ибо требуется"
# запись матриц с буферной системой \tilde{A}. стр 82 методички
tA = [[0, a2, b2],
      [1, a1, b1],
      [0, 0, 0]]
tB = [[0],
      [0],
      [1]]
tC = [0, 1, 0]
uA = matrix(getUpper(tA))
oA = matrix(getOver(tA))
A0 = 0.5 * (uA + oA)
udA = uA - A0
odA = oA - A0
dA = makeInterval(udA, odA)
def condM(H, A, Lambda, B):
    """ condition number of matrix M """
    M = scipy.linalg.solve_sylvester(-A, Lambda, -B * H)
    cM = numpy.linalg.cond(M)
    return cM


def minCondM(omega0, A, Lambda, B, H):
    Lambda = float(omega0) * Lambda
    "IV -- 2 пункт алгоритма 3.2 -- поиск матрицы H, чоб cond(M) стала 1 (Нелдер-Мид)"
    H, cM = fminsearch(matrix(A), Lambda, matrix(B), matrix(H))
    print("matrix H = " + str(H))
    print("norm(M)_min = " + str(cM))
    return cM


def minCondMAlisa(w0, A, Lambda, B, H):
    # a3 = w0**3
    # a2 = 2 * w0**2
    # a1 = 2 * w0
    # a0 = 1
    # r = roots([a0, a1, a2, a3])
    # print(r)
    # Lambda = [[real(r[1]), imag(r[1]), 0],
    #           [imag(r[2]), real(r[2]), 0],
    #           [0, 0, real(r[0])]]
    # Lambda = [[0, 0, -a3],
    #           [1, 0, -a2],
    #           [0, 1, -a1]]
    # Lambda = [[w0[0], w0[1], 0],
    #           [w0[2], w0[3], 0],
    #           [0, 0, w0[4]]]
    Lambda = [[w0[0], -0, 0],
              [0, w0[1], 0],
              [0, 0, w0[2]]]

    Lambda = matrix(Lambda) * 500
    "IV -- 2 пункт алгоритма 3.2 -- поиск матрицы H, чоб cond(M) стала 1 (Нелдер-Мид)"
    H, cM = fminsearch(matrix(A), Lambda, matrix(B), matrix(H))
    # if cM < 3:
    M = scipy.linalg.solve_sylvester(-matrix(A), Lambda, -matrix(B)* matrix(H))
    try:
        F0 = M * Lambda * M ** (-1)
        uF = F0 + udA
        oF = F0 + odA
        dF = makeInterval(uF, oF)
        cfs = getCoefs(dF)
        if min(min(cfs)) >= 0:
            print("norm(Lambda) = " + str(norm(Lambda)))
            print("cond(M)_min = " + str(cM))
            print('*******************')
            uf = poly(matrix(uF))
            of = poly(matrix(oF))
            print(uf)
            print(of)
            print(cfs)
            print("Lambda = " + str(Lambda))
            print("H = " + str(H))
            print("M = " + str(M))

    except:
        print("SINGULAR")
    print("cond(M)_min = " + str(cM))
    return cM


def fminsearch(A, Lambda, B, H0, maxiter=1000):
    """ Nelder-Mead minimization algorithm """
    margarita = lambda H: condM(H, A, Lambda, B)
    xopt, fopt, _, _, _ = scipy.optimize.fmin(func=margarita, x0=H0, maxiter=maxiter, full_output=True)
    return xopt, fopt


def fminsearchAnna(omega0, A, Lambda, B, H0):
    "for fixed Lambda"
    anna = lambda w: minCondM(w, A, Lambda, B, H0)
    w0, fopt, _, _, _ = scipy.optimize.fmin(func=anna, x0=omega0, maxiter=200, full_output=True)
    return w0, fopt


def fminsearchAlisa(omega0, A, Lambda, B, H0):
    "for Lambda in diag form"
    alisa = lambda w: minCondMAlisa(w, A, Lambda, B, H0)
    w0, fopt, _, _, _ = scipy.optimize.fmin(func=alisa, x0=omega0, maxiter=1000, full_output=True)
    return w0, fopt


if __name__ == '__main__':
    """ example of using module """
    A = matrix([[0., -0.6675, 0.0342],
                [1.0000, -2.6495, 0.3039],
                [0., 0., 0.]])
    B = matrix([[0.], [0.], [1.]])
    C = matrix([0., 1., 0.])
    # Lambda = matrix([[-1.2000, 2.0785, 0],
    #                  [-2.0785, -1.2000, 0],
    #                  [0, 0, -1]])
    Lambda = 0.79 * matrix([[-1, 0, 0],
                            [0, -0.7, 0],
                            [0, 0, -1.3]])
    # see here!
    H0 = matrix([1., 1., 1.])
    H, cM = fminsearch(A, Lambda, B, H0)
    print(H, cM)
    M = scipy.linalg.solve_sylvester(-A, Lambda, -B * H)
    print(M)

