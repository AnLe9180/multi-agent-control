function [Vf, W, target_distance, ang_to_tar, target_xy, states] = ...
    WaypointControl(target_list, robot_xyt, vlimit, ...
    dist_thr, ang_thr, method, step, Kv_1, Kw_1, Kv_2, Kw_2, pre_states)

% Initialize output variables

%robot_xyt=[robot_xyt(2);robot_xyt(1);robot_xyt(3)] /1000; % estimate of robot xy from pixel location
%target_list = [target_list(2) target_list(1)] /1000; % estimate of target xy from target in pixels


 Vf=0;
 W=0;
 finished_path_flag=0; 
 
 persistent Vf_1 end_flag;
 
 if isempty(Vf_1)
     Vf_1=0;
 end
 if isempty(end_flag)
    end_flag = 0;
 end
states = pre_states;

rx = robot_xyt(2);
ry = robot_xyt(1);
rtheta = check_angle(robot_xyt(3));
target_xy = [rx ry];
[n xy] = size(target_list);
if n==1 && xy==2
    target_xy = [target_list(1,2) target_list(1,1)];
    n = 1;
else
    for i=1:n
        if states(1) == i
            for j=1:xy
                target_xy(j) = target_list(i, j);
            end
        end
    end
end

tx = target_xy(1);
ty = target_xy(2);
target_distance = find_dist(rx, ry, tx, ty);
target_distance = target_distance/1000;
% ang_to_tar= find_theta(rx, ry, rtheta, tx, ty);

% for image     
X = 0;
Y = ty - ry;
theta = -0.005*Y;
ang_to_tar = check_angle(check_angle(theta)-check_angle(rtheta));


if ((states(1) == n) && (target_distance <= dist_thr))  %|| states(1) == -1
% %        states(1) = -1;
       % right_vel = int16(0);
       % left_vel = int16(0);
%  %       target_distance = 0;
        Vf=0;
        W=0;
        
       %if (end_flag == 1) && (target_distance <= dist_thr) % after all waypoints, psi will be adjusted to psi_d 
       %     [Vf, W] = ClosedLoop_Sequential(0, check_angle(check_angle(Psi_d)-check_angle(rtheta)), vlimit, ang_thr, dist_thr, Kv_1, Kw_1, Vf_1); 
       %      Vf_1=Vf;
       %end
        
   
else
    
    if (target_distance <= dist_thr) && (end_flag==0)
            states(1) = pre_states(1) + step;%1;
            
         while (abs((target_list(states(1),1))-(target_list(pre_states(1),1)))<2*dist_thr) && (abs((target_list(states(1),2))-(target_list(pre_states(1),2)))<2*dist_thr)
             if (states(1)<=(n-step))
                 states(1) = states(1) + step;%1;
             else
                 states(1)=n;
             end
         end

          
         if states(1) >= n 
            states(1) = n;
            end_flag=1;
         end
        
               
  %  elseif (end_flag == 1) && (target_distance <= dist_thr) % after all waypoints, psi will be adjusted to psi_d 
  %          [Vf, W] = ClosedLoop_Sequential(0, check_angle(check_angle(Psi_d)-check_angle(rtheta)), vlimit, ang_thr, dist_thr, Kv_1, Kw_1, Vf_1); 
  %           Vf_1=Vf;
    else
        
        
            if method == 2
                [Vf, W] = ClosedLoop_Both(target_distance,  ang_to_tar, vlimit, Kv_2, Kw_2);    
            else
    %            [right_vel, left_vel] = rotate_and_go(ang_to_tar, vlimit, ang_thr);
                [Vf, W] = ClosedLoop_Sequential(target_distance,  ang_to_tar, vlimit, ang_thr, dist_thr, Kv_1, Kw_1, Vf_1); 
                Vf_1=Vf;
            end
                 
    end
end


return;

%--------------------------------------------------------------------------
function [y] = check_angle(x)
y = x;
if x > pi
    y = x - 2*pi;
elseif x < -pi
    y = x + 2*pi;
end
return;
% -------------------------------------------------------------------------
function dist = find_dist(rx, ry, tx, ty)
dist = sqrt((rx-tx)^2 + (ry-ty)^2);
return;
% -------------------------------------------------------------------------
function [theta]= find_theta(rx, ry, rtheta, tx, ty)

X = tx - rx;
Y = ty - ry;
theta = atan2(Y, X);
theta = check_angle(check_angle(theta)-check_angle(rtheta));

return;
% -------------------------------------------------------------------------

function [Vf, W] = ClosedLoop_Both(dist, theta, vlimit, Kv,Kw)

d = 0.23;
vmax = vlimit;
wmax = (2*vmax);
W = Kw*theta;

%if abs(theta)<pi
Vf = Kv*dist;
%else
%    Vf=0;
%end

w_sign = sign(W);
if abs(W) > wmax
    W = w_sign*wmax;
end
if abs(Vf)> vlimit
    Vf = abs(Vf)*vlimit;
end

return;

function [Vf, W] = ClosedLoop_Sequential(dist, theta, vlimit, ang_thr, dist_thr, Kv, Kw, Vf_1)

d = 0.23;
vmax = vlimit;
wmax = (2*vmax);

if (((abs(theta) > ang_thr))  && (Vf_1<0.01)) || (abs(theta) > 5*ang_thr) % once rotated, then moves. once started moving, it won't turn unless the heading is too off target or have reached the previous target.
        W=Kw*theta;
        Vf=0;
        if abs(W)> wmax
            W=sign(theta)*wmax;
        end
else
        Vf=Kv*dist;
       
        if abs(Vf)>vlimit
            Vf=sign(Vf)*vlimit;
        end
       % if (abs(theta) > 2*ang_thr)
       %   W=Kw*theta;
       %   Vf=0.4*Vf;
       % else
       W=0;
       % end
       % if abs(W)> wmax
       %     W=sign(theta)*wmax;
       % end
        
end

return;

%{
function [vr, vl] = solve_inv_kin(dist, theta, vlimit, delta_t)

d = 0.23;
vmax = vlimit(2);
wmax = (2*vmax)/d;
w = theta/delta_t;
w_sign = sign(w);
if abs(w) > wmax
    w = w_sign*wmax;
    vr = int16(round((d*w)/2));
    vl = int16(-vr);
else
    v = dist/delta_t;
    vr_tmp = (2*v + d*w)/2;
    vl_tmp = 2*v - vr_tmp;
    
    max_of_vrvl = abs(max(vr_tmp, vl_tmp));
    if max_of_vrvl > vmax
        vr_tmp = (vr_tmp/max_of_vrvl)*vmax;
        vl_tmp = (vl_tmp/max_of_vrvl)*vmax;
    end
    vr = int16(vr_tmp);
    vl = int16(vl_tmp);

end


return;
%}

%{
% -------------------------------------------------------------------------
function [vr, vl] = rotate_and_go(theta, vlimit, ang_thr)

if abs(theta) > ang_thr
    if theta >= 0
        vr = int16(vlimit(1));
        vl = int16(-vlimit(1));
    else
        vr = int16(-vlimit(1));
        vl = int16(vlimit(1));
    end
else
        vr = int16(vlimit(2));
        vl = int16(vlimit(2));
end

return;
% -------------------------------------------------------------------------
%}