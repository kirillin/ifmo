function beauty_axes(x_text, y_text)
    a = gca();
    a.x_label.text = x_text;
    a.x_label.font_size = 4;
    a.y_label.text = y_text;
    a.y_label.font_size = 4;
endfunction

function beauty_legend(text, place)
    legend(text, place),
    a = gca();
    a.children(1).font_size = 2;
endfunction

function beauty_plot(x, y, kolor, thickness, style)
    plot2d(x, y);
    a = gca();
    a.children(1).children.foreground = kolor;
    a.children(1).children.thickness = thickness;
    a.children(1).children.line_style = style;
endfunction



// THE BEGGINING OF LAB ACTIVITY IS HERE!!
A = [0, 1; 1, -1];
b = [2; 1];
Q = [1, 0; 0, 1];
r = 2;
x0 = [1; 0]; // object's state initial values


// some calculations
P = riccati(A, b*inv(r)*b', Q, 'c');
K = inv(r) * b' * P;

//F = A - b * K;
//[M, Lambda] = spec(F);
//R = M' * (Q + r * K' * K) * M;
//t = 15;
//J = (inv(M)*x0)' * ( 
//(expm(Lambda*t)*inv(Lambda)*expm(Lambda*t) 
//- 0.5*inv(Lambda)*(expm(Lambda*t))^2) 
//- (expm(Lambda*0)*inv(Lambda)*expm(Lambda*0) 
//- 0.5*inv(Lambda)*(expm(Lambda*0))^2) 
//) * R * inv(M)*x0
//
// some calculation for 3rd lab
Gamma = [0,1,0;-64,0,0;0,0,0];
h = [1,0,1];
C = [1,0];
Lg=[-0.2528301886792453, 0.5018867924528302, -0.3333333333333333]
Mg=[1, 0, 1;
    0.5056603773584906, -0.0037735849056603774, 0.6666666666666666]


//
//// text output
//printf("Оптимальный регулятор:\n")
//disp(P, "P =")
//disp(K, "K =")
//disp(F, "F =");
//disp(M, "M =");
//disp(Lambda, "Lambda =");
//disp(R, "R =");
//disp(J, "J =");


// import and model appropriate scheme
path = get_absolute_file_path('launcher.sce');
scheme_name = path + 'modeling_scheme.zcos';
importXcosDiagram(scheme_name);
xcos_simulate(scs_m, 4);


//plotting graphs
time = _y.time;

subplot(2,1,1);
beauty_plot(time, _g.values, 1, 1, 7);
beauty_plot(time, _y.values, 1, 1, 1);

subplot(2,2,3);
beauty_plot(time, _u.values, 1, 1, 1);

subplot(2,2,4);
beauty_plot(time, perf_index.values, 1, 1, 1);

x = perf_index.time(451);
y = perf_index.values(451);


// change K
K = K + 0.20 * K;

//// remade calculations
//F = A - b * K;
//[M, Lambda] = spec(F);
//R = M' * (Q + r * K' * K) * M;
//t = 5;
//J = (inv(M)*x0)' * ( (expm(Lambda*t)*inv(Lambda)*expm(Lambda*t) - 0.5*inv(Lambda)*(expm(Lambda*t))^2) - (expm(Lambda*0)*inv(Lambda)*expm(Lambda*0) - 0.5*inv(Lambda)*(expm(Lambda*0))^2) ) * R * inv(M)*x0
//
//
//// text output
//printf("\nНеоптимальный регулятор:\n")
//disp(K, "K =")
//disp(F, "F =");
//disp(M, "M =");
//disp(Lambda, "Lambda =");
//disp(R, "R =");
//disp(J, "J =");
//

// import and model appropriate scheme again
path = get_absolute_file_path('launcher.sce');
scheme_name = path + 'modeling_scheme.zcos';
importXcosDiagram(scheme_name);
xcos_simulate(scs_m, 4);


//plotting graphs again
time = _y.time;

subplot(2,1,1);
beauty_plot(time, _y.values, 1, 1, 2);
beauty_axes("$t\text{, с}$", "");
beauty_legend(["Задающее воздействие", "Оптим. регулятор", "Неоптимальный"], 4);

subplot(2,2,3);
beauty_plot(time, _u.values, 1, 1, 2);
beauty_axes("$t\text{, с}$", "$u$");
beauty_legend(["Оптим. регулятор", "Неоптимальный"], 4);

subplot(2,2,4);
beauty_plot(time, perf_index.values, 1, 1, 2);
beauty_axes("$t\text{, с}$", "$J$");
beauty_legend(["Оптим. регулятор", "Неоптимальный"], 4);

plot(x, y, 'ks');
sx = "$x = " + string(x) + "$";
sy = "$y = " + string(y) + "$";
xstring(x-0.5, y-6, sx)
xstring(x-0.5, y-11, sy)

