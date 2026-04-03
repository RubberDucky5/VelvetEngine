#include "mathutil.h"
#include <iostream>

Vec2::Vec2(float _x, float _y) {
    x=_x;
    y=_y;
}

Vec2 Vec2::add(Vec2 *a) {
    return Vec2(this->x + a->x, this->y + a->y);
}

void Vec2::log() {
    std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
}

Vec3::Vec3(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
}

Vec3::Vec3(float fill) {
    x = fill;
    y = fill;
    z = fill;
}

void Vec3::log() {
    std::cout << "(" << this->x << ", " << this->y << ", " << this->z << ")" << std::endl;
}

Mat4::Mat4(float matrix[16]) {
    // n = matrix;
    memcpy(&n, &matrix, sizeof(float[16]));
}

Mat4::Mat4(float fill) {
    float matrix[16] = { [0 ... 15] = fill };
    memcpy(&n, &matrix, sizeof(float[16]));
}

Triangle::Triangle (Vec3 _p[3]) {
    memcpy(&p, &_p, sizeof(Vec3[3]));
}

Triangle::Triangle (Vec3 p1, Vec3 p2, Vec3 p3) {
    Vec3 _p[3] = { p1, p2, p3 };
    memcpy(&p, &_p, sizeof(Vec3[3]));
}

void Triangle::log() {
    this->p[0].log();
    this->p[1].log();
    this->p[2].log();
}