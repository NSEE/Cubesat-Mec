J = 0.01;   % [kg.m^2] - moment of inertia of the rotor
b = 0.1;    % [N.m.s] - motor viscous friction constant
% Ke = 0.01;  % [V/rad/sec] - electromotive force constant
% Kt = 0.01;  % [N.m/A] - motor torque constant
K = 0.01;  
R = 1.0;    % [Ohm] - electric resistance
L = 0.5;    % [H] - electric inductance
s = tf('s');

Jc = 1;
Jri = 0.1;
% 
% run motor_simu;


% J = (5.43*(10^(-8)));   % [kg.m^2] - moment of inertia of the rotor
% b = 0.1;    % [N.m.s] - motor viscous friction constant
% Ke = 0.01;  % [V/rad/sec] - electromotive force constant
% Kt = 0.01;  % [N.m/A] - motor torque constant
% % K = 0.01;  
% R = 1.0;    % [Ohm] - electric resistance
% L = 0.5;    % [H] - electric inductance
% s = tf('s');
% 
% Jc = 1;
% Jri = 0.1;

% run motor_simu;

%%
% P_motor = K/((J*s+b)*(L*s+R)+K^2);
% sisotool('rlocus', P_motor)