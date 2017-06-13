from scipy import matrix
from intervalium_arithmeticum import *
"""
    for polynoms form:
        D(x) = [a0] x^n + [a1] x^(n-1) + ... + an
"""


def eye(n):
    "interval I = diag([1,1]) matrix"
    I = [[[0., 0.] for j in range(n)] for i in range(n)]
    for i in range(n):
        I[i][i] = [1., 1.]
    return I


def zero(n):
    "intervals Zerox matrix"
    Z = [[[0., 0.] for j in range(n)] for i in range(n)]
    return Z

def mulmx(A, B):
    R = [[[0.,0.],[0.,0.],[0.,0.]],
         [[0.,0.],[0.,0.],[0.,0.]],
         [[0.,0.],[0.,0.],[0.,0.]]]
    for i in range(0, len(A)):
        for j in range(0, len(A)):
            for r in range(0, len(A)):
                R[i][j] = plus(R[i][j], mul(A[i][r], B[r][j]))
    return R

def powMx(A, pow):
    if pow == 0:
        return I
    B = A
    for i in range(1, pow):
        B = mulmx(B, A)
    return B

def mulmxscal(scal, A):
    R = [[[1.,1.],[0.,0.],[0.,0.]],
     [[0.,0.],[1.,1.],[0.,0.]],
     [[0.,0.],[0.,0.],[1.,1.]]]
    for i in range(0, len(A)):
        for j in range(0, len(A)):
            R[i][j] = mul(A[i][j], scal)
    return R


def trSimp(A):
    t = [0., 0.]
    for i in range(0, len(A)):
        t = plus(t, A[i][i])
    return t

def tr(A, H):
    t = [0., 0.]
    R = mulmx(A, H)
    for i in range(0, len(A)):
        t = plus(t, R[i][i])
    return t


def getH(k, A, ak):
    if k == 0:
        return H0
    Hkm1 = zero(len(A))
    LOL = zero(len(A))
    Hkm1 = mulmx(A, getH(k-1, A, geta(k-1, A)))
    LOL = mulmxscal(ak, I)
    for i in range(0, len(A)):
        for j in range(0, len(A)):
            Hkm1[i][j] = plus(Hkm1[i][j], LOL[i][j])
    return Hkm1



def trace(A):
    n = len(A)
    s = [0., 0.]
    for i in range(n):
        s = plus(s, A[i][i])
    return s


def M(i, j, A):
    """
        A = [[1,2,3],
             [4,5,6],
             [7,8,9]]
        print(M(1,1,A))
        >> [[1, 3],
            [7, 9]]
    """
    n = len(A)
    if n == 0:
        print('wtf? Matrix is empty!')
    elif n == 1:
        return A
    elif n == 2:
        return A[n-i-1][n-j-1]
    elif n >= 3:
        T = [[0., 0.] for k in range(n-1)]
        for u in range(n):
            for v in range(n):
                if u > i:
                    if v > j:
                        T[u-1][v-1] = A[u][v]
                    elif v < j:
                        T[u-1][v] = A[u][v]
                elif u < i:
                    if v > j:
                        T[u][v-1] = A[u][v]
                    elif v < j:
                        T[u][v] = A[u][v]
        return T


def det(A, row=0):
    if type(A) == int:
        return A
    n = len(A)
    if n == 1 and type(A[0]) in [int, float]:
        return A
    if n == 2 and type(A[0]) is not list:
        return A
    try:
        d = [0., 0.]
        for j in range(n):
            margarita = mul((-1)**(2+j), mul(A[row][j], mul((-1)**(row+j),det(M(row, j, A)))))
            d = plus(d, margarita)
        return d
    except IndexError:
        print(A)

def prepareMatrix(A):
    n = len(A)
    for i in range(n):
        for j in range(n):
            t = type(A[i][j])
            if t == int or t == float:
                A[i][j] = [float(A[i][j]), float(A[i][j])]
    return A


def getCoefs(F, method='KRAMER'):
    n = len(F)
    a = [(0., 0.) for j in range(n+1)]
    F = prepareMatrix(F)
    if method == 'KRAMER':
        a[0] = (1., 1.)
        a[1] = mul(-1, trace(F))
        for k in range(2, n):
            alisa = [0., 0.]
            for g in range(0, k):
                alisa = plus(alisa, det(M(g, g, F)))
            if k == n:
                a[k] = alisa
            else:
                a[k] = mul((-1)**k, alisa)
        a[n] = mul((-1)**n, det(F))
        return a

if __name__ == '__main__':
    A = [[-1,2,3],[4,5,6],[7,8,9]]
    # A = [[0.,1.],
    #      [[-900.3333, -899.6667],[-43.4264, -41.4264]]]
    print(trace(A))
    print(getCoefs(A))


#
# uF = [[0,   -0.7238,    0.0050],  [1.0000,   -2.8544,    0.0850], [371.0759,  -87.7479,   -4.0333]]
# oF = [[0,   -0.2712,    0.0617],  [1.0000,   -1.0790,    0.4150], [371.0759,  -87.7479,   -4.0333]]
#
# F = [[ [uF[0][0], oF[0][0]], [uF[0][1], oF[0][1]], [uF[0][2], oF[0][2]] ],
#      [ [uF[1][0], oF[1][0]], [uF[1][1], oF[1][1]], [uF[1][2], oF[1][2]] ],
#      [ [uF[2][0], oF[2][0]], [uF[2][1], oF[2][1]], [uF[2][2], oF[2][2]] ]]
#
# F = A
# n = 3
# f0 = [1, 1]
# f1 = [0., 0.]
# for i in range(0, n):
#     f1 = plus(f1, F[i][i])
# f1 = mul([-1, -1], f1)
#
# M11 = minus(mul(F[1][1],F[2][2]), mul(F[2][1],F[1][2]))
# M22 = minus(mul(F[0][0],F[2][2]), mul(F[2][0],F[0][2]))
# f2 = plus(M11, M22)
#
# s1 = mul(mul(F[0][0],F[1][1]),F[2][2])
# s2 = mul(mul(F[0][0],F[1][2]),F[2][1])
# s3 = mul(mul(F[0][1],F[1][0]),F[2][2])
# s4 = mul(mul(F[0][1],F[1][2]),F[2][0])
# s5 = mul(mul(F[0][2],F[1][0]),F[2][1])
# s6 = mul(mul(F[0][2],F[1][1]),F[2][0])
#
# f3 = minus(plus(plus(minus(minus(s1,s2), s3), s4), s5), s6)
#
# print(f0, f1,f2,f3)


#

# # Fadeev's method of coeffs
def geta(k, A):
    if k == 0:
        return [1., 1.]
    return mul([-1./k, -1./k], trace(mulmx(A, getH(k-1, A, geta(k-1, A)))))


n = 3
a = [[0.,0.] for i in range(n)]
a[0] = [1., 1.]

# Lever'e
def getaLevere(k, A):
    if k == 0:
        return a[0]
    alyona = [0., 0.]
    for i in range(0, k):
        me = mul(a[i], trace(powMx(A, k-i)))
        alyona = plus(alyona, me)
    return mul(-1./k, alyona)

#
# #
# #	OBSERVED FORM
# #
# qj = (-0.2, 0.2)
# # -1 and +1
# m1 = (-1., -1.)
# p1 = (1., 1.)
# # 0
# z = (0, 0)
