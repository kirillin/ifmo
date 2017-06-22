
plot(t, ee1, 'b-.')
plot(t, ee2, 'r--')
plot(t, ee3, 'g')


xgrid(color(200,200,200),1);
xlabel("$\LARGE x$");
//ylabel("$\LARGE h$");
a = gca()
a.font_size = 4;
a.x_label.font_size = 5;
a.y_label.font_size = 5;
a.children.children.thickness = 2;
//a.data_bounds = [0,0;20,20]
//a.title.text = "$\LARGE y(t, \Delta q_7)$";
a.title.text = "$\LARGE E(x)$";
a.title.font_size = 5
legend("$\lambda = 4; \mu = 0$","$\lambda = 24.01; \mu = 0$","$\lambda = 24.01; \mu = 45.28$", 1)




plot(t, ee1, 'b-.')
plot(t, ee2, 'r--')
plot(t, ee3, 'g')


xgrid(color(200,200,200),1);
xlabel("$\LARGE x$");
//ylabel("$\LARGE h$");
a = gca()
a.font_size = 4;
a.x_label.font_size = 5;
a.y_label.font_size = 5;
a.children.children.thickness = 2;
a.data_bounds = [0,9.5;20,11.5]
//a.title.text = "$\LARGE y(t, \Delta q_7)$";
a.title.text = "$\LARGE E(x)$";
a.title.font_size = 5
legend("$\lambda = 4; \mu = 0$","$\lambda = 24.01; \mu = 0$","$\lambda = 24.01; \mu = 45.28$", 1)


