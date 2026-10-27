#ifndef SNAKE_H
#define SNAKE_H
#include <stdint.h>
#include "layout.h"

#define SNAKE_BODY_MAX_SIZE ( PLAY_WIDTH * PLAY_HEIGHT )

typedef struct position {
    uint8_t x;
    uint8_t y;
}pos_t;

typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} direction_t;

typedef enum{
    STATE_PLAYING,
    STATE_WON,
    STATE_LOST
}state_t;

typedef struct snake {
    pos_t body[MAX_SIZE];
    uint16_t head;
    uint16_t tail;
    uint16_t snake_size;
    uint16_t score;
    direction_t dir;
    state_t state;
    pos_t food_pos;
    uint32_t seed;

}snake_t;

#endif /*SNAKE_H*/