#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/structs/sio.h"
#include "hardware/structs/io_bank0.h"
#include "hardware/structs/pads_bank0.h"

#define BLINK_DELAY_MS 250
#define LED_PIN PICO_DEFAULT_LED_PIN
#define LED_MASK (1u << LED_PIN) 

static void sdk_blink(void){
    gpio_init(PICO_DEFAULT_LED_PIN); // init LED to GPIO equivalent to P1SEL0,1 IN MSP43XR
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT); //Set as output equivalent of P1DIR |= BIT0;

    while (true) {

        gpio_put(PICO_DEFAULT_LED_PIN, 1);
        printf("ON\n");
        sleep_ms(BLINK_DELAY_MS);
        gpio_put(PICO_DEFAULT_LED_PIN, 0);
        printf("OFF\n");
        sleep_ms(BLINK_DELAY_MS);
    }
}


static void reg_edit_blink(void){
    pads_bank0_hw->io[LED_PIN] |= PADS_BANK0_GPIO0_IE_BITS; // Enable Input for the LED PIN
    pads_bank0_hw->io[LED_PIN] &= ~PADS_BANK0_GPIO0_OD_BITS; // Clear the disable output bit for LED

    io_bank0_hw->io[LED_PIN].ctrl = GPIO_FUNC_SIO << IO_BANK0_GPIO0_CTRL_FUNCSEL_LSB; // Sets LED pin as GPIO <- This is P1SEL0/1 = 0,0
    pads_bank0_hw->io[LED_PIN] &=  ~PADS_BANK0_GPIO0_ISO_BITS; //Remove Pin isolation, release the latch so the data can be over written with what SIO tells it
    sio_hw->gpio_oe_set = LED_MASK; // Set the LED pin as output

    bool on = false;

    while (1){

        sio_hw->gpio_togl = LED_MASK; // Toggle the output bit
        on = !on;
        printf("%s\n", on ? "ON" : "off");
        sleep_ms(BLINK_DELAY_MS);
    }
}


int main(void)
{
    stdio_init_all();
    reg_edit_blink();
}