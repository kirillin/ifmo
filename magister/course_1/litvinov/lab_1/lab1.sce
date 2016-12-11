plot2d(A.time, A.values, 1);
xgrid(2);
a = gca();
poly1= a.children(1).children(1); //store polyline handle into poly1 
poly1.thickness = 2; 
xlabel("$ \LARGE t$");
ylabel("$ \LARGE h(t) $");
