#include "lib/include.h"

/* 
   Usando el modulo 0 y 1, configurar la tarjeta a la frecuencia asignada para adquirir 6 señales 
   analógicas a una velocidad de 1 millón de muestras por segundo para los canales asignados y guardar
   los valores en un arreglo para ser enviados con unos botones externos asociados al gpio D a través 
   del protocolo de comunicación asincrona a una velocidad de 115200 todo esto usando interrupciones 

   d) 11,9,6,7,4,2 33MHz 19200 - sec 3, sec 0, sec 2
 */

int main(void)
{
    uint16_t Result[2];
    uint16_t Result1[2];
    Configurar_PLL(_25MHZ); 
    Configurar_UART3();
    Configurar_GPIO();
    Configuracion_ADC0();
    Configuracion_ADC1();
    
    // Botones pines como I

    while(1)
    { 
          
    }
}
