#ifndef __COLOUR_H_
#define __COLOUR_H_

#include <libtcod.hpp>

struct Colour;

struct HSVColour {
    float H, S, V;
    Colour toRGB();
};

struct Colour {
    float r, g, b;
    TCOD_ColorRGB toColor() {
        return TCOD_ColorRGB({(uint8_t) (255.0f * r), (uint8_t) (255.0f * g), (uint8_t) (255.0f * b)});
    }

    HSVColour toHSV();
    void shift(float s); 
};

#endif