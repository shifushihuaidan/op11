syms t;
h=[200 600 600 600];
H=[51000 71400 128000 370000];
R=[6378 6378 6378 6378];
T=[16 24 48 116]*3600;
c=(H-h)/2;
a=(H+h+2*R)/2;
b=sqrt(a.^2-c.^2);
e=c./a;
f=sqrt(1-e.^2*(cos(t)^2));
l=4*a.*int(f,t,0,pi/2);
disp('周长为')
L=double(l)
disp('平均速度为')
v=L./T
disp('最大速度为')
s1=a.*b*pi./T;
vmax=2*s1./(R+h)
disp('最小速度为')
vmin=2*s1./(R+H)


