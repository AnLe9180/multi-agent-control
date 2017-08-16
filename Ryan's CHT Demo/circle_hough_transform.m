function [Accumulator, EdgePixelCount] = circle_hough_transform(I, radius)
%#codegen
T_ACCUMULATOR = 'double'; %T_ACCUMULATOR = 'uint16';

rows = size(I,1);
cols = size(I,2);

Y0_MAX_LEN = 1000;

Accumulator = zeros(size(I), T_ACCUMULATOR);
[yIndex, xIndex] = find(I);
EdgePixelCount = numel(xIndex);

y0ffset = zeros(1,Y0_MAX_LEN, T_ACCUMULATOR);
x0 = zeros(1,Y0_MAX_LEN, T_ACCUMULATOR);

y0_len = 2*radius + 1;


for j=1:y0_len
    y0ffset(j) = ceil(sqrt(radius^2 - (-radius + (j-1)).^2 ));
end

for cnt = 1:EdgePixelCount
    low=xIndex(cnt)-radius;
    high=xIndex(cnt)+radius;
    
    
    if (low<1)
        start_index_offset = -low;
        if high>cols
            x0 = 1:cols;
        else
            x0=1:high;
        end
    else
        start_index_offset = 0;
        if (high>cols)
            x0=low:cols;
        else
            x0 = low:high;
        end
    end
    
    for i = 1:length(x0)
        
        y01 = yIndex(cnt)-y0ffset(i + start_index_offset);
        y02 = yIndex(cnt)+y0ffset(i + start_index_offset);
        
        if y01 < rows && y01 >= 1
            Accumulator(y01,x0(i)) = Accumulator(y01,x0(i))+1;
        end
        
        if y02 < rows && y02 >= 1
            Accumulator(y02,x0(i)) = Accumulator(y02,x0(i))+1;
        end
    end
end