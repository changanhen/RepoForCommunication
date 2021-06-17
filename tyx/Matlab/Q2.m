clc;
xdata=[1 2 3 4 5 6 7 8 9 10 11 12];
ydata=[3 8 14 21 26 32 33 35 30 20 11 5];
fun=@(x,xdata)x(1)*sin(x(2)*xdata)+x(3);
x0=[23 0.2 -0.2];
x=lsqcurvefit(fun,x0,xdata,ydata)
times=linspace(xdata(1),xdata(end));
plot(xdata,ydata,'b*',times,fun(x,times),'r-','linewidth',3)
hold on
legend('Daate','Tem')
title('Data and tem')
z=43.0485*sin(0.2302*xdata)-10.7546-ydata;
plot(xdata,z)

 

