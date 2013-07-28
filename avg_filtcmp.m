Ts = 0.01;
fc = 1;
tauF = 1/(2*pi*fc);
alpha = Ts/(Ts+tauF)
B = [0 alpha];
A = [1 -(1-alpha)];
[H, W] = freqz(B,A);
[Havg,Wavg] = freqz( ones(1,10)/10, 1 );
F = ((W+1e-6)/pi)*(1/(2*Ts));
Favg = ((Wavg+1e-6)/pi)*(1/(2*Ts));
h = figure;
plot( Favg, 20*log10(abs(Havg)),'LineWidth',2, F, 20*log10(abs(H)),'LineWidth',2 )
legend('Averaging Filter','Single Pole Filter')
title('Averaging/Single Pole Filter Frequency Response')
xlabel('Frequency (Hz)')
ylabel('Magnitude (dB)')
print(h,'-dpng','-color','filtcmp.png')

h = figure;
plot( Favg, (180/pi)*angle(Havg),'LineWidth',2, F, (180/pi)*angle(H),'LineWidth',2 )
legend('Averaging Filter','Single Pole Filter')
title('Averaging/Single Pole Filter Phase Response')
xlabel('Frequency (Hz)')
ylabel('Phase (degrees)')
print(h,'-dpng','-color','filtcmp_phase.png')

