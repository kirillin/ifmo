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
    a.children(1).font_size = 4;
endfunction

function beauty_plot(x, y, kolor, thickness, style)
    plot2d(x, y);
    a = gca();
    a.children(1).children.foreground = kolor;
    a.children(1).children.thickness = thickness;
    a.children(1).children.line_style = style;
endfunction



// THE BEGGINING OF LAB ACTIVITY IS HERE!!
theta_1 = 1;
theta_2 = 2;
lambda = 2;
k = 10;

// import and model appropriate scheme
path = get_absolute_file_path('launcher.sce');
scheme_name = path + 'modeling_scheme2.zcos';
importXcosDiagram(scheme_name);
xcos_simulate(scs_m, 4);


//plotting graphs
time = control_error.time;

subplot(2,2,1);
beauty_plot(time, control_error.values, 1, 1, 1);
beauty_axes("$t\text{, с}$", "$\varepsilon$");

subplot(2,2,2);
beauty_plot(time, control.values, 1, 1, 1);
beauty_axes("$t\text{, с}$", "$u$");

subplot(2,2,3);
beauty_plot(time, theta_1 - estims.values(:,1), 1, 1, 1);
beauty_axes("$t\text{, с}$", "$\tilde{\theta}_1$");

subplot(2,2,4);
beauty_plot(time, theta_2 - estims.values(:,2), 1, 1, 1);
beauty_axes("$t\text{, с}$", "$\tilde{\theta}_2$");

// for debug:
//scf();
//subplot(1,2,1);
//beauty_plot(time, debug_v.values(:,1), 1, 1, 1);
//beauty_plot(time, debug_v.values(:,2), 2, 1, 1);
//beauty_axes("$t\text{, с}$", "");
//beauty_legend(['$F(s)[x]$','$F(s)[\sin{x}]$'], 1)
//
//subplot(1,2,2);
//beauty_plot(time, debug_v.values(:,1).*(theta_1 - estims.values(:,1))+debug_v.values(:,2).*(theta_2 - estims.values(:,2)), 1, 1, 1);
//beauty_axes("$t\text{, с}$", "");
//beauty_legend(['$\tilde\theta_1 \cdot x + \tilde\theta_2 \cdot \sin{x}$'], 1)

