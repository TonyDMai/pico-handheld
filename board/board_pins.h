/**
 * This is the GPIO Pin Map for the Handheld Pico 2 
 */
#ifndef BOARD_PINS_H
#define BOARD_PINS_H

/*UART0 Pins (Debug Probe Serial)*/
#define PIN_UART0_TX 0u
#define PIN_UART0_RX 1u

/*Button Pins*/
#define BTN_COUNT 8u
#define PIN_BTN_FIRST 2u
#define PIN_BTN_UP ( PIN_BTN_FIRST + 0u )
#define PIN_BTN_DOWN ( PIN_BTN_FIRST + 1u )
#define PIN_BTN_LEFT ( PIN_BTN_FIRST + 2u )
#define PIN_BTN_RIGHT ( PIN_BTN_FIRST + 3u )
#define PIN_BTN_A ( PIN_BTN_FIRST + 4u )
#define PIN_BTN_B ( PIN_BTN_FIRST + 5u )
#define PIN_BTN_SEL ( PIN_BTN_FIRST + 6u )
#define PIN_BTN_START ( PIN_BTN_FIRST + 7u )

#define BTN_MASK_ALL ( (1u << BTN_COUNT ) - 1u ) // 8 bit masks of all 1s, all buttons are sequential, so this will get all 8 buttons
#define BTN_GPIO_MASK ( BTN_MASK_ALL << PIN_BTN_FIRST ) // mask 8 bits starting at the bit from the first btn pin, these are the GPIO positions

/*Screen Pins*/
#define PIN_LCD_SCK 10u // Clock Pin, reads DIN on each pulse
#define PIN_LCD_TX 11u // Data line, what the screen should display
#define PIN_LCD_DC 12u // Data/Command , low = command high = pixel data
#define PIN_LCD_CS 13u // Chip Select, low = screen listen to this pin, high = ignore the bus. Lets other SPI1 dev share the same clk and DIN
#define PIN_LCD_RST 14u // Reset, pull it low so the controller is in a known state
#define PIN_LCD_BL 15u // Backlight LED, high = on, use PWM for brightness
#define LCD_SPI_INDEX 1u // The Screen is on SPI1

/* Buzzer Pin */
#define PIN_BUZZER 22u

/* Battery Pins*/
#define PIN_VBAT 29u //Battery GPIO Pin, internal pin
#define ADC_INPUT_VBAT 3u // ADC input channel number Analog - Digital Converter

#endif /* BOARD_PINS_H*/