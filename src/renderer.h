#include <SDL3/SDL.h>
#include "mathutil.h"

class Scene {
    public: 
        SDL_Renderer* renderer;
        
        Scene (SDL_Renderer* _renderer, Vec2 window_size);
        void render ();
    private:
        SDL_Texture* render_target;
};