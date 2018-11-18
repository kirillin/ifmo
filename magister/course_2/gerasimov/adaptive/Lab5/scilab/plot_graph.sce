////<first_task>
////
//importXcosDiagram("/home/evgeniy/Рабочий стол/Учеба/Магистратура/Адаптивное и робастное управление/Lab5/scilab/for_output.zcos");
//xcos_simulate(scs_m, 4);
//plot2d(Y.time, [Y.values Y_lin.values]);
//legend("Выход модели ВСВ", "Выход регрессионной модели" ,4)
//a = gca();
//a.x_label.text = "$t\text{, с}$"
//a.x_label.font_size = 4;
//line2 = a.children(2).children(1);
//line2.thickness = 3;
//line2.foreground = 1;
//a.children(1).font_size = 2;
////
////<\first_task>


//<second_task>
//
importXcosDiagram("/home/evgeniy/Рабочий стол/Учеба/Магистратура/Адаптивное и робастное управление/Lab5/scilab/for_state.zcos");
xcos_simulate(scs_m, 4);
for i = 1:2
    subplot(2,1,i)
    plot2d(X.time, [X.values(:,i) X_lin.values(:,i)]);
    legend("Модель ВСВ", "Наблюдатель" ,4)
    a = gca();
    a.x_label.text = "$t\text{, с}$"
    a.x_label.font_size = 4;
    str = "$x_{\small" + string(i)+ "}$"
    a.y_label.text = str;
    a.y_label.font_size = 4;
    line2 = a.children(2).children(1);
    line2.thickness = 3;
    line2.foreground = 1;
    a.children(1).font_size = 2;
end
//
//<\second_task>
