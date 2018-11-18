clear;

function g=gradJ(point)
    g = []
    x = point(1);
    u = point(2);
    g(1) = 4*x + 2*u + 3;
    g(2) = 2*x + 2*u + 5;
endfunction

deff('z=f(x,u)','z=2*x^2 + u^2 + 2*x*u + 3*x + 5*u -10')
x=-4:1:6;
u=-6:1:3;


//initialization
vis_array = []

xi0 = [5; 2]; vis_array(1,:) = [xi0', f(xi0(1), xi0(2))];
_gamma = 0.01;
H = [4,2;2,2];

// method fast descent
k = 1; prev_point = xi0;
g = gradJ(prev_point)
point = 0
disp('########')
while sum(g) <> 0 do
//while k < 8 do
//    point = prev_point - H^-1 * g;    // Newton-Rosfen
    point = prev_point - _gamma * g;    // Fast descent
    disp(point, _gamma * g, g, prev_point, k,"**************")
    prev_point = point
    g = gradJ(prev_point)
    k = k + 1;
    vis_array(k,:) = [point', f(point(1), point(2))+1]
end
disp(size(vis_array))

// ploting
fplot3d1(x,u,f,theta=-70,alpha=80);
set(gcf(),"color_map",[jetcolormap(32)])

a=gca();
param3d(vis_array(:,1), vis_array(:,2), vis_array(:,3));
h = a.children(1);
h.thickness = 2;
h.foreground = 28;
h.mark_mode = 'on'
h.mark_style = 9;
h.mark_size = 1;
a.title.text = '$\text{При } \gamma = 0.01$';
a.title.font_size = 5;

h.mark_foreground = 28;

//legend("$\text{Метод наискорейшего спуска}$")
legend("$\text{Градиентный поиск методом Ньютона-Рафсона}$")
a.children(1).font_size = 4


//// plot 2d countours of 3d surface
scf()
levels = [-17.25, -16, -10, 0, 20, 50, 100, 250, 300, 350, 570];
contour2d(x,u,f,levels)
a=gca();
plot(vis_array(:,1), vis_array(:,2), 'ro-')
h=a.children(1)
a.children(1).children.foreground = 5
a.children(1).children.thickness = 2
a.x_label.text = '$x$'
a.x_label.font_size = 5
a.y_label.text = '$u$'
a.y_label.font_size = 5
a.title.text = '$\text{При } \gamma = 0.01$';
a.title.font_size = 5;
