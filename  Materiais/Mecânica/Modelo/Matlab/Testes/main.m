%% initialization

clear; clc;

proj;
spec;


x = 0;


% validation
% evaluate
% results

%% Validation
 
% [dim,mass,dyn] = validation(Cubesat,specCubesat);

mass = validation(Cubesat,specCubesat);

%% Evaluate

[Jstructure,Jmotor,Jflywheel,J,CGflywheel,flywheelmass,wcubesat,L,T] = evaluate(Cubesat,specCubesat);

%% Results

res = results(mass,Cubesat,specCubesat);

%%

% % tipo = input('1: Cubesat \n2: Labsim \n3: Multi-Mission Plataform\n');
% % 
% % if tipo == 1
% %     
% %     calc inertia Cubesat
% %     
% %     fprintf('escolha 1 \n');
% %     ret1 = inertia(Cubesat,specCubesat); 
% %     
% % else
% %     if tipo == 2
% %         
% %     calc inertia Labsim
% %         
% %     fprintf('escolha 2 \n');
% %     ret1 = inertia(Labsim,specLabsim);
% %     
% %     else
% %         
% %         calc inertia Multi-Mission Plataform
% %         
% %         fprintf('escolha 3 \n');
% %         ret1 = inertia(Labsim,specLabsim); 
% %         
% %     end
% %     
% % end