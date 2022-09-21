#include "Colour.hpp"

#include <cmath>

Colour HSVColour::toRGB() {
    float C = S * V;
    float Hp = H / 60.0f;
    float X = C * (1 - abs(fmod(Hp, 2) - 1));
    Colour rgb = {0.0f, 0.0f, 0.0f};
    if (0 <= Hp && Hp < 1) {
        rgb = {C, X, 0};
    } else if (1 <= Hp && Hp < 2) {
        rgb = {X, C, 0};
    } else if (2 <= Hp && Hp < 3) {
        rgb = {0, C, X};
    } else if (3 <= Hp && Hp < 4) {
        rgb = {0, X, C};
    } else if (4 <= Hp && Hp < 5) {
        rgb = {X, 0, C};
    } else {
        rgb = {C, 0, X};
    }
    float m = V - C;
    return {rgb.r + m, rgb.g + m, rgb.b + m};
}

HSVColour Colour::toHSV() {
    float V = std::max({r, g, b});
    float Xmin = std::min({r, g, b});
    float C = V - Xmin;
    float H;
    if (C == 0) {
        H = 0;
    } else if (V == r) {
        H = 60.0f * (0 + (g - b) / C);
    } else if (V == g) {
        H = 60.0f * (2 + (b - r) / C);
    } else {
        H = 60.0f * (2 + (r - g) / C);
    }
    float S;
    if (V == 0) {
        S = 0;
    } else {
        S = C / V;
    }
    return {H, S, V};
}

void Colour::shift(float s) {
    TCODRandom *rng = TCODRandom::getInstance();
    //r = (uint8_t) ((float) r) * rng->getFloat(1.0f-s, 1.0f+s);
    //g *= rng->getFloat(1.0f-s, 1.0f+s);
    //b *= rng->getFloat(1.0f-s, 1.0f+s);
    HSVColour hsv = toHSV();
    hsv.H *= rng->getFloat(1.0f-s, 1.0f+s);
    hsv.S *= rng->getFloat(1.0f-s, 1.0f+s);
    hsv.V *= rng->getFloat(1.0f-s, 1.0f+s);
    Colour rgb = hsv.toRGB();
    r = rgb.r;
    g = rgb.g;
    b = rgb.b;
}