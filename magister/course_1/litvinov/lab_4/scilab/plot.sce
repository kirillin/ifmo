//plot(W.time, W.values(:,1), 'k.');
plot(W.time, W.values(:,2), 'b');
plot(W.time, W.values(:,3), 'r--');
plot(W.time, W.values(:,4), 'g--');

xgrid(3);
xlabel("$\LARGE k$");
//ylabel("$\LARGE h$");
a = gca()
a.font_size = 4;
a.x_label.font_size = 5;
a.y_label.font_size = 5;
a.children.children.thickness = 3;
a.data_bounds = [0,-3;2.6,7]
//a.title.text = "$\LARGE g(k)$";
a.title.font_size = 5;
legend("y(k)", "e(k)", "g(k)", 4)
//legend("y(kT)", "y(t)", 4)

