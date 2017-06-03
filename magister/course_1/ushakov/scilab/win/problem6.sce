%
%   problem 6
%
w0 = 3;
A11 = [   0,  -1/2,       1/30;
        1,  -236/120,   1/4;
        0,  0,          0
];
A0 = [  0,  -0.6675, 0.03415;
        1,  -2.6495, 0.3039; 
        0,  0,         0
];

% upper and over A matricies
uA = [  0,	-0.2238      -0.02835;    
        0,  -0.8877,	-0.165;
        0,  0,          0
];
oA = [  0,  0.2288,     0.02835;
        0,  0.8877,     0.165;
        0,  0,          0
];
B = [0; 0; 1];
C = [0, 1, 0];

% disire chr. polynom
a3 = w0^3;
a2 = 2 * w0^2;
a1 = 2 * w0;
a0 = 1;
% first method of standart model -- diag
r = roots([a0, a1, a2, a3]);
Lambda = 0.8*[  real(r(2)), imag(r(2)), 0;
            imag(r(3)), real(r(3)), 0;
            0,          0,          r(1)
];
%Lambda =0.8*[  -0.707 0.707 0;
%            -0.707 -0.707 0;
%            0 0 -0.01
%];
%Lambda = diag([-1.4,-0.7,-3])
H = [1, 0, 1];
% second method of standart model -- coeffs
%Lambda = [  0, 0, -a3;
%            1, 0, -a2;
%            0, 1, -a1
%];
%H = [0, 0, 1];
% first method -- Aram's canonical form
Lambda = 0.79 * [-1 0 0; 0 -0.7 0; 0 0 -1.3];
H = [1,1,1];
% alhorithm of Nelder-Mead
H0=[0,0,1];
[H, Mcond] = fminsearch(@(H) cond(sylvester(-A0, Lambda, -B*H)), H0);
Mcond
det([H; H*Lambda;H*Lambda^2])
M = sylvester(-A0, Lambda, -B * H);
F0 = M * Lambda*M^-1;
K = H * M^-1;
F = A0 - B*K;
Kg = -(C * F^-1  * B)^(-1);
G = B * Kg;

deltaIF = norm(uA) / norm(F0);

uF = F + uA;
oF = F + oA;
chUF = charpoly(uF);
chOF = charpoly(oF);
%norm(uA)
%norm(uA) / norm(A)


plot(w)
