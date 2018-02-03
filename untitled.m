syms theta0 theta1 theta2 a0 a1 a2 a3 d0 d1 d2 alpha0 alpha1 alpha2 f 


H01=sym([cos(theta0),0, sin(theta0),a0*cos(theta0);
         sin(theta0),0,-cos(theta0),a0*sin(theta0);
         0       ,1,    0   ,d0;
         0       ,0,    0   ,   1       ]);
     
H12=sym([cos(theta1),-sin(theta1),0,a1*cos(theta1);
         sin(theta1),cos(theta1),0,a1*sin(theta1);
         0       ,   0    ,1,   d1       ;
         0       ,   0    ,0,   1       ]);
     
H23=sym([cos(theta2),-sin(theta2),0,a2*cos(theta2);
         sin(theta2),cos(theta2),0,a2*sin(theta2);
             0      ,   0    ,   1,       d2;
            0       ,   0    ,   0,       1]);
     
H03=H01*H12*H23;


