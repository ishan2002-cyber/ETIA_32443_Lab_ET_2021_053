#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
    // Configure LEDs and Buzzer as OUTPUT
    DDRD |= (1 << PD3);
    DDRD |= (1 << PD4);
    DDRD |= (1 << PD5);

    // Configure PIR Sensor as INPUT
    DDRD &= ~(1 << PD2);

    while (1)
    {
       
    }

    return 0;
}