#include "lib/include.h"

/* 
   Usando el modulo 0 y 1, configurar la tarjeta a la frecuencia asignada para adquirir 6 señales 
   analógicas a una velocidad de 1 millón de muestras por segundo para los canales asignados y guardar
   los valores en un arreglo para ser enviados con unos botones externos asociados al gpio D a través 
   del protocolo de comunicación asincrona a una velocidad de 115200 todo esto usando interrupciones 

   d) 11,9,6,7,4,2 19200 - sec 3, sec 0, sec 2
 */

int main(void)
{
    uint16_t Result[2];
    uint16_t Result1[2];
    char ADC_1[4];
    char ADC_2[4];
    char ADC_3[4];
    char ADC_4[4];
    char ADC_5[4];
    char ADC_6[4];
    Configurar_PLL(_80MHZ); 
    Configurar_UART3();
    Configurar_GPIO();
    Configuracion_ADC0();
    Configuracion_ADC1();

    while(1)
    { 
       ADC0_In1(Result);
       ADC1_In2(Result1); 
       ADC1_In3(Result1);
       
       //Convertir los valores números a caracteres para enviarlos por el UART
       itoa(Result[0],ADC_1,10);
       itoa(Result[1],ADC_2,10);
       itoa(Result[2],ADC_3,10);
       itoa(Result1[0],ADC_4,10);
       itoa(Result1[1],ADC_5,10);
       itoa(Result1[2],ADC_6,10);
       
       printString(ADC_1);
       printString(ADC_2);
       printString(ADC_3);
       printString(ADC_4);
       printString(ADC_5);
       printString(ADC_6);   
    }
}
