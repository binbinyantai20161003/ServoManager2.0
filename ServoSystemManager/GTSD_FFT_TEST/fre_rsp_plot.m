%%
% by liu.g
% 2014/03/17
%%

clc;
clear;
close all;

% [n real, imag, out_real, out_imag]  = textread('data.txt','%d %f %f %f %f');
% [TS]                                = textread('para.txt','%f');
% [m m_dbb m_phh]                     = textread('dpf.txt','%d %f %f');
 [TS]                                = textread('para.txt','%f');
 [m m_dbb m_phh]                     = textread('dpf.txt','%d %f %f');
% 
N1 = length(m);
fsamp = 1/TS;
N2 = fix(N1/2);

f1     =    fsamp*(0:N2)/N1;
fbd    =    fsamp*(N2/N1);

% xin    =   real + i*imag;
% xout   =   out_real + i*out_imag;
% 
% gin    =   (abs(xin) * 2.0) / N1;
% gout   =   (abs(xout) * 2.0) / N1;
% 
% dbb     =   20*log10(gout./gin);
% 
% angin   =   angle(xin);
% angout  =   angle(xout);
% phh     =   unwrap(angout-angin)/2/pi*360;

subplot(2,1,1)

% semilogx(f1,dbb(1:N2+1),'b-.','linewidth',2);hold on;
semilogx(f1,m_dbb(1:N2+1),'r-','linewidth',2);
% hold off;
axis([1 fbd/2 -70 5]);                
grid on;
xlabel('Frequency [Hz]');
ylabel('Gain [dB]');   


subplot(2,1,2)
% semilogx(f1,phh(1:N2+1),'b-.','linewidth',2); hold on;
semilogx(f1,m_phh(1:N2+1)/2/pi*360,'r-','linewidth',2); 
% hold off;
axis([1 fbd/2 -360 360]);
grid on; 
xlabel('Frequency [Hz]');
ylabel('Phase [deg]'); 


