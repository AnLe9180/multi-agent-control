%test

%% Initial Conditions
global v; 
global omega;
global thetastar;
krho=.5;
kphi = .5;

%cartesian values for  Nth robot
x=[5 6 7];
y=[5 6 7];
theta=zeros(1, length(x));
rho=zeros(1, length(x));


[theta,rho] = cart2pol(x,y)


sqrt(2)

    P_x = 2;
    P_y= 3;
    Rt = [ 1 0; 0 1];
[phi_d, rho_d] = cart2pol(P_x,P_y)
w_d=3; 