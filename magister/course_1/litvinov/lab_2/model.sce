T = 0.2;
A = [0, 1; 0, 0];
B = [0; 1];
C = [1, 0];
Ad = expm(A*T);
Bd = [0; 0];
for i=1:10
    Bd = Bd + (A^(i-1) * T^i) / prod(1:i) * B;
end

z1 = [0.9, -0.9, 0, imult(0.1), complex(-0.2, 0.8), complex(0.8,0.2)];
z2 = [1, -1, 0.2, imult(-0.1), complex(-0.2, -0.8), complex(0.8,-0.2)];
a1 = [];
a0 = [];
k2 = [];
k1 = [];

Fb = [
    1/5, 1/50;
    -1/5, 1/50
];

for i=1:6
    
    Z = [
        z1(i), 1;
        z2(i), 1
    ]
    Z2 = [
        -z1(i)^2;
        -z2(i)^2
    ]
    a = Z^-1 * Z2;    
    a1(i) = a(1);
    a0(i) = a(2);
    
    Fb2 = [
        a(1) + 2; 
        a(2) - 1
    ];
    
    k = Fb^-1 * Fb2;
    k2(i) = k(1);
    k1(i) = k(2);
end

init = 3;
i = 6;
K2 = k2(i);
K1 = k1(i);
