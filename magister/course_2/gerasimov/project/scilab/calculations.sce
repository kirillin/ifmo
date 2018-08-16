// ОУ
A = [0, 1; -1, 0];
B = [0; 4];
C = [2; 3];

tp = 2;
tp_filter = 3;

// 1. Анализ ОУ
Lambda =spec(A);    // Устойчивость
U = [B, A*B];       // Управляемость
Q = [C'; C'*A];       // Наблюдаемость


// 2. Синтез стабилизирующего управления
tp0 = 2.9;
omega0 = tp0 / tp;
z1 = 1.41 * omega0;
z0 = omega0^2;
Gamma = [0, -z0; 1, -z1];
H = [0, 1];

M = sylv(-A,Gamma,B*H,'c')
K = - H * M^(-1)

F = A - B * K;

//plot2d(S1.time, S1.values);
//legend("$u$", "$y$" , 4);
//    a = gca();
//    a.font_size = 3;
//    a.x_label.text = "$t\text{, с}$"
//    a.x_label.font_size = 6;
//    a.children(1).font_size = 6;    
//    line = a.children.children
//    line.thickness = 3;
//    line.foreground = 1;
//    line.line_style = 1;
//    line2 = a.children.children(2)
//    line2.thickness = 1.1;
//    line2.foreground = 1;
//    line2.line_style = 1;
//    //a.grid = [30, 30]

// 3. Построение генератора сигнала задания
A_g = 2;
C_0 = 3;
omega_g = 6;

Gamma = [0, 1, 0; -omega_g^2, 0, 0; 0, 0, 0];
H = [1, 0, 1];

//plot2d(FNC.time, FNC.values);
//plot2d(GEN.time, GEN.values, rect=[0,3;-1,5]);
//legend("$\text{Сигнал с построенного генератора}$", "$\text{Проверочная функция g(t) = 2 \sin(6 t) + 3}$"  ,4);
//    a = gca();
//    a.font_size = 3;
//    a.x_label.text = "$t\text{, с}$"
//    a.x_label.font_size = 6;
//    a.children(1).font_size = 5;    
//    line = a.children(2).children;
//    line.thickness = 3;
//    line.foreground = 1;
//    line.line_style = 3;
//    line2 = a.children(3).children;
//    line2.thickness = 1.1;
//    line2.foreground = 1;
//    line2.line_style = 1;
//    //a.grid = [30, 30]


// 4a. Построение параметризованного генератора
// Фильтр, полином Ньютона 3-его порядка:
omega0 = 6.3 / tp_filter;
k2 = 3 * omega0;
k1 = 3 * omega0^2;
k0 = omega0^3;

Gamma0 = [  -k2, 1, 0; 
            -k1, 0, 1; 
            -k0, 0, 0];
H0 = [1,0,0];

th = [k2; k1 - omega_g^2; k0];

//plot2d(G3.time, G3.values);
//legend("$\text{Сигнал с модели генератора}$", "$\text{Сигнал с параметризованной модели генератора}$"  ,4);
//    a = gca();
//    a.font_size = 3;
//    a.x_label.text = "$t\text{, с}$"
//    a.x_label.font_size = 6;
//    a.children(1).font_size = 5;    
//    line = a.children(2).children(1);
//    line.thickness = 3;
//    line.foreground = 1;
//    line.line_style = 1;
//    line2 = a.children(2).children(2);
//    line2.thickness = 1.1;
//    line2.foreground = 1;
//    line2.line_style = 1;
//    //a.grid = [30, 30]

// в новом базисе
G = [   0, 1, 0;
        0, 0, 1;
        -k0, -k1, -k2];
l = [0;0;1];

//S = sylv(-Ad,Gd, Bd * Hd, 'd');
//Kd = Hd * S^(-1);

// АДАПТИВНЫЙ ИДЕНТИФИКАТОР
// выход
//plot2d(G1.time, G1.values);//(:,1) - G1.values(:,2));
//legend("${g}$", "$\hat{g}$",4);
//    a = gca();
//    a.font_size = 3;
//    a.margins = [0.03, 0.03, 0.05, 0.16]
//    a.x_label.text = "$t\text{, с}$"
//    a.x_label.font_size = 6;
//    a.children(1).font_size = 5;    
//    line = a.children(2).children(1);
//    line.thickness = 2;
//    line.foreground = 1;
//    line.line_style = 1;
//    line2 = a.children(2).children(2);
//    line2.thickness = 1.1;
//    line2.foreground = 1;
//    line2.line_style = 1;
//    //a.grid = [30, 30]

// параметрическая ошибка
//plot2d(T1.time, T1.values)
//legend("$\tilde{\theta}_1$", "$\tilde{\theta}_2$", "$\tilde{\theta}_3$",4);
//    a = gca();
//    a.font_size = 3;
//    a.margins = [0.03, 0.03, 0.05, 0.16]
//    a.x_label.text = "$t\text{, с}$"
//    a.x_label.font_size = 6;
//    a.children(1).font_size = 5;    
//    line = a.children(2).children(1);
//    line.thickness = 1;
//    line.foreground = 1;
//    line.line_style = 1;
//    line2 = a.children(2).children(2);
//    line2.thickness = 2;
//    line2.foreground = 1;
//    line2.line_style = 7;
//    line3 = a.children(2).children(3);
//    line3.thickness = 2;
//    line3.foreground = 1;
//    line3.line_style = 1;
//    //a.grid = [30, 30]
//

// AA и регулятор
//plot2d(EPS.time, EPS.values)
//legend("$\varepsilon = g - y$", 4);
//    a = gca();
//    a.font_size = 3;
//    a.margins = [0.03, 0.03, 0.05, 0.16]
//    a.x_label.text = "$t\text{, с}$"
//    a.x_label.font_size = 6;
//    a.children(1).font_size = 5;    
//    line = a.children(2).children(1);
//    line.thickness = 1.1;
//    line.foreground = 1;
//    line.line_style = 1;
//    //a.grid = [30, 30]
//


//plot2d(UU.time, UU.values)
//legend("$u$", 4);
//    a = gca();
//    a.font_size = 3;
//    a.margins = [0.03, 0.03, 0.05, 0.16]
//    a.x_label.text = "$t\text{, с}$"
//    a.x_label.font_size = 6;
//    a.children(1).font_size = 5;    
//    line = a.children(2).children(1);
//    line.thickness = 1.1;
//    line.foreground = 1;
//    line.line_style = 1;
//    //a.grid = [30, 30]

//
plot2d(PSI.time, PSI.values)
legend("$\hat{\psi}_1$", "$\hat{\psi}_2$", "$\hat{\psi}_3$", 4);
    a = gca();
    a.font_size = 3;
    a.margins = [0.03, 0.03, 0.05, 0.16]
    a.x_label.text = "$t\text{, с}$"
    a.x_label.font_size = 6;
    a.children(1).font_size = 5;    
    line = a.children(2).children(1);
    line.thickness = 1;
    line.foreground = 1;
    line.line_style = 1;
    line2 = a.children(2).children(2);
    line2.thickness = 2;
    line2.foreground = 1;
    line2.line_style = 7;
    line3 = a.children(2).children(3);
    line3.thickness = 2;
    line3.foreground = 1;
    line3.line_style = 1;
    //a.grid = [30, 30]
//
//




