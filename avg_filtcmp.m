% Script to compare an moving average filter
% with a single pole low pass filter
Ts = 0.01;  % sample at 100 Hz
fc = 1;     % set the cutoff at 1 Hz
tauF = 1/(2*pi*fc);   % angular period for the cutoff
alpha = Ts/(Ts+tauF); % time domain filter coefficient
B = [0 alpha];        % numerator for digital frequency transfer function
A = [1 -(1-alpha)];   % denominator for digital frequency transfer function
[H, W] = freqz(B,A);  % calculate the frequency response for the single
                      % pole filter
[Havg,Wavg] = freqz( ones(1,10)/10, 1 ); % calculate the frequency response
                                         % for the averaging filter
F = ((W+1e-6)/pi)*(1/(2*Ts));            % get the frequency in Hz for
Favg = ((Wavg+1e-6)/pi)*(1/(2*Ts));      % both filters
h = figure;                              % get a new figure and save the handle
% plot the frequency response of both filters
plot( Favg, 20*log10(abs(Havg)),'LineWidth',2,...
      F, 20*log10(abs(H)),'LineWidth',2 )
% add notations to the plot
legend('Averaging Filter','Single Pole Filter')
title('Averaging/Single Pole Filter Frequency Response')
xlabel('Frequency (Hz)')
ylabel('Magnitude (dB)')
% write the plot to a PNG file
print(h,'-dpng','-color','filtcmp.png')

h = figure;
plot( Favg, (180/pi)*angle(Havg),'LineWidth',2, F, (180/pi)*angle(H),'LineWidth',2 )
legend('Averaging Filter','Single Pole Filter')
title('Averaging/Single Pole Filter Phase Response')
xlabel('Frequency (Hz)')
ylabel('Phase (degrees)')
print(h,'-dpng','-color','filtcmp_phase.png')

