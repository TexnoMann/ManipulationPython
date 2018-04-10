M= dlmread('/media/files/Man/interpolTest.data');
MSpeed= dlmread('/media/files/Man/interpolTestSpeed.data');
Time= 0: 0.050 : 4.05;
J3=M(:,3);
J3Speed= MSpeed(:,3);
figure()
plot(Time,J3);
p=figure()
plot(Time,J3Speed);


