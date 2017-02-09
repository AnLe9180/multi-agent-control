clc;

figure(1)
for i=1:(length(coordinates_x)/2)
  plot(coordinates_x(i,1),coordinates_y(i,1),'*g','LineWidth',2);
  
  plot(coordinates_x(i,2),coordinates_y(i,2),'*b','LineWidth',2);
  
  plot(coordinates_x(i,3),coordinates_y(i,3),'*r','LineWidth',2);
  hold on;
end