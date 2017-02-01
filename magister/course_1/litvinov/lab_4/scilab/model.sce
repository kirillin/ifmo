T = 0.5;
k1 = 1;
k2 = 0.5;
T2 = 0.95


A = [0, 1; 0, 1.0526]
B = [0; 0.5263]
C = [1,0];
Cd = C;
Ad = expm(A*T);
Bd = [0; 0];
for i=1:10
    Bd = Bd + (A^(i-1) * T^i) / prod(1:i) * B;
end
Bd

Ud = [Bd, Ad*Bd];
Qd = [C; C*Ad];

Gd = [0,1;0,0];
Hd = [1, 0]

S = sylv(-Ad,Gd, Bd * Hd, 'd');
Kd = Hd * S^(-1);



sl = syslin('d', Ad, Bd, Cd);
[d,num,chi] =ss2tf(sl)

Ak = [0, 1; -1.6926579,2.6926579];
Bk = [0;1]
Uk = [Bk, Ak*Bk];
M = Ud * Uk^-1;
Kk = [- 1.6926579, 2.6926579]
Kd = Kk * M^-1

Fd = Ad - Bd * Kd
