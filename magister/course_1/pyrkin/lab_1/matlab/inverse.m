  function [q1,q2,q3,q4,q5,q6]  = inverse(H)
    l = 10;

    a = [0 l 0 0 0 0];
    al = [pi/2 0 -pi/2 pi/2 -pi/2 0];
    d = [l 0 0 2*l 0 2*l];
    q1= [0];
    q2= [0];
    q3= [0];
    q4= [0];
    q5= [0];
    q6= [0];
    function R03 = fwd(t1,t2,t3)
        angle = pi / 2;
        tetta = [t1 t2+pi/2 t3-pi/2];
        di =    [l 0 0 2*l 0 2*l];
        ai =    [0 l 0 0 0 0];
        alpha = [angle 0 -angle angle -angle 0];

        H = [
            1 0 0 0;
            0 1 0 0;
            0 0 1 0;
            0 0 0 1;
        ];

        for i = 1:3
            c_t = cos(tetta(i));
            s_t = sin(tetta(i));
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
        R03 = H(1:3, 1:3);
    end

    
    R06 = H(1:3, 1:3);
    o06 = H(1:3, 4);
    oc = o06 - d(6)*R06*[0; 0; 1];
    xc = oc(1);
    yc = oc(2);
    zc = oc(3);
    % q1 - theta 1
    if ((xc ~= 0) && (yc ~= 0))
        q1(1) = atan2(yc, xc);
        q1(2) = pi + atan2(yc, xc);
    end
    % q3 - theta 3
    s = zc - d(1);
    r = sqrt(xc^2 + yc^2);
    D = (s^2 + r^2 - a(2)^2 - 4 * a(2)^2) / (4*a(2)^2);
    q3(1) = atan2(-sqrt(1 - D^2), D) + al(3);
    q3(2) = atan2(sqrt(1 - D^2), D) + al(3);
    
%    q2(1) = atan2(s, r) - atan2(2*a(2)*sin(q3(1)), a(2) + 2*a(2)*cos(q3(1)));
%    q2(2) = atan2(s, r) - atan2(2*a(2)*sin(q3(2)), a(2) + 2*a(2)*cos(q3(2)));

    q2(1) = atan2(s, r) - atan2(-2*a(2)*cos(q3(1)), a(2) - 2*a(2)*sin(q3(1)));
    q2(2) = atan2(s, r) - atan2(2*a(2)*cos(q3(2)), a(2) - 2*a(2)*sin(q3(2)));    
    
    c1 = cos(q1(1));
    c2 = cos(q2(1));
    c3 = cos(q3(1));
    s1 = sin(q1(1));
    s2 = sin(q2(1));
    s3 = sin(q3(1));
    R03 = [c1*c2*c3, -c1*s2*s3, s1;
        s1*c2*c3, -s1*s2*s3, -c1;
        s2*s3, c2*c3, 0];
    R03 = fwd(q1(1),q2(1),q3(1));
    R36 = R03' * R06;
    if ((R36(1,3) ~= R36(2,3)) && (R36(1,3) ~= 0))
        q5(1) = atan2(sqrt(1 - R36(3,3)^2), R36(3,3));
        
        q4(1) = atan2(R36(2,3), R36(1,3));
        q6(1) = atan2(-R36(3,2), R36(3,1));
        
        q5(2) = atan2(-sqrt(1 - R36(3,3)^2), R36(3,3));
        q4(2) = atan2(-R36(2,3), -R36(1,3));
        q6(2) = atan2(R36(3,2), -R36(3,1));        
    elseif ((R36(1,3) == 0) && (R36(3,1) == 0) && (R36(1,3) == R36(2,3)) && (R36(3,1) == R36(3,2)))
        if (R36(3,3) > 0)
            q5(3) = 0;
            % any
            q4(3) = atan2(R36(1,1),R36(2,1));
            q5(3) = 0;
        elseif (R36(3,3) < 0)
            q5(4) = pi;
            % any
            q4(3) = atan2(-R36(1,1),-R36(1,2));
            q5(3) = 0;
        end
    end;
    q1 = q1 * 180 / pi;
    q2 = q2 * 180 / pi;
    q3 = q3 * 180 / pi;
    q4 = q4 * 180 / pi;
    q5 = q5 * 180 / pi;
    q6 = q6 * 180 / pi;
end