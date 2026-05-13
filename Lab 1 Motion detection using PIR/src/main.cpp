#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


// Function to generate tone
void tone(unsigned int frequency, unsigned int duration_ms)
{
    unsigned long i;
    unsigned long delay_us;

    // Half period calculation
    delay_us = 1000000UL / (frequency * 2);

    // Generate square wave
    for(i = 0; i < ((unsigned long)duration_ms * 1000UL) / (delay_us * 2); i++)
    {
        PORTD |= (1 << PD5);
        _delay_us(delay_us);

        PORTD &= ~(1 << PD5);
        _delay_us(delay_us);
    }
}

int main(void)
{
    // Configure LEDs and buzzer as OUTPUT
    DDRD |= (1 << PD3);
    DDRD |= (1 << PD4);
    DDRD |= (1 << PD5);

    // Configure PIR sensor as INPUT
    DDRD &= ~(1 << PD2);

    while(1)
    {
        // Blink status LED
        PORTD |= (1 << PD3);
        _delay_ms(1000);

        PORTD &= ~(1 << PD3);
        _delay_ms(1000);

        // Check PIR sensor
        if(PIND & (1 << PD2))
        {
            // Motion detected
            PORTD |= (1 << PD4);

            // Generate buzzer sound
            tone(1000, 5000);   // 1000Hz for 5 seconds

            // Turn OFF alert LED
            PORTD &= ~(1 << PD4);
        }
    }

    return 0;
}