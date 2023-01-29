%% Código para graficar señales de MATLAB 
clc;
clear; 
close all;

%% Comunicación con UART
puerto = serialport("COM5",19200,'timeout',5);
muestras = 10000; %Cantidad de muestras 
cont = 0;

%% Formato de la gráfica
figure('Name', 'Señales del ADC', 'NumberTitle', 'on','color',[1 1 1]); grid on;
title('Voltajes de 6 canales del ADC', 'FontName', 'Arial', 'FontSize', 12);
xlabel('tiempo [s]', 'FontName', 'Arial', 'FontSize', 9);
ylabel('Amplitud [v]', 'FontName', 'Arial', 'FontSize', 9);
xlim([0 100]);
ylim([0 4]);

%% 
while cont<muestras
    if mod(cont,100) == 0 %Para modificar limite en eje x y hacer una grafica movible 
       xlim([cont cont+100]);
    end
    
    % Convertir números a caracterés además de leer 
    ADC{1}(cont) = str2double(readline(puerto));
    ADC{2}(cont) = str2double(readline(puerto));
    ADC{3}(cont) = str2double(readline(puerto));
    ADC{4}(cont) = str2double(readline(puerto));
    ADC{5}(cont) = str2double(readline(puerto));
    ADC{6}(cont) = str2double(readline(puerto));
    
    %Conversión a voltaje
    voltaje_1 = (ADC{1}(cont)*3.3)/4096;
    voltaje_2 = (ADC{2}(cont)*3.3)/4096;
    voltaje_3 = (ADC{3}(cont)*3.3)/4096;
    voltaje_4 = (ADC{4}(cont)*3.3)/4096;
    voltaje_5 = (ADC{5}(cont)*3.3)/4096;
    voltaje_6 = (ADC{6}(cont)*3.3)/4096;
    
    %Graficar
    plot(voltaje_1, 'm');
    hold on;
    plot(voltaje_2, 'm');
    plot(voltaje_3, 'm');
    plot(voltaje_4, 'm');
    plot(voltaje_5, 'm');
    plot(voltaje_6, 'm');
    drawnow;
    hold off;
    
    cont = cont+1;  
end