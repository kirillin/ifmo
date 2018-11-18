//kolor = 1;
//importXcosDiagram("/home/evgeniy/Рабочий стол/Учеба/Магистратура/Адаптивное и робастное управление/Lab1/scilab/adapt.zcos");
//xcos_simulate(scs_m, 4);
//subplot(2,1,2);
//plot2d(X.time, [X.values Xm.values], rect=[0,-0.7,15,0.7]);
////plot2d(estim.time, X.values,5)
//legend("$x$", "$x_m$")
//a = gca();
////    a.title.text = "$K=0.9$"
////    a.title.font_size = 3;
//a.x_label.text = "$t\text{, с}$"
//a.x_label.font_size = 4;
////a.y_label.text = "$y$"
////a.y_label.font_size = 4;
////a.children(1).children.thickness = 1;
//a.children(1).font_size = 4;
//
//plot2d([3;3],[-0.7; 0.7],rect=[0,-0.7,15,0.7])
//plot2d([6;6],[-0.7; 0.7],rect=[0,-0.7,15,0.7])
//plot2d([9;9],[-0.7; 0.7],rect=[0,-0.7,15,0.7])
//
//subplot(2,3,3)
//plot2d(U.time, U.values,rect=[0,-4,15,4])
//a = gca();
//a.x_label.text = "$t\text{, с}$"
//a.x_label.font_size = 4;
//a.y_label.text = "$u$"
//a.y_label.font_size = 4;
//
//subplot(2,3,1)
//plot2d(theta.time, theta.values)
//a = gca();
//a.x_label.text = "$t\text{, с}$"
//a.x_label.font_size = 4;
//a.y_label.text = "$\theta$"
//a.y_label.font_size = 4;
//
//subplot(2,3,2)
//plot2d(theta.time, theta.values - estim.values)
//a = gca();
//a.x_label.text = "$t\text{, с}$"
//a.x_label.font_size = 4;
//a.y_label.text = "$\tilde\theta$"
//a.y_label.font_size = 4;

//tms = 0;
tms_e = 0;
for i=1:60
    kolor = i;
    gamm = 5 + (i-1)*5
//    gamm = 250;
    importXcosDiagram("/home/evgeniy/Рабочий стол/Учеба/Магистратура/Адаптивное и робастное управление/Lab1/scilab/adapt_for_gamma_check.zcos");
    xcos_simulate(scs_m, 4);
//    plot2d(estim.time, estim.values);
    plot2d(X.time, Xm.values-X.values);
    tms_e(i) = go_time(X.time, Xm.values-X.values+1);
//    subplot(3,1,3);
//    plot2d(X.time, [X.values Xm.values]);
//    xlabel("$t\text{, с}$");
//    legend("$x$", "$x_m$",4);
//    tms(i)= go_time(estim.time, estim.values)
    printf("%3d -- %2.2f\n", gamm, tms_e(i));
end
