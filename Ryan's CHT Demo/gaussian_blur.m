function [I] = gaussian_blur(Image, sigma, kernel_len)
    x = -(floor(kernel_len/2)):1:(floor(kernel_len/2)); % calculate Gaussian (1D)
    g = exp(-0.5/sigma^2*x.^2);    
    g = g(g>max(g)*.005);
    kg = g/sum(g(:));            % normalize Gaussian 

    I = cast(conv2(kg, kg, double(Image),'same'), 'uint8');

end

