plot([0,1], [0.95, 0.95], "b--")
plot([0,1], [1.05, 1.05], "b--")
plot([t_p, t_p], [0, 2], "r--")
plot([0,1], [1.1, 1.1], "r--")

plot([0,1], [1, 1], "s-")
plot(Q.time, Q.values(:,1), "k")
plot(Q.time, Q.values(:,4), "b")
