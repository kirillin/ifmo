W = O
//plot([0,50], [1.05,1.05], "g--")
plot(W.time, W.values(:, 1), "k--");
plot(W.time, W.values(:, 2), "b");
plot(W.time, W.values(:, 3), "r");
plot(W.time, W.values(:, 4), "g");
//plot(W.time, W.values(:, 1), "b");
//plot(W.time, W.values(:, 2), "k--");

//plot([0,4], [1.3+0.065, 1.3+0.065], "r--")
//plot([0,4], [1.3-0.065, 1.3-0.065], "r--")
//plot([0,4], [0.7+0.035, 0.7+0.035], "g--")
//plot([0,4], [0.7-0.035, 0.7-0.035], "g--")


xgrid(color(200,200,200),1);
xlabel("$\LARGE t, [sec]$");
//ylabel("$\LARGE h$");
a = gca()
a.font_size = 4;
a.x_label.font_size = 5;
a.y_label.font_size = 5;
a.children.children.thickness = 2;
a.data_bounds = [0,0;30,3]
//a.title.text = "$\LARGE y(t, \Delta q_7)$";
a.title.text = "$\LARGE y(t, q_j)$";
a.title.font_size = 5
legend("$g(t)$", "$y(t, 0)$", "$y(t, 0.2)$", "$y(t, -0.2)$", 1)
//legend("$g(t)$", "$y(t, 0.3)$", "$y(t, 0)$", "$y(t, -0.3)$", 1)
//legend("$y(t)$", "$g(t)$", 1)
//legend("y(kT)", "y(t)", 4)
