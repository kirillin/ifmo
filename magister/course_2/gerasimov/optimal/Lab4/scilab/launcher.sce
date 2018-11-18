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
C = [1,0];
G = eye(2,2);
W = [2, 1.5; 1.5, 2];
V = 2;
x0 = [1; 0]; // object's state initial values


// some calculations
P = riccati(A, C'*inv(V)*C, G*W*G', 'c');
L = P * C' * inv(V);
R = chol(W);


// text output
printf("Оптимальный наблюдатель:\n");
disp(P, "P =");
disp(L, "L =");
disp(R, "R =");
disp(spec(A-L*C),"Eigs of A-LC:")


// import and model appropriate scheme
path = get_absolute_file_path('launcher.sce');
scheme_name = path + 'modeling_scheme.zcos';
importXcosDiagram(scheme_name);
xcos_simulate(scs_m, 4);


//plotting graphs
time = errors.time;

subplot(3,1,1);
beauty_plot(time, errors.values(:,1), 1, 1, 1);
//beauty_axes("$t\text{, с}$", "$e_\text{н1}$");

subplot(3,1,2);
beauty_plot(time, errors.values(:,2), 1, 1, 1);
//beauty_axes("$t\text{, с}$", "$e_\text{н2}$");

subplot(3,2,5);
beauty_plot(time, perf_index.values, 1, 1, 1);
//beauty_axes("$t\text{, с}$", "$J$");

subplot(3,2,6);
beauty_plot(time, perf_index.values, 1, 1, 1);
//beauty_axes("$t\text{, с}$", "$J$");



//// change L
//L = 2*L;
//
//
//// text output
//printf("\nНаблюдатель с другой L:\n");
//disp(P, "P =");
//disp(L, "L =");
//disp(R, "R =");
//disp(spec(A - L*C),"Eigs of A-LC:")
//
//
//// import and model appropriate scheme again
//path = get_absolute_file_path('launcher.sce');
//scheme_name = path + 'modeling_scheme.zcos';
//importXcosDiagram(scheme_name);
//xcos_simulate(scs_m, 4);
//
//
////plotting graphs again
//time = errors.time;
//st = 8;
//th = 1;
//
//subplot(3,1,1);
//beauty_plot(time, errors.values(:,1), 1, th, st);
//beauty_axes("$t\text{, с}$", "$e_\text{н1}$");
//beauty_legend(["Оптим. L", "Неоптим. L"], 1);
//
//subplot(3,1,2);
//beauty_plot(time, errors.values(:,2), 1, th, st);
//beauty_axes("$t\text{, с}$", "$e_\text{н2}$");
//beauty_legend(["Оптим. L", "Неоптим. L"], 1);
//
//subplot(3,2,5);
//beauty_plot(time, perf_index.values, 1, th, st);
//beauty_axes("$t\text{, с}$", "$J$");
//beauty_legend(["Оптим. L", "Неоптим. L"], 1);
//
//subplot(3,2,6);
//beauty_plot(time, perf_index.values, 1, th, st);
//beauty_axes("$t\text{, с}$", "$J$");
//beauty_legend(["Оптим. L", "Неоптим. L"], 1);



//// change W
//W = 2*W;
//R = chol(W);
//
//// text output
//printf("\nСитуация при другой W:\n");
//disp(P, "P =");
//disp(L, "L =");
//disp(R, "R =");
//disp(spec(A-L*C),"Eigs of A-LC:")
//
//
//// import and model appropriate scheme again
//path = get_absolute_file_path('launcher.sce');
//scheme_name = path + 'modeling_scheme.zcos';
//importXcosDiagram(scheme_name);
//xcos_simulate(scs_m, 4);
//
//
////plotting graphs again
//time = errors.time;
//st = 8;
//th = 1;
//
//subplot(3,1,1);
//beauty_plot(time, errors.values(:,1), 1, th, st);
//beauty_axes("$t\text{, с}$", "$e_\text{н1}$");
//beauty_legend(["Номин. W", "Неномин. W"], 1);
//
//subplot(3,1,2);
//beauty_plot(time, errors.values(:,2), 1, th, st);
//beauty_axes("$t\text{, с}$", "$e_\text{н2}$");
//beauty_legend(["Номин. W", "Неномин. W"], 1);
//
//subplot(3,2,5);
//beauty_plot(time, perf_index.values, 1, th, st);
//beauty_axes("$t\text{, с}$", "$J$");
//beauty_legend(["Номин. W", "Неномин. W"], 1);
//
//subplot(3,2,6);
//beauty_plot(time, perf_index.values, 1, th, st);
//beauty_axes("$t\text{, с}$", "$J$");
//beauty_legend(["Номин. W", "Неномин. W"], 1);




// change V
V = 2*V;

// text output
printf("\nНаблюдатель с другой L:\n");
disp(P, "P =");
disp(L, "L =");
disp(R, "R =");
disp(spec(A-L*C),"Eigs of A-LC:")


// import and model appropriate scheme again
path = get_absolute_file_path('launcher.sce');
scheme_name = path + 'modeling_scheme.zcos';
importXcosDiagram(scheme_name);
xcos_simulate(scs_m, 4);


//plotting graphs again
time = errors.time;
st = 8;
th = 1;

subplot(3,1,1);
beauty_plot(time, errors.values(:,1), 1, th, st);
beauty_axes("$t\text{, с}$", "$e_\text{н1}$");
beauty_legend(["Номин. V", "Неномин. V"], 1);

subplot(3,1,2);
beauty_plot(time, errors.values(:,2), 1, th, st);
beauty_axes("$t\text{, с}$", "$e_\text{н2}$");
beauty_legend(["Номин. V", "Неномин. V"], 1);

subplot(3,2,5);
beauty_plot(time, perf_index.values, 1, th, st);
beauty_axes("$t\text{, с}$", "$J$");
beauty_legend(["Номин. V", "Неномин. V"], 1);

subplot(3,2,6);
beauty_plot(time, perf_index.values, 1, th, st);
beauty_axes("$t\text{, с}$", "$J$");
beauty_legend(["Номин. V", "Неномин. V"], 1);
