% Script plot the frequency response of a single pole low pass filter
Ts = 0.5;            % sample at 2 Hz
fc = 0.1;            % set the cutoff at 0.1 Hz
tauF = 1/(2*pi*fc);  % angular period for the cutoff
alpha = Ts/(Ts+tauF);% time domain filter coefficient
B = [0 alpha];       % numerator for digital frequency transfer function
A = [1 -(1-alpha)];  % denominator for digital frequency transfer function
[H, W] = freqz(B,A); % calculate the frequency response for the single
% get the frequency in hertz
f = ((W+1e-6)/pi)*(1/(2*Ts));
% get the magnitude of the filter in dB
HdB = 20*log10(abs(H));
h = figure;          % get a new figure and save the handle
% plot the frequency response
semilogx( f, HdB,'LineWidth',4)
% add notations to the plot
title('Digital Filter Frequency Response')
ylabel('Magnitude (dB)')
xlabel('Frequency (Hz)')
print(h,'-dpng','-color','dfilt.png')

% find the values which are less than -3 dB
II = ( 20*log10(abs(H)) < -3);
% get the first value which is less than -3 dB
N = find(II,1,'first');
% plot the values 40 points before and behind
% the -3 dB point
ww = (N-40):(N+40);
h = figure;
% plot the frequency response and mark the -3 dB point
semilogx( f(ww), HdB(ww), 'LineWidth',2,f(N),HdB(N),'o','markersize',20,'LineWidth',2)
title('Digital Filter Frequency Response -3 dB Point')
ylabel('Magnitude (dB)')
xlabel('Frequency (Hz)')
print(h,'-dpng','-color','dfilt3dB.png')

