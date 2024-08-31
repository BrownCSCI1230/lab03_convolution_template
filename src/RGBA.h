#pragma once

#include <cstdint>

struct RGBA {
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
    std::uint8_t a = 255;
};

struct RGBAf {
    // Task 7: Edit the field types so that they can represent intensity
    // values larger than 255!
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
    std::uint8_t a = 255;


    RGBA toRGBA() {
        RGBA result;

        // Task 8: Complete the toRGBA() function to clamp your float values and return a RGBA struct.

        return result;
    }

    static RGBAf fromRGBA(RGBA pixel) {
        // TODO: Uncomment after Task 7!
        // return RGBAf{ float(pixel.r), float(pixel.g), float(pixel.b), float(pixel.a) };
    }

};
