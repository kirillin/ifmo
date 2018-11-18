switch_desturbance = 1;
gamm = 1500;
sigm = 0.01;

path = get_absolute_file_path("plot_graph.sce");
//importXcosDiagram(path + "adapt_desturbance_robust.zcos");
importXcosDiagram(path + "adapt_desturbance_robust_and_adapt.zcos");
xcos_simulate(scs_m, 4);

subplot(2,1,1);
a = gca();

if sigm == 0 then
    if switch_desturbance == 1 then
        a.title.text = "$\gamma = " + string(gamm) + "; \delta = \delta(t)$";
    else
        a.title.text = "$\gamma = " + string(gamm) + "; \delta = 0$";
    end
else
    if switch_desturbance == 1 then
        a.title.text = "$\sigma = " + string(sigm) + "; \gamma = " + string(gamm) + "; \delta = \delta(t)$";
    else
        a.title.text = "$\sigma = " + string(sigm) + "$; \gamma = " + string(gamm) + "; \delta = 0$";
    end
end;

a.title.font_size = 4;

// 1
//subplot(2,2,1);
//plot2d(X.time, [X.values(:,1), Xm.values(:,1)]);
//a = gca();
//a.x_label.text = "$t\text{, с}$"
//a.x_label.font_size = 4;
//legend("$x_1$","$x_{M1}$")
//a.children(1).font_size = 4;
//a.children(2).children(1).thickness = 2;
//a.children(2).children(1).line_style = 1;
//a.children(2).children(1).foreground = 1;
//
//subplot(2,2,2);
//plot2d(X.time, [X.values(:,2), Xm.values(:,2)]);
//a = gca();
//a.x_label.text = "$t\text{, с}$"
//a.x_label.font_size = 4;
//legend("$x_2$", "$x_{M2}$")
//a.children(1).font_size = 4;
//a.children(2).children(1).thickness = 2;
//a.children(2).children(1).line_style = 1;
//a.children(2).children(1).foreground = 1;
//
//subplot(2,1,2);
//plot2d(X.time, Xm.values - X.values);
//a = gca();
//a.x_label.text = "$t\text{, с}$"
//a.x_label.font_size = 4;
//legend("$e_1$", "$e_2$",4)
//a.children(1).font_size = 4;
//a.children(2).children(1).thickness = 2;
//a.children(2).children(1).foreground = 1;


// 2
plot2d(X.time, [X.values(:,1), Xm.values(:,1)]);
a = gca();
a.x_label.text = "$t\text{, с}$"
a.x_label.font_size = 4;
second_line = a.children.children(1);
second_line.line_style = 7;
second_line.thickness = 2;
second_line.foreground = 1;
legend("$x_1$","$x_{M1}$");
a.children(1).font_size = 4;

subplot(2,1,2);
plot2d(X.time, [X.values(:,2), Xm.values(:,2)]);

a = gca();
a.x_label.text = "$t\text{, с}$"
a.x_label.font_size = 4;
second_line = a.children.children(1);
second_line.line_style = 7;
second_line.thickness = 2;
second_line.foreground = 1;
legend("$x_2$","$x_{M2}$");
a.children(1).font_size = 4;

scf();
subplot(2,1,1);
plot2d(X.time, Xm.values - X.values);
a = gca();
a.x_label.text = "$t\text{, с}$"
a.x_label.font_size = 4;
second_line = a.children.children(1);
second_line.thickness = 3;
second_line.foreground = 1;
legend("$e_1$", "$e_2$");
a.children(1).font_size = 4;
xgrid();

subplot(2,1,2);
plot2d(X.time, [-256 + (-1) - estim.values(:,1), -32 + (1) - estim.values(:,2)]);
a = gca();
a.x_label.text = "$t\text{, с}$"
a.x_label.font_size = 4;
second_line = a.children.children(1);
second_line.thickness = 3;
second_line.foreground = 1;
legend("$\tilde\theta_1$", "$\tilde\theta_2$",4);
a.children(1).font_size = 3;
xgrid();


