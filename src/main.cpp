/*
  Copyright (C) 1997-2026 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely.
*/
#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#define WIDTH 800
#define HEIGHT 600

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

static SDL_Texture *render_target;

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    /* Create the window */
    if (!SDL_CreateWindowAndRenderer("Velvet Engine", WIDTH, HEIGHT, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window and/or renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    render_target = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

    return SDL_APP_CONTINUE;
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    void *pixels;
    int pitch;
    SDL_LockTexture(render_target, NULL, &pixels, &pitch);

    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        *((Uint32*)pixels + i) = 0xFF0000FF;
    }

    SDL_UnlockTexture(render_target);
    SDL_RenderTexture(renderer, render_target, NULL, NULL);

    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
}