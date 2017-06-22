Dmax = 10
Dmin = 0.1

dD = Dmax - Dmin

l = (dD / 2)^2
m = 2 * l/3 * sqrt(l / 3)

d = (0.25 * 4.9^4 -0.5 * l * 4.9^2 - m * 4.9) / 0.01
d = 0.001
x0 = 10;
c = 10;
function e=E(x, l, m)
    e = (0.25 * (x-x0)^4 - 0.5 * l * (x-x0)^2 - m * (x-x0))*d + c
endfunction


l = 5^2*0.25;
m = 0;
ee1 = zeros(1,n)
for i = 1:n
    ee1(i) = E(i)
end


l = 9.9^2*0.25;
m = 0;
ee2 = zeros(1,n)
for i = 1:n
    ee2(i) = E(i)
end


l = 9.9^2*0.25;
m = 2*l/3 * sqrt(l/3);
ee3 = zeros(1,n)
for i = 1:n
    ee3(i) = E(i)
end

n =  20
t = [-10,10]

K = 1 / (1-l);
f = K * m/2;

//f =-2*sqrt(3) / 9 * (K-1) * sqrt((K-1)/K)
function e=u(z)
    e =  z^3 + ((K-1)/K)*z + f/K;
endfunction

ee4 = zeros(0,n)
for i = 1:n
    ee4(i) = u(i)
end

//plot(t, ee4, 'r')
//plot([0,30], [0,0], 'k')


function e=uu(z_s)
    e = z_s + 0.0425 *((-0.99 - z_s)^3 -(-0.99 - z_s));
endfunction

ee5 = zeros(0,n)
for i = -n:n
    ee5(i) = uu(i)
end

plot(t, ee5, 'r')
