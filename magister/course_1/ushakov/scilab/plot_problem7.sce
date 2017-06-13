xgrid(color(200,200,200),1);
a = gca()


xlabel("$\LARGE t, [sec]$");
//ylabel("$\LARGE g$");
a = gca()
a.font_size = 4;
a.x_label.font_size = 5;
a.y_label.font_size = 5;
a.children.children.thickness = 1.5;
a.data_bounds = [0,-1.4;80,1.4]

//a.title.text = "$\LARGE y(t, \Delta q_7)$";
//a.title.text = "$\LARGE y(t, q_j)$";
a.title.font_size = 5
legend("$g(t)$", "$y(t, 0)$", "$y(t, 0.2)$", "$y(t, -0.2)$", 4)
legend("$e_1(t, 0)$", "$e_1(t, 0.2)$", "$e_1(t, -0.2)$", 4)
//legend("$g(t)$", "$y(t, 0.3)$", "$y(t, 0)$", "$y(t, -0.3)$", 1)
//legend("$y(t)$", "$g(t)$", 1)
//legend("y(kT)", "y(t)", 4)
