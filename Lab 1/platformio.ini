#include <avr/io.h>
int main(void)
{

 DDRB |= (1<<0);
 DDRD &= ~(1<<2);
 PORTD |= (1<<2);
 while (1)
 {
 if (PIND & (1<<2))
 {
 PORTB |= (1<<0);
 }
 else
 {
 PORTB &= ~(1<<0);
 }
 }
}