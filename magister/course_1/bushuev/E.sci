x0 = 10;
c = 10;
d=1/1000;
function e=E(x, l, m)
    e = (0.25 * (x-x0)^4 - 0.5 * l * (x-x0)^2 - m * (x-x0))*d + c
endfunction


n = 20
t = [1:1:n]

l = (7-3)^2*0.25;
m = 0;
ee1 = zeros(1,n)
for i = 1:n
    ee1(i) = E(i)
end


l = (9.9-0.1)^2*0.25;
m = 0;
ee2 = zeros(1,n)
for i = 1:n
    ee2(i) = E(i)
end


l = (9.9-0.1)^2*0.25;
m = 2*l/3 * sqrt(l/3);
ee3 = zeros(1,n)
for i = 1:n
    ee3(i) = E(i)
end

K = 1 / (1-l);
f = K * m;

f = -2*sqrt(3) / 9 * (K-1) * sqrt((K-1)/K)
function e=u(z)
    e =  -z^3 + ((K-1)/K)*z + f/K;
endfunction

ee4 = zeros(0,n)
for i = 1:n
    ee4(i) = u(i)
end

plot(t, ee4, 'r')
plot([0,10], [0,0], 'k')

xgrid(color(200,200,200),1);

//ylabel("$\LARGE h$");
a = gca()
a.font_size = 4;
a.x_label.font_size = 5;
a.y_label.font_size = 5;
a.children.children.thickness = 2;
//a.data_bounds = [0,0;20,20]
//a.title.text = "$\LARGE y(t, \Delta q_7)$";
a.title.text = "$\LARGE E(x)$";
a.title.font_size = 5

