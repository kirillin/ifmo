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
F = A - b * K;
[M, Lambda] = spec(F);
R = M' * (Q + r * K' * K) * M;
t = 5;
J = (inv(M)*x0)' * ( (expm(Lambda*t)*inv(Lambda)*expm(Lambda*t) - 0.5*inv(Lambda)*(expm(Lambda*t))^2) - (expm(Lambda*0)*inv(Lambda)*expm(Lambda*0) - 0.5*inv(Lambda)*(expm(Lambda*0))^2) ) * R * inv(M)*x0


// text output
printf("Оптимальный регулятор:\n")
disp(P, "P =")
disp(K, "K =")
disp(F, "F =");
disp(M, "M =");
disp(Lambda, "Lambda =");
disp(R, "R =");
disp(J, "J =");


// import and model appropriate scheme
path = get_absolute_file_path('launcher.sce');
scheme_name = path + 'modeling_scheme.zcos';
importXcosDiagram(scheme_name);
xcos_simulate(scs_m, 4);


//plotting graphs
time = state.time;

subplot(2,2,1);
beauty_plot(time, state.values(:,1), 1, 1, 1);

subplot(2,2,2);
beauty_plot(time, state.values(:,2), 1, 1, 1);

subplot(2,2,3);
beauty_plot(time, control.values, 1, 1, 1);

subplot(2,2,4);
beauty_plot(time, perf_index.values, 1, 1, 1);


// change K
K = K + 0.20 * K;


// remade calculations
F = A - b * K;
[M, Lambda] = spec(F);
R = M' * (Q + r * K' * K) * M;
t = 5;
J = (inv(M)*x0)' * ( (expm(Lambda*t)*inv(Lambda)*expm(Lambda*t) - 0.5*inv(Lambda)*(expm(Lambda*t))^2) - (expm(Lambda*0)*inv(Lambda)*expm(Lambda*0) - 0.5*inv(Lambda)*(expm(Lambda*0))^2) ) * R * inv(M)*x0


// text output
printf("\nНеоптимальный регулятор:\n")
disp(K, "K =")
disp(F, "F =");
disp(M, "M =");
disp(Lambda, "Lambda =");
disp(R, "R =");
disp(J, "J =");


// import and model appropriate scheme again
path = get_absolute_file_path('launcher.sce');
scheme_name = path + 'modeling_scheme.zcos';
importXcosDiagram(scheme_name);
xcos_simulate(scs_m, 4);


//plotting graphs again
time = state.time;

subplot(2,2,1);
beauty_plot(time, state.values(:,1), 1, 1, 2);
beauty_axes("$t\text{, с}$", "$x_1$");
beauty_legend(["Оптим. регулятор", "Неоптимальный"], 1);

subplot(2,2,2);
beauty_plot(time, state.values(:,2), 1, 1, 2);
beauty_axes("$t\text{, с}$", "$x_2$");
beauty_legend(["Оптим. регулятор", "Неоптимальный"], 1);

subplot(2,2,3);
beauty_plot(time, control.values, 1, 1, 2);
beauty_axes("$t\text{, с}$", "$u$");
beauty_legend(["Оптим. регулятор", "Неоптимальный"], 4);

subplot(2,2,4);
beauty_plot(time, perf_index.values, 1, 1, 2);
beauty_axes("$t\text{, с}$", "$J$");
beauty_legend(["Оптим. регулятор", "Неоптимальный"], 4);

