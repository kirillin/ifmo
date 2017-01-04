plot(W.time, W.values);
xgrid(3);
xlabel("$\LARGE t$");
ylabel("$\LARGE h$");
a = gca()
a.font_size = 4;
a.x_label.font_size = 5;
a.y_label.font_size = 5;
a.children.children.thickness = 1;
//a.data_bounds = [0,-100;10,100]
a.title.text = "$\LARGE g(k)$";
a.title.font_size = 5;
legend("y(k)", "e(k)", "g(k)")
