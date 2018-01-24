syms th0 th1 th2 a1 a2 a3 a4 f 

H01=sym([cos(th0),0, sin(th0),a2*cos(f)*cos(th0);
         sin(th0),0,-cos(th0),a2*cos(f)*sin(th0);
         0       ,1,    0   ,a1+a2*sin(f);
         0       ,0,    0   ,   1       ]);
     
H12=sym([cos(th1),-sin(th1),0,a3*cos(th1);
         sin(th1),cos(th1),0,a3*sin(th1);
         0       ,   0    ,1,0;
         0       ,   0    ,0,   1       ]);
     
H23=sym([cos(th2),-sin(th2),0,a3*cos(th2);
         sin(th2),cos(th2),0,a3*sin(th2);
         0       ,   0    ,1,0;
         0       ,   0    ,0,   1       ]);
     
H03=H01*H12*H23;

