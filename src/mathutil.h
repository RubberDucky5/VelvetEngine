#pragma once

class Vec2 {
    public:
        float x,y;
        Vec2(float x, float y);
        Vec2() {x=0;y=0;};

        Vec2 add(Vec2 *a);
        void log();
};

class Vec3 {
    public:
        float x,y,z;
        Vec3(float x, float y, float z);
        Vec3(float fill);
        Vec3() {x=0;y=0;z=0;};

        Vec3 add(Vec3 *a);

        void log();

};

class Mat3 {
    public:
        float n[9];

        Mat3(float matrix[9]);
        Mat3(float fill);
};

class Mat4 {
    public:
        float n[16];

        Mat4(float matrix[16]);
        Mat4(float fill);
        Mat4() = default;
};

class Triangle {
    public:
        Vec3 p[3];

        Triangle(Vec3 _p[3]);
        Triangle(Vec3 p1, Vec3 p2, Vec3 p3);

        void log();
};