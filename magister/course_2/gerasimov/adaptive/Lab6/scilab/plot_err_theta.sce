//subplot(2,1,2);
    plot2d(X.time, [th.values - theta_est.values]);
    legend("$\tilde\theta_1$", "$\tilde\theta_2$","$\tilde\theta_3$","$\tilde\theta_4$"  ,4)
    a = gca();
    a.x_label.text = "$t\text{, с}$"
    a.x_label.font_size = 4;
    str = "$x_{\small" + string(2)+ "}$"
    a.y_label.text = str;
    a.y_label.font_size = 4;
    line2 = a.children(2).children(1);
    line2.thickness = 1;
//    line2.foreground = 1;
//    line2.line_style = 1;

    line3 = a.children(2).children(2);
    line3.thickness = 1;
//    line3.foreground = 1;
//    line3.line_style = 2;

    line4 = a.children(2).children(3);
    line4.thickness = 1;
//    line4.foreground = 1;
//    line4.line_style = 3;

    line5 = a.children(2).children(4);
    line5.thickness = 1;
//    line5.foreground = 1;
//    line5.line_style = 4;


    a.children(1).font_size = 2;
