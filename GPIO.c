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
