#ifndef UART_UART_H_
#define UART_UART_H_

extern void Configurar_UART3(void);
extern char readChar(void);
extern void printChar(char c);
extern void printString(char* string);
extern char * readString(char delimitador);
extern void UART3_Transmitter(unsigned char Result,unsigned char Result1);


#endif /* UART_UART_H_ */