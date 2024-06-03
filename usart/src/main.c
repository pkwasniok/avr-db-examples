#define F_CPU 4000000

#include <avr/io.h>
#include <util/delay.h>

#include "./usart.h"

volatile char data[] = "Hello, world!\r\n";

int main(void)
{
    // Configure USART0 Tx pin as output
    PORTA.DIRSET |= (1<<0);

    // Initialize USART0
    usart_init(&USART0, 9600);

    while (1) {
        char *pointer = data;
        while (*pointer != '\0') {
            usart_write(&USART0, *(pointer++));
        }

        _delay_ms(1000);
    }
}
