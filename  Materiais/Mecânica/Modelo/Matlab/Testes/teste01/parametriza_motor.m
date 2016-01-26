Ra  = 34.2;                % [ohm] - resistencia da bobina
La  = (1.19*(10^-3));      % [H] - indutancia da bobina
B   = (5*(10^-3));                   % cnt atrito
J   = ((0.543));                   % inercia
alpha = .1;                 % cnt de 

k1 = -(((Ra)/(La))+((B)/(J)));
k2 = -((((Ra)*(B))+((alpha)^2))/((J)*(La)));
k3 = ((alpha)/((J)*(La)));
k4 = -((1)/(J));
k5 = -((Ra)/((J)*(La)));

w2 = 0;
w1 = 0;
w = 0;