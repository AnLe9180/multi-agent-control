function Im = draw_circle2(I, yIndex, xIndex, radius, max_val)
Im = I;
Y0_MAX_LEN = 300;

numRow = size(I,1);
numCol = size(I,2);

y0ffset = zeros(1,Y0_MAX_LEN);
x0 = zeros(1,Y0_MAX_LEN);

y0_len = 2*radius + 1;


for j=1:y0_len
    y0ffset(j) = ceil(sqrt(radius^2 - (-radius + (j-1)).^2 ));
end

for cnt = 1:numel(xIndex)
    low=xIndex(cnt)-radius;
    high=xIndex(cnt)+radius;
    
    
    if (low<1)
        start_index_offset = -low;
        if high>numCol
            x0 = 1:numCol;
        else
            x0=1:high;
        end
    else
        start_index_offset = 0;
        if (high>numCol)
            x0=low:numCol;
        else
            x0 = low:high;
        end
    end
    
    for i = 1:length(x0)
        
        y01 = yIndex(cnt)-y0ffset(i + start_index_offset);
        y02 = yIndex(cnt)+y0ffset(i + start_index_offset);
                
        if y01 < numRow && y01 >= 1
            Im(y01,x0(i)) = max_val;
        end
        
        if y02 < numRow && y02 >= 1
            Im(y02,x0(i)) = max_val;
        end
    end
end