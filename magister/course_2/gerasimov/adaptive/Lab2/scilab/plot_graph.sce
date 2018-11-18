// model properteis
theta = 2;  // used for draw graphics
lambda = 2;

// control parameters
gamm = 120;
sigm = 0.001;

// ploting parameters
switch_disturbance = 1;
line_style = 1;
thickness = 2;
kolor = 1;

// ploting...
path = get_absolute_file_path("plot_graph.sce");
//importXcosDiagram(path + "adapt_disturbance.zcos");
//importXcosDiagram(path + "adapt_disturbance_solve_1.zcos");
importXcosDiagram(path + "adapt_disturbance_solve_2.zcos");
xcos_simulate(scs_m, 4);


//----// X ans X_m
    subplot(2, 1, 1);
    plot2d(X.time, [Xm.values X.values], [1, kolor]);
        legend("$x_m$", "$x$", 4);
        a = gca();
        a.margins = [0.05, 0.03, 0.15, 0.1];
        a.x_label.text = "$t\text{, с}$"
        a.x_label.font_size = 4;
        a.children(2).children(2).thickness = 2;
        a.children(2).children(2).line_style = 7;
        a.children(2).children(1).thickness = thickness;
        a.children(2).children(1).line_style = line_style;
//        a.title.text = "$\gamma = " + string(gamm) + "$";
        a.title.text = "$\gamma = " + string(gamm) + "; \sigma = " + string(sigm) + "$"; 
        a.title.font_size = 5;

//----// epsilon
//    plot2d(X.time, Xm.values - X.values, color(255, 0, 0));
//        legend("$x_m$", "$x$","$\varepsilon$", 4);
//        a.children(2).children.thickness = 1;
//        a.children(2).children.line_style = 2;
      a.children(1).font_size = 5;

//----// U
    subplot(2, 2, 3);
    plot2d(X.time, U.values);
        a = gca();
        a.grid = [30, 30]
        a.y_label.text = "$u$"
        a.y_label.font_size = 5;
        a.x_label.text = "$t\text{, с}$"
        a.x_label.font_size = 4;
        a.children(1).children.thickness = thickness;
        a.children(1).children.line_style = line_style;
        a.children(1).children.foreground = kolor;
        a.margins = [0.1, 0.07, 0.08, 0.2];

//----// \tilde\theta
    subplot(2, 2, 4);
    plot2d(X.time, theta - theta_est.values);
        a = gca();
        a.grid = [30, 30]
        a.y_label.text = "$\tilde\theta$"
        a.y_label.font_size = 5;
        a.x_label.text = "$t\text{, с}$"
        a.x_label.font_size = 4;
        a.children(1).children.thickness = thickness;
        a.children(1).children.line_style = line_style;
        a.children(1).children.foreground = kolor;
        a.margins = [0.1, 0.06, 0.08, 0.2];
