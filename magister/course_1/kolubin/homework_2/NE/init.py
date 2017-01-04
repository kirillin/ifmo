from numpy import zeros, pi

G = 0


# kinematics and dynamics parameters
class robot:
    N = 2
    # LINKS
    sigma = 1
    nu = [0, 0]
    m = [10, 5]             # mass
    l = [1, 0.5]            # length
    diameter = [0.02, 0.02]
    # centers of mass
    r = [l[0]/2, l[1]/2]
    # DH parameters
    a = [l[0], l[1]]
    alpha = [0, 0]
    d = [0, 0]
    theta = [0, 0]
    # ***
    # vectors for each link
    vec_r = zeros((3, N))
    vec_rc = zeros((3, N))
    # axis of rotation
    z = zeros((3, N+1))
    g = zeros((3, N + 1))
    vec_r[0, :] = l         # vector from i-1 to i joint
    vec_rc[0, :] = r        # vector from i-1 to center of mass of link i
    z[2, :] = 1             # rotation axis [0; 0; 1]
    g[1, :] = G             # vectors of gravitation [0; g; 0] for axis Y0


# from (pi/2, -pi) to (0, pi/2)
#   for 1 sec. with step 0.01
class trajectory:
    # s -- start point
    # e -- end point
    # position, velocity, acceleration for q_1
    #   start q_1
    Q1s = pi / 2
    dotQ1s = 0
    ddotQ1s = 0
    #   end q_1
    Q1e = 0
    dotQ1e = 0
    ddotQ1e = 0
    # position, velocity, acceleration for q_2
    #   start q_2
    Q2s = -pi
    dotQ2s = 0
    ddotQ2s = 0
    #   end q_2
    Q2e = pi / 2
    dotQ2e = 0
    ddotQ2e = 0
    # the time interval
    ts = 0
    te = 1
    step = 0.01
    # ***
    initQ = [
        [Q1s, Q1e],
        [Q2s, Q2e]
    ]
    initDotQ = [
        [dotQ1s, dotQ1e],
        [dotQ2s, dotQ2e]
    ]
    initDDotQ = [
        [ddotQ1s, ddotQ1e],
        [ddotQ2s, ddotQ2e]
    ]
    interval = [ts, te, step]
