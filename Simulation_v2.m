clear all;
close all;
clc;
%% Initial Conditions
%global v; 
%global omega;
%global thetastar;
krho=.005;
kphi = .005;
Px1 = []
Py1 = []

Px2 = []
Py2 = []

Px3 = []
Py3 = []





%desired value
    P_x = 2;
    P_y= 3;
    Rt = [ 1 0; 0 1];
[phi_d, rho_d] = cart2pol(P_x,P_y)
phi_d
rho_d
w_d=.005; 
%cartesian values for  Nth robot
x=[-3 4 -3];
y=[-8 -3 3];
   
x=x-P_x; %offset to global coordinate value
y=y-P_y;

phi=zeros(1, length(x));
rho=zeros(1, length(x));
[phi,rho] = cart2pol(x,y);
phi
%Set value for N robots
N=3;

%Simulation time
% The computing step time
T=100;
tsteps=0.01; 
tt=0:tsteps:T;
dt=tt';
%% Formulation Setup

for k=1:1000;
    

    
    %Iterating for Control Law
    for i=1:N;
        %partial q(p)/dx q(p)/dy ; atan(y,x)/dx atan(y,x)/dy
        %J_i=[P_x/(sqrt(P_x^2+P_y^2)) P_y/(sqrt(P_x^2+P_y^2)); -P_y/(P_x^2+P_y^2) P_x/(P_x^2+P_y^2)];
        J_i=[x(i)/(sqrt(x(i)^2+y(i)^2)) y(i)/(sqrt(x(i)^2+y(i)^2)); -y(i)/(x(i)^2+y(i)^2) x(i)/(x(i)^2+y(i)^2)];
        %J_i=[(P_x-x(i))/(sqrt((P_x-x(i))^2+(P_y-y(i))^2)) (P_y-y(i))/(sqrt((P_x-x(i))^2+(P_y-y(i))^2)); -(P_y-y(i))/((P_x-x(i))^2+(P_y-y(i))^2) (P_x-x(i))/((P_x-x(i))^2+(P_y-y(i))^2)];
        
        %Vi=qi_dot= [rhoi_dot, thetai_dot]
        rhoi_dot = krho*(rho_d-rho(i))
        phi;
        i;
        N;
        phii_d= phii_(phi, i)
        phii_d = phi_d - phii_d
        phii_dot = w_d + kphi*(phi_d-phi(i));
        V_i= [rhoi_dot; phii_dot];
        Ui = Rt*(J_i'*V_i);
        x(i)= x(i) + Ui(1)*dt(k);
        y(i)= y(i) + Ui(2)*dt(k);
        %figure(1)
        %hold on
        %plot(x(i) , y(i))
        %hold on
        %plotting trajectory
        if i==1
            Px1 = [Px1 x(i)];
            Py1 = [Py1 y(i)];
        end
        if i==2
            Px2 = [Px2 x(i)];
            Py2 = [Py2 y(i)];
        end
        if i==3
            Px3 = [Px3 x(i)];
            Py3 = [Py3 y(i)];
        end
    end


end
%offset to global coordinate value
Px1=Px1+P_x;
Py1=Py1+P_y;
Px2=Px2+P_x;
Py2=Py2+P_y;
Px3=Px3+P_x;
Py3=Py3+P_y;


  plot(P_x,P_y,'--o','LineWidth',2);
for i=1:length(Px1)
  plot(Px1(i),Py1(i),'--x','LineWidth',2);
  
  plot(Px2(i),Py2(i),'*b','LineWidth',2);
  
  plot(Px3(i),Py3(i),'*r','LineWidth',2);
  hold on;
  pause(0.01);
end
%% Extra Code
%P_i=sqrt(x^2+y^2);
%theta_i=atan2(y,x);



