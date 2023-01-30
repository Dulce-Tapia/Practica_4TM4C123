%% Código para graficar señales de MATLAB 
clc;
clear; 
close all;

%% Comunicación con UART
puerto = serialport("COM5",19200);
muestras = 50000; %Cantidad de muestras 
cont = 1;

%% Formato de la gráfica
figure('Name', 'Señales del ADC', 'NumberTitle', 'on','color',[1 1 1]);
title('VOLTAJE DEL ADC', 'FontName', 'Arial', 'FontSize', 12);
xlabel('tiempo [s]', 'FontName', 'Arial', 'FontSize', 9);
ylabel('Amplitud [v]', 'FontName', 'Arial', 'FontSize', 9);
grid on; 
hold on;
time = 1:1:muestras;
ylim([0 3.5]);
xlim([0 muestras]);

%% 
ADC = cell(1, 6); 
for i=1:6
    ADC{i} = zeros(1, muestras);
end
adc1 = animatedline('Color', 'r');
adc2 = animatedline('Color', 'c');
adc3 = animatedline('Color', 'g');
adc4 = animatedline('Color', 'm');
adc5 = animatedline('Color', 'b');
adc6 = animatedline('Color', 'y');

legend("1", "2", "3", "4", "5", "6");

while true
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
    addpoints(adc1, time(cont), voltage_1);
    addpoints(adc2, time(cont), voltage_2);
    addpoints(adc3, time(cont), voltage_3); 
    addpoints(adc4, time(cont), voltage_4);
    addpoints(adc5, time(cont), voltage_5);
    addpoints(adc6, time(cont), voltage_6);
    drawnow

    cont = cont+1; 
    if cont == muestras 
        break 
    end 
end