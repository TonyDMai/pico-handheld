#include "buttons.h"
#include "pico/stdlib.h"
#include "hardware/structs/sio.h"
#include "hardware/structs/io_bank0.h"
#include "hardware/structs/pads_bank0.h"

#define VALID_STABLE_COUNT 4

static uint8_t held_state = 0x00;
static uint8_t btn_pressed = 0x00;

void buttons_init(void){
    for (uint8_t i = 0; i < BTN_COUNT; i++ ){
        pads_bank0_hw->io[PIN_BTN_FIRST + i] |= PADS_BANK0_GPIO0_IE_BITS; // Bit 6 is the Input Enable bit which is what this constant is 0x0000 0040
        pads_bank0_hw->io[PIN_BTN_FIRST + i] |= PADS_BANK0_GPIO0_OD_BITS; // Disable writing to this pin
        pads_bank0_hw->io[PIN_BTN_FIRST + i] |=  PADS_BANK0_GPIO0_PUE_BITS; // Enable pull up resisters since buttons are active low, Activate on press sets it to "0"
        pads_bank0_hw->io[PIN_BTN_FIRST + i] &= ~PADS_BANK0_GPIO0_PDE_BITS; // Disable pull down resisters
        io_bank0_hw->io[PIN_BTN_FIRST + i].ctrl = GPIO_FUNC_SIO << IO_BANK0_GPIO0_CTRL_FUNCSEL_LSB; // set as default GPIO
        pads_bank0_hw->io[PIN_BTN_FIRST + i] &= ~PADS_BANK0_GPIO0_ISO_BITS;// clears the isolation bit, "attaching itself back to logic", lets changes from the logic be written onto the pin
    }

    sio_hw->gpio_oe_clr = BTN_GPIO_MASK;
}

void buttons_update(void){
    static uint8_t stable_count = 0;
    static uint8_t prev_raw_input = 0x00;

    uint8_t in = (uint8_t)~( ( sio_hw->gpio_in >> PIN_BTN_FIRST ) & BTN_MASK_ALL );

    if (in == prev_raw_input ){
        if (stable_count < VALID_STABLE_COUNT){
            stable_count++;
        }
    }
    else {
        stable_count = 0;
        prev_raw_input = in;
    }

    if (stable_count >= VALID_STABLE_COUNT){
        uint8_t old_held_state = held_state;
        held_state = in;
        btn_pressed = held_state & ~old_held_state;
    } else {
        btn_pressed = 0;
    }

}

uint8_t buttons_held(void){
    return held_state;
}

uint8_t buttons_pressed(void){
    return btn_pressed;
}