#include "renderer.h"

void Camera::render_tri (SDL_Renderer* renderer, Triangle tri) {
    for(int i = 300; i< 500; i++) {
        SDL_RenderLine(renderer, i,200,i,400); // Add in triangle renderer
    }
}

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

    Triangle t = Triangle(Vec3(100, 100, 0), Vec3(100, 400, 0), Vec3(400, 400, 0));

    this->camera->render_tri(this->renderer, t);

    // void *pixels;
    // int pitch;
    // SDL_LockTexture(render_target, NULL, &pixels, &pitch);

    // SDL_UnlockTexture(render_target);
    // SDL_RenderTexture(renderer, render_target, NULL, NULL);
}