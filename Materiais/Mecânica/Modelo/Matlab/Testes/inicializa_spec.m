%% Inicializa especificacoes

%% Specification Cube Sat
specCubsat.V = 12;
specCubsat.r = 3E3;

%% Specification Laboratório de Simulações
specLabsim.r = 5E3;
specLabsim.v = 10;

%% Specification Multi-Mission Plataform
specMmp.L = 12;               % [N.m.s] - The angular momentum of the wheel at maximum operational speed (nominal) should be at least 12 Nms with a tolerance of 1%
specMmp.theta = 0.1;          % [deg] - The direction of rotation axis of the wheel shall be perpendicular to the mounting surface with a tolerance lower than or equal to 0.1 deg.
specMmp.imbst = 1.1;          % [g.cm] - Residual static imbalance of the rotating parts shall be lower than 1.1 g.cm, and residual dynamic imbalance shall be lower than 10 g.cm2.
specMmp.imbdy = 10;           % [g.cm^2]
specMmp.Tmax = 0.075;         % [N.m] - maximum motor torque
specMmp.Tlmax = 0.025;        % [N.m] - maximum loss torque (friction torque)

% Dimensions %
% specMmp.diameter = 250;     % [mm] - diametro maximo %
% specMmp.height = 90;        % [mm] - altura maxima %
specMmp.diameter = 0.25;      % [m] - maximum diameter
specMmp.height = 0.09;        % [mm] - maximum height

% Mass %

specMmp.mass = 5;           % [kg] - total mass

