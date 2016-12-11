  
    angle = pi/2;
    tetta = [0 0 angle 0 pi/4 0];
    di =    [1 0 0 1 0 1];
    ai =    [0 1 0 0 0 0];
    aL = [angle 0 angle -angle angle 0];

    H = [
        1 0 0 0;
        0 1 0 0;
        0 0 1 0;
        0 0 0 1;
    ];

    for i = 1:6
        c_t = cos(tetta(i));
        s_t = sin(tetta(i));
        d = di(i);
        a = ai(i);
        c_a = cos(aL(i));
        s_a = sin(aL(i));

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
        H = H * A
    end

    x = H(1,4); 
    y = H(2,4);
    z = H(3,4);
