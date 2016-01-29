function [L] = angular_momentum(J,wcubesat)
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here

% Motor Angular Momentum
    [Lmotor] = ((J)*(wcubesat));               % [Nms] - Motor Angular Momentum

% Cubesat Angular Momentum
    [L] = (Lmotor);                     % [Nms] - Cubesat Angular Momentum
    
end