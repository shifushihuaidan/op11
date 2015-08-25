a=0:0.001:2*pi;
r=cos(3*a);
x=r.*cos(a);y=r.*sin(a);
figure(2),comet(x,y)