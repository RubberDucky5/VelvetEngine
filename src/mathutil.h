#pragma once

class Vec2 {
    public:
        int x,y;
        Vec2(int x, int y);

        Vec2 add(Vec2 *a);
        void _log();
};