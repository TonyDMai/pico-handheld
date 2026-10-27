#include "buttons.h"
#include "pico/stdlib.h"
#include "hardware/structs/sio.h"
#include "hardware/structs/io_bank0.h"
#include "hardware/structs/pads_bank0.h"

void buttons_init(void){
    for (uint8_t i = 0; i < BTN_COUNT; i++ ){
        pads_bank0_hw->io[PIN_BTN_FIRST + i] |= PADS_BANK0_GPIO0_IE_BITS; // Bit 6 is the Input Enable bit which is what this constant is 0x0000 0040
        pads_bank0_hw->io[PIN_BTN_FIRST + i] |= PADS_BANK0_GPIO0_OD_BITS; // Disable writing to this pin
        pads_bank0_hw->io[PIN_BTN_FIRST + i] |=  PADS_BANK0_GPIO0_PUE_BITS; // Enable pull up resisters since buttons are active low, Activate on press sets it to "0"
        pads_bank0_hw->io[PIN_BTN_FIRST + i] &= ~PADS_BANK0_GPIO0_PDE_BITS; // Disable pull down resisters
        io_bank0_hw->io[PIN_BTN_FIRST + i].ctrl = GPIO_FUNC_SIO << IO_BANK0_GPIO0_CTRL_FUNCSEL_LSB; // set as default GPIO
        pads_bank0_hw->io[PIN_BTN_FIRST + i] &= ~PADS_BANK0_GPIO0_ISO_BITS;// clears the isolation bit, "attaching itself back to the board", lets changes from the logic be written onto the pin
    }

    sio_hw->gpio_oe_clr = BTN_GPIO_MASK;
}