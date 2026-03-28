#include "mathutil.h"
#include <iostream>

Vec2::Vec2(int _x, int _y) {
    x=_x;
    y=_y;
}

Vec2 Vec2::add(Vec2 *a) {
    return Vec2(this->x + a->x, this->y + a->y);
}

void Vec2::_log() {
    std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
}