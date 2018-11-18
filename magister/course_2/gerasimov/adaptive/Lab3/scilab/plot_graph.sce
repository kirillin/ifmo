////<first_task>
////
//importXcosDiagram("/home/evgeniy/Рабочий стол/Учеба/Магистратура/Адаптивное и робастное управление/Lab3/scilab/ref_model.zcos");
//xcos_simulate(scs_m, 4);
//plot2d(Y.time, Y.values);
//a = gca();
//a.x_label.text = "$t\text{, с}$"
//a.x_label.font_size = 4;
//a.y_label.text = "$y_{\scriptsize M}$"
//a.y_label.font_size = 4;
//final = Y.values(max(size(Y.values)));
//plot2d([0;0.8],[1.05*final;1.05*final])
//plot2d([0;0.8],[0.95*final;0.95*final])
//xgrid();
////
////<\first_task>


////<second_task>
////
//importXcosDiagram("/home/evgeniy/Рабочий стол/Учеба/Магистратура/Адаптивное и робастное управление/Lab3/scilab/no_adapt.zcos");
//xcos_simulate(scs_m, 4);
//subplot(2,2,1);
//plot2d(X.time, [X.values(:,1), Xm.values(:,1)]);
//a = gca();
//a.x_label.text = "$t\text{, с}$"
//a.x_label.font_size = 4;
//legend("$x_1$","$x_{M1}$")
//a.children(1).font_size = 4;
//
//subplot(2,2,2);
//plot2d(X.time, [X.values(:,2), Xm.values(:,2)]);
//a = gca();
//a.x_label.text = "$t\text{, с}$"
//a.x_label.font_size = 4;
//legend("$x_2$", "$x_{M2}$")
//a.children(1).font_size = 4;
//
//subplot(2,1,2);
//plot2d(X.time, Xm.values - X.values);
//a = gca();
//a.x_label.text = "$t\text{, с}$"
//a.x_label.font_size = 4;
//legend("$e_1$", "$e_2$",4)
//a.children(1).font_size = 4;
////
////<\second_task>


//<third_task>
//
importXcosDiagram("/home/evgeniy/Рабочий стол/Учеба/Магистратура/Адаптивное и робастное управление/Lab3/scilab/adapt.zcos");
xcos_simulate(scs_m, 4);
subplot(2,1,1);
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
plot2d(X.time, [X.values(:,2), Xm.values(:,2)], rect=[0, -10, 5, 10]);
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
//
//<\third_task>

