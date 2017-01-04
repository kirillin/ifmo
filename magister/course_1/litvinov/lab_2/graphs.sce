//plot(Q.time, Q.values(:,1), "r")
//plot(Q.time, Q.values(:,2), "k--")
plot(Q.values(:,2), Q.values(:,1), "b")
xgrid(3);

g = gca();
//g.x_label.text = '$\LARGE t, [sec]$'
//g.y_label.text = '$\LARGE h(t)$'
g.x_label.text = '$\LARGE y(t))$'
g.y_label.text = '$\LARGE \dot y(t)$'
g.children.children(1).thickness = 2
//g.children.children(2).thickness = 2
