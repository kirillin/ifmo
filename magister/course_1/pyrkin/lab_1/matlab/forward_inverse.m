function H  = forward_inverse(t1, t2, t3, t4, t5, t6)
    %#codegen
    l = 10;
    angle = pi / 2;

    tetta = [t1 t2 t3 t4 t5 t6];
    di =    [l 0 0 2*l 0 2*l];
    ai =    [0 l 0 0 0 0];
    alpha = [angle 0 -angle angle -angle 0];

    H = [
        1 0 0 0;
        0 1 0 0;
        0 0 1 0;
        0 0 0 1;
    ];

    for i = 1:6
        c_t = cos(tetta(i)*pi/180);
        s_t = sin(tetta(i)*pi/180);
        d = di(i);
        a = ai(i);
        c_a = cos(alpha(i));
        s_a = sin(alpha(i));

        Rtz = [
            c_t -s_t 0 0;
            s_t c_t 0 0;
            0 0 1 0;
            0 0 0 1
        ];
        Tz = [
            1 0 0 0;
            0 1 0 0;
            0 0 1 d;
            0 0 0 1
        ];
        Tx = [
            1 0 0 a;
            0 1 0 0;
            0 0 1 0;
            0 0 0 1
        ];
        Rtx = [
            1 0 0 0;
            0 c_a -s_a 0;
            0 s_a c_a 0;
            0 0 0 1
        ];

        A = Rtz * Tz * Tx * Rtx;
        H = H * A;
    end;
end