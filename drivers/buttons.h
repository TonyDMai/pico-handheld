#ifndef BUTTONS_H
#define BUTTONS_H
#include <stdint.h>
#include "board_pins.h"

/* Individual Masks for the Buttons : PIN_BTN_X - PIN_BTN_FIRST = bit position in the buttons byte, this is the bit mask for each button */ 
#define BTN_UP ( 1u << (PIN_BTN_UP - PIN_BTN_FIRST ) )
#define BTN_DOWN ( 1u << (PIN_BTN_DOWN - PIN_BTN_FIRST ) )
#define BTN_LEFT ( 1u << (PIN_BTN_LEFT - PIN_BTN_FIRST ) )
#define BTN_RIGHT ( 1u << (PIN_BTN_RIGHT - PIN_BTN_FIRST ) )
#define BTN_A ( 1u << (PIN_BTN_A - PIN_BTN_FIRST ) )
#define BTN_B ( 1u << (PIN_BTN_B - PIN_BTN_FIRST ) )
#define BTN_SEL ( 1u << (PIN_BTN_SEL - PIN_BTN_FIRST ) )
#define BTN_START ( 1u << (PIN_BTN_START - PIN_BTN_FIRST ) )


void buttons_init(void); // Set Up buttons
void buttons_update(void); //Call every ~5ms check reads the pins and debounces
uint8_t buttons_held(void); // returns the buttons being held status
uint8_t buttons_pressed(void); // returns the buttons being pressed since last update


#endif /*BUTTONS_H */