Ts = 0.5;
fc = 0.1;
tauF = 1/(2*pi*fc);
alpha = Ts/(Ts+tauF)
B = [0 alpha];
A = [1 -(1-alpha)];
[H, W] = freqz(B,A);
h = figure;
semilogx( ((W+1e-6)/pi)*(1/(2*Ts)), 20*log10(abs(H)),'LineWidth',4)
title('Digital Filter Frequency Response')
ylabel('Magnitude (dB)')
xlabel('Frequency (Hz)')
print(h,'-dpng','-color','dfilt.png')

