% Script plot the frequency response of a single pole low pass filter
Ts = 0.5;            % sample at 2 Hz
fc = 0.1;            % set the cutoff at 0.1 Hz
tauF = 1/(2*pi*fc);  % angular period for the cutoff
alpha = Ts/(Ts+tauF);% time domain filter coefficient
B = [0 alpha];       % numerator for digital frequency transfer function
A = [1 -(1-alpha)];  % denominator for digital frequency transfer function
[H, W] = freqz(B,A); % calculate the frequency response for the single
h = figure;          % get a new figure and save the handle
% plot the frequency response
semilogx( ((W+1e-6)/pi)*(1/(2*Ts)), 20*log10(abs(H)),'LineWidth',4)
% add notations to the plot
title('Digital Filter Frequency Response')
ylabel('Magnitude (dB)')
xlabel('Frequency (Hz)')
print(h,'-dpng','-color','dfilt.png')

