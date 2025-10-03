// #define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


// 7  6   5   4   3   2   1   0 -> BIT POSITION
// 8  4   2   1   8   4   2   1 -> BIT SIZE (FOR HEX)
// 0  0   0   0   0   0   0   0 -> 
// 0  0   0   1   1   1   0   0 -> 1C
// Table for for digit from 0-9 
// correspomding pins(a=2, b=3, c= 4, d=5, e=6, f=7, g=8)

uint8_t digitPD[10] = {
  0b100000, // 0 → a,b,c,d,e ON, g OFF
  0b111001, // 1 → b,c ON
  0b000100, // 2 → a,b,d,e,g ON
  0b010000, // 3 → a,b,c,d,g ON
  0b011001, // 4 → b,c,g ON
  0b010010, // 5 → a,c,d,g ON
  0b000010, // 6 → a,c,d,e,g ON
  0b111000, // 7 → a,b,c ON
  0b000000, // 8 → all ON
  0b010000  // 9 → a,b,c,d,g ON
  
};

uint8_t digitPB[10] = {
    0, // 0 → f ON
    1, // 1 → f OFF
    1, // 2 → f OFF
    1, // 3 → f OFF
    0, // 4 → f ON
    0, // 5 → f ON
    0, // 6 → f ON
    1, // 7 → f OFF
    0, // 8 → f ON
    0  // 9 → f ON
};

void showNumber(uint8_t num) {
    PORTD = (digitPD[num] << 2);   // PD2–PD7
    if (digitPB[num]) PORTB |= (1 << PB0);
    else PORTB &= ~(1 << PB0);
}


int main (void){
    DDRB |= (1 << PB4) | (1 << PB3) | (1 << PB2) | (1 << PB0);  // PB4, PB3, PB2 & PB0 mark as OUTPUT
    DDRD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7); // PD2 all to PD7 OUTPUT
    PORTB &= ~((1 << PB0) | (1 << PB2) | (1 << PB3) | (1 << PB4)); // clear PB4, PB3, PB2 & PB0
    PORTD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7));
    PORTD = 0;
    
    while(1){
      for (int i = 0; i < 10; ++i){

        showNumber(i);
        
        if (i <= 4){
          PORTB |= (1 << PB4);
          PORTB &= ~((1 << PB3) | (1 << PB2));
        }
        
        else if (i <= 8){
          PORTB &= ~((1 << PB4) | (1 << PB2));
          PORTB |= (1 << PB3);
        }
        
        else {
          PORTB &= ~((1 << PB4) | (1 << PB3));
          PORTB |= (1 << PB2);
        }

        _delay_ms(1000);
      }
      _delay_ms(5000);

      PORTB &= ~((1 << PB2) | (1 << PB3) | (1 << PB4));
  }
}
