#include "renderer.h"

Scene::Scene (SDL_Renderer* _renderer, Vec2 window_size) { 
    renderer = _renderer;
    render_target = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, window_size.x, window_size.y);
}

void Scene::render () {
    SDL_SetRenderDrawColor(this->renderer, 50, 50, 75, 255);
    SDL_RenderClear(this->renderer);

    // void *pixels;
    // int pitch;
    // SDL_LockTexture(render_target, NULL, &pixels, &pitch);

    

    // SDL_UnlockTexture(render_target);
    // SDL_RenderTexture(renderer, render_target, NULL, NULL);
}