#pragma once

#include <cstdint>
#include <algorithm>

struct RGBA {
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
    std::uint8_t a = 255;
};

// You are not required to use this struct when completing the lab,
// but could find it useful if you'd like an intermediate representation
// of your pixels as float values (which, notably, may exceed 255).
struct RGBAf {
    float r;
    float g;
    float b;
    float a = 255.f;

    RGBA toRGBA() {
        RGBA result;
        result.r = std::uint8_t(std::clamp(r,0.f,255.f));
        result.g = std::uint8_t(std::clamp(g,0.f,255.f));
        result.b = std::uint8_t(std::clamp(b,0.f,255.f));
        result.a = std::uint8_t(std::clamp(a,0.f,255.f));
        return result;
    }

    static RGBAf fromRGBA(RGBA pixel) {
        return RGBAf{float(pixel.r),float(pixel.g),float(pixel.b),float(pixel.a)};
    }
};
