T = 0.5;
k1 = 1;
k2 = 0.5;
T2 = 0.95


A = [0, 1; 0, -1.0526]
B = [0; 0.5263]
C = [1,0];

Cd = C;
Ad = expm(A*T);
Bd = [0; 0];
for i=1:10
    Bd = Bd + (A^(i-1) * T^i) / prod(1:i) * B;
end

Ud = [Bd, Ad*Bd];
Qd = [C; C*Ad];
// DISCR MODEL
Gd = [0,1;0,0];
Hd = [1, 0]
M = sylv(-Ad, Gd, -Bd * Hd, 'd');
Kd = -Hd * M^(-1);
    Fd1 = Ad - Bd * Kd;

Gz = [  
    0,1;
    0,0
];
Hz = [1, 0]

Mz = sylv(-Ad', Gz, Cd' * Hz, 'd');
L = -Hz * Mz^(-1);
    Fd = Ad - L' * Cd;
    
   
