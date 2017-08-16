% Reference::
% - "A Computational Approach To Edge Detection", 
%   J. Canny,
%   IEEE Trans. Pattern Analysis and Machine Intelligence, 8(6):679–698, 1986.
%
% Original Author::
% Oded Comay, Tel Aviv University, 1996-7.
%
% See also ISOBEL, KDGAUSS.


% I: greyscale uint8
function E = canny_edge_detect(Im,sigma,kernlen,th_low,th_high)
    
    I = cast(Im,'double');
    
    sd = sigma;
    th0 = th_low;
    th1 = th_high;

    %x= -5*sd:sd*5;
    x = -floor(kernlen/2):1:floor(kernlen/2);
    g = exp(-0.5/sd^2*x.^2); 		% Create a normalized Gaussian
    g = g(g>max(g)*.005); g = g/sum(g(:));
    dg = diff(g);				% Gaussian first derivative

    dx = abs(conv2(I, dg, 'same'));		% X/Y edges
    dy = abs(conv2(I, dg', 'same'));

    [ny, nx] = size(I);
                        % Find maxima 
    dy0 = [dy(2:ny,:); dy(ny,:)]; dy2 = [dy(1,:); dy(1:ny-1,:)];
    dx0 = [dx(:, 2:nx) dx(:,nx)]; dx2 = [dx(:,1) dx(:,1:nx-1)];
    peaks = find((dy>dy0 & dy>dy2) | (dx>dx0 & dx>dx2));
    e = zeros(size(I));
    e(peaks) = sqrt(dx(peaks).^2 + dy(peaks).^2); 

    e(:,2)    = zeros(ny,1);    e(2,:) = zeros(1,nx);	% Remove artificial edges at image border
    e(:,nx-2) = zeros(ny,1); e(ny-2,:) = zeros(1,nx);
    e(:,1)    = zeros(ny,1);    e(1,:) = zeros(1,nx);
    e(:,nx)   = zeros(ny,1);   e(ny,:) = zeros(1,nx);
    e(:,nx-1) = zeros(ny,1); e(ny-1,:) = zeros(1,nx);
    e = e/max(e(:));

    if th1  == 0, E = e; return; end
    E(ny,nx) = 0;

    % Edge thinning
    p = find(e >= th1);
    while ~isempty(p)
      E(p) = e(p);
      e(p) = zeros(size(p));
      n = [p+1 p-1 p+ny p-ny p-ny-1 p-ny+1 p+ny-1 p+ny+1]; % direct neighbors
      On = zeros(ny,nx); On(n) = n;
      p = find(e > th0 & On);
    end
