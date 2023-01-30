#include "lib/include.h"

extern void Configurar_GPIO(void)
{
    SYSCTL->RCGCGPIO |=(1<<3); 
    GPIOD->LOCK= 0x4C4F434B;   // 2) unlock GPIO Port F
    GPIOD->CR = 0x1F;           // allow changes to PF4-0
    GPIOD->AMSEL = 0x00;        // 3) disable analog on PF
    GPIOD->PCTL = 0x00000000;   // 4) PCTL GPIO on PF4-0
    GPIOD->DIR = 0x0E;          // 5) PF4,PF0 in, PF3-1 out
    GPIOD->AFSEL = 0x00;        // 6) disable alt funct on PF7-0
    GPIOD->PUR = 0x11;          // enable pull-up on PF0 and PF4
    GPIOD->DEN = 0x1F;          // 7) enable digital I/O on PF4-0

    
    SYSCTL->RCGCGPIO |=(1<<0);  // Se habilita el puerto A
    GPIOA->LOCK= 0x4C4F434B;   // 2) unlock GPIO Port A
    GPIOA->CR = 0xFF;           // allow changes to PA0-7
    GPIOA->AMSEL = 0x00;        // 3) disable analog on PA Deshabilita la función analógica 687
    GPIOA->PCTL = 0x00000000;   // 4) PCTL GPIO on PA0-7 Función Alternativa
    GPIOA->DIR = (0<<5)|(0<<4)|(0<<3)|(0<<2)|(0<<1)|(0<<0);          // 5) Indicar si es I-0 S-1
    GPIOA->AFSEL = 0x00;        // 6) disable alt funct on PA7-0 acticar la función alternativa 
    GPIOA->PUR = (1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1)|(1<<0);          // modo de los pines pull-down PA0 - PA7 pág. 678
    GPIOA->DEN = (1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1)|(1<<0);          // 7) enable digital I/O on PA5-0

    // Configuración de interrupción de botones 
    // Nota. porque en el puerto PD se encuentra ocupado 
    //Limpiar los bits en los pines a utilizar pág. 664
    GPIOA_AHB->IM |= (0<<5)|(0<<4)|(0<<3)|(0<<2)|(0<<1)|(0<<0); 
    // Para detectar bordes (cambio) pág. 664 
    GPIOA_AHB->IS |= (0<<5)|(0<<4)|(0<<3)|(0<<2)|(0<<1)|(0<<0); 
    // Para que interrupción sea controlada por IEV pág. 665
    // Segunda opción detecta los 2 bordes 
    GPIOA_AHB->IBE |= (0<<5)|(0<<4)|(0<<3)|(0<<2)|(0<<1)|(0<<0);
    // Para controlar con flanco de bajada (0) o flanco de subida (1)
    GPIOA_AHB->IEV |= (1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1)|(1<<0);
    // No ha ocurrido una interrupción en los pines pág. 668
    GPIOA_AHB->RIS |= (0<<5)|(0<<4)|(0<<3)|(0<<2)|(0<<1)|(0<<0);
    // El nivel es detectado en el pin correspondiente 664
    GPIOA_AHB->IM |= (1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1)|(1<<0);
    // Pág. 104 donde se indica el numero de interrupcion
     // n=12 ----> [4n+3] [4n+2] [4n+1] [4n] ---> [4n+3]
     // 0 es el número de prioridad 
    NVIC->IP[0] = (NVIC->IP[0]&0xFFFFFF00) | 0x20000000;
    // Habilitar la interrupción 
    NVIC -> ISER[0] = 0x00000001;

}

extern void Delay(void)
{
  unsigned long volatile time;
  time = 1600000;
  while(time)
  {
		time--;
  }
}
