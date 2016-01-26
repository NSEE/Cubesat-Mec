%% Inicializa motores

%% motor Cube Sat
motorCubsat.v = 12;
motorCubsat.r = 3E3;

%% motor Laboratório de Simulações


% Values at nominal voltage %

%motorLabsim.w0 = 12300;                % [rpm] - No load speed%
%motorLabsim.i0 = 629;                  % [mA] - No load current
%motorLabsim.w1 = 9890;                 % [rpm] - Nominal speed
%motorLabsim.T1 = 36.8;                 % [mNm] - Nominal torque (max. continuous torque)
%motorLabsim.T2 = 432;                  % [mNm] - Stall torque

motorLabsim.V = 12;                     % [V] - Nominal voltage
motorLabsim.w0 = ((12300*2*pi())/60);   % [rad/s] - No load speed
motorLabsim.i0 = (629*(10^-3));         % [A] - No load current
motorLabsim.w1 = ((9890*2*pi())/60);    % [rad/s] - Nominal speed
motorLabsim.T1 = (36.8*(10^-3));        % [Nm] - Nominal torque (max. continuous torque)
motorLabsim.i1 = 4.04;                  % [A] - Nominal current (max. continuous current)
motorLabsim.T2 = (432*(10^-3));         % [Nm] - Stall torque
motorLabsim.i2 = 48.3;                  % [A] - Starting current
motorLabsim.effmax = 79;                % [%] - Max. efficiency

% Characteristics %

motorLabsim.Rrup = 0.248;               % [ohm] - Terminal resistance phase to phase
motorLabsim.Lrup = 0.109;               % [mH] - Terminal inductance phase to phase
motorLabsim.Tconst = 8.95;              % [mNm/A] - Torque constant
motorLabsim.Sconst = 1070;              % [rpm/V] - Speed constant
motorLabsim.STgradient = 29.6;          % [rpm/mNm] - Speed / torque gradient
motorLabsim.Mtc = 3.26;                 % [ms] - Mechanical time constant
motorLabsim.Jmotor = 10.5;              % [gcm^2] - Rotor inertia
motorLabsim.Wmotor = 170;               % [g] - Weight of motor

% Dimensions %

motorLabsim.volante.R1 = 0.10;          % [m] - external radius
motorLabsim.volante.R2 = 0.08;          % [m] - internal radius
motorLabsim.volante.h = 0.08;           % [m] - height

% Mass %

%motorLabsim.volante.dens = 7860;        % [kg/m^3] - Average density of steel
motorLabsim.volante.dens = 2697;        % [kg/m^3] - Average density of aluminum
motorLabsim.volante.volume = (((pi())*(((motorLabsim.volante.R1)^2)-((motorLabsim.volante.R2)^2)))*(motorLabsim.volante.h)); % [m^3] - Volume
motorLabsim.volante.M = (motorLabsim.volante.dens)*(motorLabsim.volante.volume);              % [kg] - total mass


%% motor Multi-Mission Plataform
motorMmp.r = 5E3;
motorMmp.v = 10;

