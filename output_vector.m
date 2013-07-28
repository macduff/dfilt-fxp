% load the input data and plot it
test_vector;
% load the results of the simulation
out;
Ts = 0.5;                            % sample at 2 Hz
tt = (0:(length(y)-1))*Ts; % get the time for each sample
h = figure;
plot( tt, y, 'LineWidth', 2);
% add notations to the plot
title('Digital Filter Output')
ylabel('Magnitude (bits)')
xlabel('Time (s)')
print(h,'-dpng','-color','output.png')
% plot both the input and output
h = figure;
plot( tt, test_vector, 'LineWidth', 2, tt, y, 'LineWidth', 2);
% add notations to the plot
title('Digital Filter Input and Output')
ylabel('Magnitude (bits)')
xlabel('Time (s)')
print(h,'-dpng','-color','io.png')

