#ifndef _IO_H
#define _IO_H

#define PERIPHERAL_BASE 0xFE000000

void uart_init();
void uart_writeText(char *buffer);
void uart_readText();
void uart_loadOutputFifo();
unsigned char uart_readByte();
unsigned int uart_isReadByteReady();
void uart_writeByteBlocking(unsigned char ch);
void uart_writeByteBlockingActual(unsigned char ch);
void uart_update();
void mmio_write(long reg, unsigned int val);
unsigned int mmio_read(long reg);

extern unsigned char uart_input_line[100];

#endif /* _IO_H */