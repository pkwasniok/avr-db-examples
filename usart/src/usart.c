#include "./usart.h"

void usart_init(USART_t *usart, uint32_t baud_rate) {
    // Set baud rate
    usart->BAUD = (uint16_t)((((640 * (uint32_t)4000000) / (16 * baud_rate)) + 5) / 10);

    // Set frame format and mode of operation (8 data bit, 1 stop bit, asynchronous, no parity)
    usart->CTRLC |= (0x3<<0);

    // Enable transmitter and receiver
    usart->CTRLB |= (1<<7) | (1<<6);
}

void usart_write(USART_t *usart, uint8_t byte) {
    while ((usart->STATUS & USART_DREIF_bm) == 0);
    usart->TXDATAL = byte;
}

uint8_t usart_read(USART_t *usart, char *buffer) {
    if ((usart->STATUS & USART_RXCIF_bm) == 0) {
        return 0;
    }

    *buffer = usart->RXDATAL;

    return 1;
}
