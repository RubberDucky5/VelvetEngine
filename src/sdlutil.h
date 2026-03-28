#pragma once
#include "mathutil.h"
#include <cstdint>


void tline(void* pixels, int pitch, Vec2 p1, Vec2 p2, uint32_t color);
void tpixel(void* pixels, int pitch, Vec2 p, uint32_t color);