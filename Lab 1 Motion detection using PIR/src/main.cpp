#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

// Pin Definitions
#define PIR_SENSOR   PD2
#define STATUS_LED   PD3
#define ALERT_LED    PD4
#define BUZZER       PD5

int main(void)
{
    // Configure LEDs and Buzzer as OUTPUT
    DDRD |= (1 << PD3);
    DDRD |= (1 << PD4);
    DDRD |= (1 << BUZZER);

    // Configure PIR Sensor as INPUT
    DDRD &= ~(1 << PD2);

    while (1)
    {
        // Blink System Status LED
        PORTD |= (1 << PD3);
        _delay_ms(1000);

        PORTD &= ~(1 << PD3);
        _delay_ms(1000);

        // Read PIR Sensor
        if (PIND & (1 << PD2))
        {
            // Motion detected

            // Turn ON Alert LED
            PORTD |= (1 << PD4);

            // Turn ON Buzzer
            PORTD |= (1 << PD5);

            // Alarm duration (5 seconds)
            _delay_ms(5000);

            // Turn OFF Alert LED
            PORTD &= ~(1 << PD4);

            // Turn OFF Buzzer
            PORTD &= ~(1 << PD5);
        }
    }

    return 0;
}