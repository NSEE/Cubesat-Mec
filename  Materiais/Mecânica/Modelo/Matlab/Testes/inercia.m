function [ ret1 ] = inercia( motorLabsim, specLabsim )
%UNTITLED6 Summary of this function goes here
%   Detailed explanation goes here
    
    ret1.v = specLabsim.v;

    ret1.R1 = motorLabsim.volante.R1;
    ret1.R2 = motorLabsim.volante.R2;
    ret1.h = motorLabsim.volante.h;
    ret1.M = motorLabsim.volante.M;
    
    ret1.Jxx = ((((ret1.M)*(((ret1.R1)^2)+((ret1.R2)^2)))/4)+(((ret1.M)*((ret1.v)^2))/12));
    ret1.Jxy = 0;
    ret1.Jxz = 0;
    
    ret1.Jyx = 0;
    ret1.Jyy = ((((ret1.M)*(((ret1.R1)^2)+((ret1.R2)^2)))/4)+(((ret1.M)*((ret1.v)^2))/12));
    ret1.Jyz = 0;
    
    ret1.Jzx = 0;
    ret1.Jzy = 0;
    ret1.Jzz = (((ret1.M)*(((ret1.R1)^2)+((ret1.R2)^2)))/2);
    
    J = [ret1.Jxx ret1.Jxy ret1.Jxz; ret1.Jyx ret1.Jyy ret1.Jyz; ret1.Jzx ret1.Jzy ret1.Jzz];
    w = [0;0;motorLabsim.w1];
    L = J*w                                     % [kgm] - angular momentum
    
end
