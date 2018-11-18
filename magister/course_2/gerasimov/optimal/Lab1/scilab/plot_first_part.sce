clear;
deff('z=f(x,u)','z= 2*x^2 + u^2 + 2*x*u + 3*x + 5*u - 10');
//deff('z=c(x,u)','z= x+100*u+1');
deff('z=c(x,u)','z= x-2*u^2');

x=-4:1:6;
u=-6:1:3;

fplot3d1(x,u,f,theta=-70,alpha=80);
fplot3d1(x,u,c,theta=-70,alpha=80);

set(gcf(),"color_map",[graycolormap(32)])

zz = f(1,-3.5)+1;   // +1 чтобы было видно точку под любыми углами обзора
param3d1(1,-3.5, list(zz, -9))  // глобальный минимум


// минимум в условиях ограничения
p = poly([5,14,12,32], 'u', 'coeff');
rs = roots(p);

uu = rs(3);
xx = 2 * uu**2;

zz = f(xx,uu)+1;
param3d1(xx, uu, list(zz, -3))

legend("$\text{Глобальный минимум}$", "$\text{Минимум в условиях ограничения c(x,u)}$");
a = gca()
a.children(1).font_size = 4


deff('z=q(x,u)','z= 2*x^2 + u^2 + 2*x*u + 3*x + 5*u - 10 + l*(x-2*u^2)');
