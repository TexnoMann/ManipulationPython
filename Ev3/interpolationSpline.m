syms q0 q1 qs0 qs1 qss0 qss1 t0 t1;
matrixSpline5 = sym([1   ,   1*t0     ,   t0.^2    ,     t0.^3  ,    t0.^4   ,    t0.^5;
                    1   ,   1*t1     ,   t1.^2    ,     t1.^3  ,    t1.^4   ,    t1.^5;
                    1   ,   1        ,   2*t0     , 3*t0.^2    , 4*t0.^3    ,   5*t0.^4;
                    0   ,   1        ,   2*t1     , 3*t1.^2    , 4*t1.^3    ,   5*t1.^4;
                    0   ,      0     ,      2     ,     6*t0   ,12*t0.^2    ,   20*t0.^3;
                    0   ,      0     ,      2     ,     6*t0   ,12*t1.^2    ,   20*t1.^3]);
           

x = sym([q0;q1;qs0;qs1;qss0;qss1]);

imSpline= inv(matrixSpline);
a = imSpline*x;



