plot(W.time, W.values(:, 4), "k--");
plot(W.time, W.values(:, 1), "r");
plot(W.time, W.values(:, 2), "b");
plot(W.time, W.values(:, 3), "g");
//plot(W.time, W.values(:, 1), "b");
//plot(W.time, W.values(:, 2), "k--");


xgrid(color(200,200,200),1);
xlabel("$\LARGE t$");
//ylabel("$\LARGE h$");
a = gca()
a.font_size = 4;
a.x_label.font_size = 5;
a.y_label.font_size = 5;
a.children.children.thickness = 2;
a.data_bounds = [0,-1;50,15]
a.title.text = "$\LARGE y(t, \Delta q_1)$";
a.title.font_size = 5
legend("$g(t)$", "$y(t, 0.2)$", "$y(t, 0)$", "$y(t, -0.2)$", 1)
//legend("$y(t)$", "$g(t)$", 1)
//legend("y(kT)", "y(t)", 4)
