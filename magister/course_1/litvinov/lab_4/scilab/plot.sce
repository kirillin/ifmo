plot(out.time, out.values);

xgrid(3);
xlabel("$\LARGE k$");
//ylabel("$\LARGE h$");
a = gca()
a.font_size = 4;
a.x_label.font_size = 5;
a.y_label.font_size = 5;
a.children.children.thickness = 3;
//a.data_bounds = [0,-3;2.6,7]
//a.title.text = "$\LARGE g(k)$";
a.title.font_size = 5;
legend("u(t)", "$\theta(t)$", "$\dot \psi(t)$", "$\dot \theta(t)$", 4)
//legend("y(kT)", "y(t)", 4)

