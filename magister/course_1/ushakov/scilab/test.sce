function [f]=rosenbrock(x)
 //x = [x1 x2];
 f = 100.0 *(x(2)-x(1)^2)^2 + (1-x(1))^2;
endfunction

x0 = [-2, 2]
//[f, x8] =optim(rosenbrock, x0);

[x,f] = fminsearch(rosenbrock, x0);




A = [0, -0.6675, 0.0371;1,-2.6495,0.3733;0,0,1]
B = [1,0;1,0;0,1]
C = [0,1,0]
omega_0 = 3
G = diag(spec(tA)) * omega_0
He = [1,1,1]


function [M]= sylvester(H)
    M = sylv(-A, G, B*H, 'c');
endfunction


He0 = [1,0,0]

[x,M] = fminsearch(sylvester, He0);

