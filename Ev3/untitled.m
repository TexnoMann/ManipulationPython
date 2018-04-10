
syms theta0 theta1 theta2 a0 a1 a2 a3 d0 d1 d2 alpha0 alpha1 alpha2 f
syms qs0 qs1 qs2

theta1=theta1+pi/2;
p00 = [0;0;0];
p01 = [a0*cos(theta0);    a0*sin(theta0);     d0];
p12 = [a1*cos(theta1);    a1*sin(theta1);     d1];
p23 = [a2*cos(theta2);    a2*sin(theta2);     d2];

H01 = sym([cos(theta0),   0,  sin(theta0),a0*cos(theta0);
         sin(theta0),   0,  -cos(theta0),a0*sin(theta0);
            0       ,   1,      0       ,   d0         ;
            0       ,   0,      0       ,   1       ]);
H12 = sym([cos(theta1),-sin(theta1),0,a1*cos(theta1);
         sin(theta1),cos(theta1),0,a1*sin(theta1);
            0       ,   0       ,1,   d1       ;
            0       ,   0       ,0,   1       ]);
H23 = sym([cos(theta2),-sin(theta2),0,a2*cos(theta2);
         sin(theta2),cos(theta2),0,a2*sin(theta2);
             0      ,     0     ,1,       d2    ;
             0      ,     0     ,0,       1     ]); 
H03 = H01*H12*H23;

R00 = eye();
z00 = R00*[0;0;1];
R01 = [cos(theta0), -sin(theta0), 0;
      sin(theta0), cos(theta0),0  ;
      0,            0,          1];
  e1=[1,0,0;
      0,0,-1;
      0,1,0];
R01 = R01*e1;
z01 = R01*[0;0;1];

R12=[cos(theta1),-sin(theta1),    0;
     sin(theta1),cos(theta1),     0;
        0           ,           0    ,      1];
R02 = R01*R12;
z02 = R02*[0;0;1];


R23 = [cos(theta2),-sin(theta2),  0;
     sin(theta2),cos(theta2),   0;
         0      ,   0    ,   1];
R03 = R02*R23;
z03 = R03*[0;0;1];

p02 = p01 + R01*p12;
p03 = p02 + R02*p23;
p0N = p03;

J=[cross(z00,(p0N-p00)),    cross(z01,(p0N-p01)),   cross(z02,(p0N-p02));
        z00             ,           z01         ,           z02         ];
dJdt=diff(J);
S=J*[qs0;qs1;qs2];

    
    