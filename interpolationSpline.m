syms q0 q1 qs0 qs1 qss0 qss1 t0 t1;

matrixSpline = sym([1   ,   0        ,   0        ,     0      ,    0       ,    0      ;
                    1   ,   1*t1     ,   t1.^2    ,     t1.^3  ,    t1.^4   ,    t1.^5;
                    0   ,   1        ,   0        ,     0      ,    0       ,   0       ;
                    0   ,   1        ,   2*t1     , 3*t1.^2    , 4*t1.^3    ,   5*t1.^4;
                    0   ,      0     ,      2     ,     0      ,       0    ,   0       ;
                    0   ,      0     ,      2     ,     6*t1   ,12*t1.^2    ,   20*t1.^3]);
           

x = sym([q0;q1;qs0;qs1;qss0;qss1]);

imSpline= inv(matrixSpline);
a = imSpline*x;



