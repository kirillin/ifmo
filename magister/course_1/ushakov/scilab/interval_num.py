
uF = [[0,   -0.7238,    0.0050],  [1.0000,   -2.8544,    0.0850], [371.0759,  -87.7479,   -4.0333]]
oF = [[0,   -0.2712,    0.0617],  [1.0000,   -1.0790,    0.4150], [371.0759,  -87.7479,   -4.0333]]



F = [[ [uF[0][0], oF[0][0]], [uF[0][1], oF[0][1]], [uF[0][2], oF[0][2]] ],
     [ [uF[1][0], oF[1][0]], [uF[1][1], oF[1][1]], [uF[1][2], oF[1][2]] ],
     [ [uF[2][0], oF[2][0]], [uF[2][1], oF[2][1]], [uF[2][2], oF[2][2]] ]]

n = 3
f0 = [1,1]
f1 = [0.,0.]
for i in range(0, n):
    print(F[i][i])
    f1 = plus(f1, F[i][i])
f1 = mul([-1,-1], f1)

M11 = minus(mul(F[1][1],F[2][2]), mul(F[2][1],F[1][2]))
M22 = minus(mul(F[0][0],F[2][2]), mul(F[2][0],F[0][2]))
f2 = plus(M11, M22)

s1 = mul(mul(F[0][0],F[1][1]),F[2][2])
s2 = mul(mul(F[0][0],F[1][2]),F[2][1])
s3 = mul(mul(F[0][1],F[1][0]),F[2][2])
s4 = mul(mul(F[0][1],F[1][2]),F[2][0])
s5 = mul(mul(F[0][2],F[1][0]),F[2][1])
s6 = mul(mul(F[0][2],F[1][1]),F[2][0])

f3 = minus(plus(plus(minus(minus(s1,s2), s3), s4), s5), s6)

# Lever'e method of coeffs

I = [[[1.,1.],[0.,0.],[0.,0.]],
     [[0.,0.],[1.,1.],[0.,0.]],
     [[0.,0.],[0.,0.],[1.,1.]]]
Z = [[[0.,0.],[0.,0.],[0.,0.]],
     [[0.,0.],[0.,0.],[0.,0.]],
     [[0.,0.],[0.,0.],[0.,0.]]]

H0 = I

def mulmx(A, B):
    R = [[[0.,0.],[0.,0.],[0.,0.]],
         [[0.,0.],[0.,0.],[0.,0.]],
         [[0.,0.],[0.,0.],[0.,0.]]]
    for i in range(0, len(A)):
        for j in range(0, len(A)):
            for r in range(0, len(A)):
                R[i][j] = plus(R[i][j], mul(A[i][r],B[r][j]))
    return R

def mulmxscal(scal, A):
    R = [[[1.,1.],[0.,0.],[0.,0.]],
     [[0.,0.],[1.,1.],[0.,0.]],
     [[0.,0.],[0.,0.],[1.,1.]]]
    for i in range(0, len(A)):
        for j in range(0, len(A)):
            R[i][j] = mul(A[i][j], scal)
    return R

def tr(A, H):
    t = [0., 0.]
    R = mulmx(A, H)
    for i in range(0, len(A)):
        t = plus(t, R[i][i])
    return t


def getH(k, A, ak):
    if k == 0:
        return H0
    Hkm1 = Z
    LOL = Z
    Hkm1 = mulmx(A, getH(k-1, A, geta(k-1, A)))
    LOL = mulmxscal(ak, I)
    for i in range(0, len(A)):
        for j in range(0, len(A)):
            Hkm1[i][j] = plus(Hkm1[i][j], LOL[i][j])
    return Hkm1

def geta(k, A):
    if k == 0:
        return [1., 1.]
    return mul([-1./k, -1./k], tr(A, getH(k-1, A, geta(k-1, A))))


#
#	OBSERVED FORM
#
qj = (-0.2, 0.2)
# -1 and +1
m1 = (-1., -1.)
p1 = (1., 1.)
# 0
z = (0, 0)

a12 = mul(m1, div(mul(), mul()))

A  = [	[],
		[]]