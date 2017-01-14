T = 0.5;
k1 = 1;
k2 = 0.5;
T2 = 0.95

g0 = 4;
f0 = 1.5;
f1 = 4.5;

A = [0, 1; 0, -1.0526]
B = [0; 0.5263]
C = [1, 0];
Bf = [0; -1]

Cd = C;
Ad = expm(A*T);
Bd = 0;
for i=1:100
    Bd = Bd + (A^(i-1) * T^i) / prod(1:i) * B;
end
Bd
Bfd = 0;
for i=1:100
    Bfd = Bfd + (A^(i-1) * T^i) / prod(1:i) * Bf;
end
Bfd

Ud = [Bd, Ad*Bd];
Qd = [Cd; Cd*Ad];

A1 = [
    1,  -C(1),  -C(2); 
    0,  Ad(1,1), Ad(1,2);
    0,  Ad(2,1), Ad(2,2)
];

B1 = [
    0; 
    Bd(1); 
    Bd(2)
];

H = [1,0,0];
G = [
    0,1,0;
    0,0,1;
    0,0,0
];

S = sylv(-A1,G, B1 * H, 'c');
Kd = -H * S^(-1);

//Kf = Bd^(-1) * (Bfd * [1, 0]);

Ud = [Bd, Ad*Bd];
Qd = [C; C*Ad];

Gd = [0,1;0,0];
Hd = [1, 0]
S = sylv(-Ad,Gd, Bd * Hd, 'd');
Kdg = -Hd * S^(-1);

kf = Bfd(1) / Bd(1);
