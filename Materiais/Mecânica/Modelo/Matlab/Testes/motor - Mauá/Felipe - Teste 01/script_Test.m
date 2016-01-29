t = linspace(-20*pi,20*pi,1000);
data = sin(t)./t*100;
csvwrite('Test.dat',data); 
    