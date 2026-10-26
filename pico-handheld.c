#include <stdio.h>
#include "pico/stdlib.h"

#define BLINK_DELAY_MS 250

int main()
{
    stdio_init_all();
    gpio_init(PICO_DEFAULT_LED_PIN); // init LED to GPIO equivalent to P1SEL0,1 IN MSP43XR
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT); //Set as output equivalent of P1DIR = |= BIT0;

    while (true) {

        gpio_put(PICO_DEFAULT_LED_PIN, 1);
        printf("ON\n");
        sleep_ms(BLINK_DELAY_MS);
        gpio_put(PICO_DEFAULT_LED_PIN, 0);
        printf("OFF\n");
        sleep_ms(BLINK_DELAY_MS);
    }
}
