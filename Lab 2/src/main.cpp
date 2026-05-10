#include <avr/io.h> 
#include <util/delay.h> 
 
int main(void) 
{ 
  DDRC = 0x0F; 
 
    while (1) 
    { 
       
      PORTC |= (1 << PC0); 
        _delay_ms(1000); 
         PORTC &= ~(1 << PC0); 
       
      PORTC |= (1 << PC1); 
        _delay_ms(1000); 
         PORTC &= ~(1 << PC1); 
       
      PORTC |= (1 << PC2); 
        _delay_ms(1000); 
         PORTC &= ~(1 << PC2); 
       
      PORTC |= (1 << PC3); 
        _delay_ms(1000); 
         PORTC &= ~(1 << PC3); 
 
         
    } 
} 
 