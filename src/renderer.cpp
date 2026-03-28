#include "renderer.h"

Scene::Scene (SDL_Renderer* _renderer, Vec2 window_size) { 
    renderer = _renderer;
    render_target = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, window_size.x, window_size.y);
}

void Scene::render (const bool* keys) {
    SDL_SetRenderDrawColor(this->renderer, 50, 50, 75, 255);
    SDL_RenderClear(this->renderer);

    if(keys[SDL_SCANCODE_SPACE]) {    
        SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
    } else{
        SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, 255);
    }

    for(int i = 300; i< 500; i++) {
        SDL_RenderLine(this->renderer, i,200,i,400);
    }

    // void *pixels;
    // int pitch;
    // SDL_LockTexture(render_target, NULL, &pixels, &pitch);

    // SDL_UnlockTexture(render_target);
    // SDL_RenderTexture(renderer, render_target, NULL, NULL);
}