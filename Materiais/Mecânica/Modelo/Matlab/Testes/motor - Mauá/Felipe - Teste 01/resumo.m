%%% Aula experimental 29 de maio de 2013

tempo = linspace(0,max(size(vel))*10e-3,max(size(vel)));
vel = [tempo1 vel];
pos = [tempo1 pos];
input = [tempo1 input];




%% Malha de velocidade

%%% y(t)= A*(1 - exp(-at))

%%% valor final =  3.044 (positivo)
%%% valor final = -3.3393 (negativo)
%%% Km Ktac = 0.7979

Ktac = 3.3393/13.09;
Km = 0.7979/0.2551;
Kenc = 20/(2*pi);
%%% Ktac = 0.2551

%%% em uma constante de tempo 1.9242 neste ponto t=43 *0.01 = 1

taum= 0.43;

%% Controle de posição

Kp=1;



