function [Jstructure,Jmotor,Jflywheel,J,CGflywheel,flywheelmass,wcubesat,L,T] = evaluate(proj,spec)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

% Evaluate

[Jstructure,Jmotor,Jflywheel,J,CGflywheel,flywheelmass] = inertia(proj,spec);

[wcubesat] = angular_velocity(Jstructure,Jmotor,proj,spec);

[L] = angular_momentum(J,wcubesat);

[T] = torque(proj,spec);

end