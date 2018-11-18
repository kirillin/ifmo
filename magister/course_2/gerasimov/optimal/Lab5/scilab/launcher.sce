function beauty_axes(x_text, y_text)
    a = gca();
    a.x_label.text = x_text;
    a.x_label.font_size = 4;
    a.y_label.text = y_text;
    a.y_label.font_size = 4;
endfunction

function beauty_legend(text, place)
    legend(text, place),
    a = gca();
    a.children(1).font_size = 2;
endfunction

function beauty_plot(x, y, kolor, thickness, style)
    plot2d(x, y);
    a = gca();
    a.children(1).children.foreground = kolor;
    a.children(1).children.thickness = thickness;
    a.children(1).children.line_style = style;
endfunction

x0 = 10;
ks = [-0.5, -0.1, -2];	// first element for optimal controller

styles = [7, 1, 2]
for i = 1:length(ks) do
    k = ks(i)
    Z = [-2, k; -2, 2];
    eZ = expm(Z);
    lambda0 = (5 - eZ(1,1) * x0) / eZ(1,2);
    
    path = get_absolute_file_path('launcher.sce');
    scheme_name = path + 'modeling_scheme.zcos';
    importXcosDiagram(scheme_name);
    xcos_simulate(scs_m, 4);
    
    time = _x.time;
    subplot(2,2,1);
    beauty_plot(time, _x.values, 1, 1, styles(i));
    
    subplot(2,2,3);
    beauty_plot(time, _u.values, 1, 1, styles(i));

    subplot(1,2,2);
    beauty_plot(time, J.values, 1, 1, styles(i));
end

subplot(2,2,1);
beauty_axes("$t\text{, с}$", "$x$");
beauty_legend(["$\text{Оптим. регулятор}\,\,k = "+string(ks(1))+"$", 
               "$\text{Неоптимальный}\,\,k = "+string(ks(2))+"$", 
               "$\text{Неоптимальный}\,\,k = "+string(ks(3))+"$"],2);

subplot(2,2,3);
beauty_axes("$t\text{, с}$", "$u$");
beauty_legend(["$\text{Оптим. регулятор}\,\,k = "+string(ks(1))+"$", 
               "$\text{Неоптимальный}\,\,k = "+string(ks(2))+"$", 
               "$\text{Неоптимальный}\,\,k = "+string(ks(3))+"$"],2);

subplot(1,2,2);
beauty_axes("$t\text{, с}$", "$J$");
beauty_legend(["$\text{Оптим. регулятор}\,\,k = "+string(ks(1))+"$", 
               "$\text{Неоптимальный}\,\,k = "+string(ks(2))+"$", 
               "$\text{Неоптимальный}\,\,k = "+string(ks(3))+"$"],2);

