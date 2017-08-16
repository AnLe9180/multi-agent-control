function [ I_out ] = downsample( I, rate )

offset = ceil(rate/2);
I_out = cast(I(offset:rate:size(I,1),offset:rate:size(I,2)), 'uint8');

end

