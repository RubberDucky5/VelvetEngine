#include <SDL3/SDL.h>
#include "mathutil.h"

class Camera {
    public:
        Mat4 transform;

        void render_tri (SDL_Renderer* renderer, Triangle tri);

        Camera() {transform = Mat4();};
};

class Scene {
    public: 
        SDL_Renderer* renderer;

        Camera* camera;

        Scene (SDL_Renderer* _renderer, Vec2 window_size);
        void render (const bool* keys);
    private:
        SDL_Texture* render_target;
};