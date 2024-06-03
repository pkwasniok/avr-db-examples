#ifndef USART_H_
#define  USART_H_

#include <avr/io.h>

void usart_init(USART_t *usart, uint32_t baud_rate);
void usart_write(USART_t *usart, uint8_t byte);
uint8_t usart_read(USART_t *usart, char *buffer);

#endif // USART_H_
