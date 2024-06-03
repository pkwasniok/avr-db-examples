#define F_CPU 4000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    PORTD.DIRSET |= PIN7_bm;
    VPORTA.OUT |= PIN7_bm;

    while (1) {
        PORTD.OUTTGL |= PIN7_bm;
        _delay_ms(500);
    }
}
