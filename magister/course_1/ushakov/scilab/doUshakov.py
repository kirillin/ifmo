#!/usr/bin/env python3
# coding: utf8
"""
    main file for solve Prof. Ushakov's problem #6 (и пятое в принципе)
    <<Синтез закона медианного модального управления>>
    SPb, 2017

    ДЛЯ ОУ, ПФ которого имеет коэффициенты, согласно варианта ААББАААА
        b0, b1 = 3., 0.4
        a0, a1, a2, a3, a4 = 2., 0.6, 0, 6, 10
***
    чтобы нормально пользоваться матрицами (складывать, умножать и проч.)
        нужно (для НЕинтервальных матриц, конешн) преобразовать тип
            из list в scipy.matrix (потому что matrix
                не умеет иметь своими элементами list'ы)
    uA -- upper{A}
    oA -- over{A}
    A0 -- медиана матрицы A
    dA -- интервальный компонент матицы A

"""
from scipy import matrix
import scipy.optimize
from scipy.linalg import norm, solve_sylvester, eig
from numpy.linalg import cond
from numpy import poly, roots, real, imag
from intervalium_arithmeticum import *
from  nelder_optimizium import fminsearch, fminsearchAlisa, fminsearchAnna
from matrix_coefficientium import getCoefs, geta, getaLevere, det

"ВЫЧИСЛЕНИЕ КОЭФФИЦИЕНТОВ ПЕРЕДАТОЧНОЙ ФУНКЦИИ"
#q1 = q2 = q3 = q4 = q5 = q6 = q7 = 0.    # номинальная система
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

"II -- пункт алгоритма 3.1 -- требования к системе"
tp = 2
sigma = 5
deltaIR = 0.02
w0 = 3
#
"III -- пункт алгоритма 3.1 -- формирование матрицы \Lambda"
# ||Lambda|| >= cond(M)^3 * (||dA|| / deltaIR) (предполагая cond(M) = 1)
normdA = norm(odA)

# A0 = [[0., - 0.749,         0.064],
#       [1., - 0.224,         0],
#       [0., 0., - 1.]]
# A0 = matrix(A0)
# udA = [[0., - 0.412, - 0.047],
#        [0., - 0.124, - 0],
#        [0.,          0.,            0.]]
# odA = [[0.,          0.412,         0.047],
#        [0.,          0.124,         0],
#         [0., 0., 0.]]
# B = [[0],
#      [0],
#      [1]]
# C = [0, 1, 0]
# Lambda = [  [-1, 0, 0],
#             [0, -0.7, 0],
#             [0, 0, -1.3]]
Lambda = [[-0.23556989,  1.76541707,  0.        ],
 [-0.0738662,  -2.27511469,  0.        ],
 [ 0.,          0.,         -3.08861299]]
H0 = [1, 1, 1]
#w0 = [-0.7, 0.7, -0.7, -0.7, -1.3, 30] # cond(M) 1
w0 = [-1, -0.7, -1.3, 3] # cond(M) 1
w0 = [ 0.07181391,  0.93004605 ,-0.55640068 ,-1.41296885, -1.51600497 , 0.54357359]
H = [-14.72547841 ,-65.13505061 , 19.33903897]

Lambda = [[w0[0], -0, 0],
          [0, w0[1], 0],
          [0, 0, w0[2]]]
Lambda = [[w0[0], w0[1], 0],
          [w0[2], w0[3], 0],
          [0, 0, w0[4]]]
Lambda = matrix(Lambda) * w0[5]*3
# w0 = [-0.7, 0.7, -0.7, -0.7, -1.3, 30] # cond(M) 1
w0 = [-1, -0.7, -1.3] # cond(M) 1
#w0, cM = fminsearchAnna(w0, matrix(A0), Lambda, matrix(tB), matrix(H0))
w0, cM = fminsearchAlisa(w0, matrix(A0), Lambda, matrix(tB), matrix(H0))
print(w0, cM)
#Lambda = matrix(Lambda)
nLambda = norm(Lambda)
conition = normdA / deltaIR
print("norm(Lambda) = %f\nnormdA / deltaIR = %f" % (nLambda, conition))
"IV -- 2 пункт алгоритма 3.2 -- поиск матрицы H, чоб cond(M) стала 1 (Нелдер-Мид)"
H, cM = fminsearch(matrix(A0), Lambda, matrix(tB), matrix(H0))
# print("matrix H = " + str(H))
# print("cond(M)_min = " + str(cM))


"V -- "
Lambda = [[  -2.29765025,    0. ,           0.,        ],
 [   0.         ,  -0.28491155  ,  0.        ],
 [   0.         ,   0.      ,   -246.1036489 ]]
H = [ -4.29851934e-03 , -2.29278489e-06  , 2.38744173e+00]
M = [[ -2.64051117e-03 , -8.93915334e-03 , -1.62991967e-06],
 [ -9.11914470e-03 , -3.78140147e-03 , -1.20996537e-05],
 [ -1.87083275e-03  ,-8.04735670e-06,   9.70096031e-03]]
Lambda = matrix(Lambda)


H = matrix(H)
M = matrix(M)
M = solve_sylvester(-A0, Lambda, -matrix(tB) * H)
print(cond(M))
F0 = M * Lambda * M**(-1)
K = H * M**(-1)
F = A0 - tB * K
Kg = -(tC * F**(-1) * matrix(tB))**(-1)
G = tB * Kg

uF = F0 + udA
oF = F0 + odA
# uf = getCoefs(uF.tolist())
# of = getCoefs(oF.tolist())
# dF = makeInterval(uF, oF)
# df = getCoefs(dF)
# print(df)


# uF =[[0., - 1.161, 0.017],
#     [1., - 0.348, 0.],
#     [- 1073.2996, - 1363.9993, - 14.776]]
#
#
# oF = [[0., - 0.337, 0.111],
#         [1., - 0.1, 0.],
#         [- 1073.2996, - 1363.9993, - 14.776]]

dF = makeInterval(matrix(uF), matrix(oF))

print(poly(matrix(uF)))
print(poly(matrix(oF)))
print(getCoefs(dF))
# print(geta(3, dF))
# print(getaLevere(3, dF))

print("norma = " + str(norm(uA)/norm(F)))

print(dF)
print(det(dF))
F = dF
s1 = mul(mul(F[0][0],F[1][1]),F[2][2])
s2 = mul(mul(F[0][0],F[1][2]),F[2][1])
s3 = mul(mul(F[0][1],F[1][0]),F[2][2])
s4 = mul(mul(F[0][1],F[1][2]),F[2][0])
s5 = mul(mul(F[0][2],F[1][0]),F[2][1])
s6 = mul(mul(F[0][2],F[1][1]),F[2][0])

f3 = minus(plus(plus(minus(minus(s1,s2), s3), s4), s5), s6)
print(f3)