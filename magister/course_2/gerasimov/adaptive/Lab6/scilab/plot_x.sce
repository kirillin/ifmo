r = 2000000:2100000
subplot(2,1,1);
    plot2d(X.time(r), [X.values(r,1) X_est.values(r,1)]);
    legend("$x_1$", "$\hat{x_1}$" ,4)
    a = gca();
    a.x_label.text = "$t\text{, с}$"
    a.x_label.font_size = 4;
    str = "$x_{\small" + string(1)+ "}$"
    a.y_label.text = str;
    a.y_label.font_size = 4;
    line2 = a.children(2).children(1);
    line2.thickness = 3;
    line2.foreground = 1;
    a.children(1).font_size = 2;
subplot(2,1,2);
    plot2d(X.time(r), [X.values(r,2) X_est.values(r,2)]);
    legend("$x_2$", "$\hat{x_2}$" ,4)
    a = gca();
    a.x_label.text = "$t\text{, с}$"
    a.x_label.font_size = 4;
    str = "$x_{\small" + string(2)+ "}$"
    a.y_label.text = str;
    a.y_label.font_size = 4;
    line2 = a.children(2).children(1);
    line2.thickness = 3;
    line2.foreground = 1;
    a.children(1).font_size = 2;
