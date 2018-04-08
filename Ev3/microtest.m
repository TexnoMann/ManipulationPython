theta0=0.7854
theta1=-0.5264
theta2=-2.5599

a0=0.55;
a1=0.15;
a2=0.20;
d0=0.17;
d1=0;
d2=0;
theta1=theta1+pi/2;
p00 = [0;0;0];
p01 = [a0*cos(theta0);    a0*sin(theta0);     d0];
p12 = [a1*cos(theta1);    a1*sin(theta1);     d1];
p23 = [a2*cos(theta2);    a2*sin(theta2);     d2];

H01 = ([cos(theta0),   0,  sin(theta0),a0*cos(theta0);
         sin(theta0),   0,  -cos(theta0),a0*sin(theta0);
            0       ,   1,      0       ,   d0         ;
            0       ,   0,      0       ,   1       ]);
H12 = ([cos(theta1),-sin(theta1),0,a1*cos(theta1);
         sin(theta1),cos(theta1),0,a1*sin(theta1);
            0       ,   0       ,1,   d1       ;
            0       ,   0       ,0,   1       ]);
H23 = ([cos(theta2),-sin(theta2),0,a2*cos(theta2);
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