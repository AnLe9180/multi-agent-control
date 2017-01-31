
function delta = phii_(theta, N)
    %for i=1:len(theta)
    %    phi_sum = phi_sum - theta(i);
    %end
    sz = size(theta);
    for i=1:(sz*2)
         theta = [theta theta(i)];
    end
    theta = [theta(sz(2)) theta] ;
   

    theta ;
    theta(N) ;
    theta(N+2);
    delta = (theta(N) + theta(N+2)) / 2;
end
