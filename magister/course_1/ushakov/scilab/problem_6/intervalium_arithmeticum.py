# print(mul(3, 4))
# print(mul(3, (4, 5)))
# print(mul((3, 4), -5))
# print(mul((-3, 4), (5, 6)))

# print(plus(3, 4))
# print(plus(3, (3, 4)))
# print(plus((3, 4), 4))
# print(plus((3, 4), (4, 5)))

# print(minus(2, 5))
# print(minus(2, (5, 6)))
# print(minus((5, 6), 5))
# print(minus((5, 6), (-2, 2)))

# print(div(3, 4))
# print(div(3, (4, 5)))
# print(div((3, 4), 4))
# print(div((3, 4), (5, 6)))

def imul(a, b):
    "intervals only"
    ua, oa = float(a[0]), float(a[1])
    ub, ob = b
    v = (ua * ub, ua * ob, oa * ub, oa * ob)
    return min(v), max(v)


def mul(a, b):
    "universal multiply"
    if type(a) in [int, float]:
        if type(b) == int or type(b) == float:
            return a * b
        else:
            return imul((a, a), b)
    else:
        if type(b) == int or type(b) == float:
            return imul(a, (b, b))
        else:
            return imul(a, b)


def plus(a, b):
    if type(a) in [int, float]:
        if type(b) == int or type(b) == float:
            return a + b
        else:
            ub, ob = b
            return ub + a, ob + a
    else:
        if type(b) == int or type(b) == float:
            ua, oa = a
            return ua + b, oa + b
        else:
            ua, oa = a
            ub, ob = b
            v = (ua + ub, ua + ob, oa + ub, oa + ob)
            return min(v), max(v)#ua + ub, oa + ob


def minus(a, b):
    if type(a) == int:
        if type(b) == int or type(b) == float:
            return a - b
        else:
            ua, oa = a, a
            ub, ob = b
    else:
        if type(b) == int or type(b) == float:
            ua, oa = a
            ub, ob = b, b
        else:
            ua, oa = a
            ub, ob = b
    v = (ua - ub, ua - ob, oa - ub, oa - ob)
    return min(v), max(v)


def idiv(a, b):
    "intervals only"
    ua, oa = a
    ub, ob = b
    v = (ua / ub, ua / ob, oa / ub, oa / ob)
    return min(v), max(v)


def div(a, b):
    if type(a) == int or type(b) == float:
        if type(b) == int or type(b) == float:
            return a / b
        else:
            return idiv((a, a), b)
    else:
        if type(b) == int or type(b) == float:
            return idiv(a, (b, b))
        else:
            return idiv(a, b)


def getUpper(A, shit=0):
    try:
        n = len(A)
        m = len(A[0])
        uA = [[0. for j in range(m)] for i in range(n)]
        for i in range(n):
            for j in range(m):
                if type(A[i][j]) in [int, float]:
                    uA[i][j] = A[i][j]
                else:
                    uA[i][j] = A[i][j][shit]
        return uA
    except TypeError:
        n = len(A)
        uA = [0. for j in range(n)]
        for i in range(n):
            if type(A[i]) in [int, float]:
                uA[i] = A[i]
            else:
                uA[i] = A[i][shit]
        return uA


def getOver(A):
    return getUpper(A, shit=1)


def makeInterval(uA, oA):
    """ only square matrices"""
    n = len(uA)
    A = [[[0,0] for j in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            A[i][j][0] = uA[i, j]
            A[i][j][1] = oA[i, j]
    return A


if __name__ == '__main__':
    q = [-3, 9]

    x = div(q, q)
    print(x)