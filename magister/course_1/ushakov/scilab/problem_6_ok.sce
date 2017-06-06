// Aram solve
A0 = [  [ 0.         -0.749         0.064]
        [ 1.         -0.224         0]
        [ 0.          0.            -1.]]
udA = [ [ 0.         -0.412         -0.047]
        [ 0.         -0.124         -0]
        [ 0.          0.            0.]]
odA = [ [ 0.          0.412         0.047]
        [ 0.          0.124         0]
        [ 0.          0.            0.]]
B = [ [0],
       [0],
       [1]]
C =     [0, 1, 0]


// init values
Lambda0 = [-1, -0.7, -1.3, 5];
H0 = [1, 1, 1];

function [positiv]=isPolynomPositiv(F0, uF, oF)
   positiv = 1
   // init array for coeffs
   a = [[1,1];[2,2];[3,3];[4,4]];
   // here is computing coefficients of polynoms 
   for i = 1:4 do
       if a(i,:) <= 0 then
           positiv = 0
           break;
       else
           disp('positive polynom was found!');
       end
   end
endfunction

function [condM]=condMfromLambda(L)
    Lambda = [  [L(1),  0,    0];
                [0,     L(2), 0];
                [0,     0,    L(3)]] * L(4);
        
    function [cM]=condMfromH(H0)
        H = [H0(1), H0(2), H0(3)]
        M = sylv(-A0, Lambda, -B * H, 'c');
        cM = cond(M);
    endfunction
        
    [H, condM] = fminsearch(condMfromH, H0);
    disp(condM)
    M = sylv(-A0, Lambda, -B * H, 'c');
    F0 = M * Lambda * M**(-1);
    uF = F0 + udA;
    oF = F0 + odA;
    if isPolynomPositiv(F0, uF, oF) == 1 then
        disp(Lambda);
        disp(H);
        disp(M);
        disp('************');
    end
endfunction


[Lambda, condM] = fminsearch(condMfromLambda, Lambda0)



