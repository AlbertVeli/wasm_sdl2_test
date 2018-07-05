#include <SDL2/SDL.h>
#include "init.h"

context ctx;

void init(int w, int h)
{
  SDL_Window *window;
  SDL_Renderer *renderer;

  /* Init Video */
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    SDL_Quit();
  }

  window = SDL_CreateWindow("wasm_sdl2_test", SDL_WINDOWPOS_UNDEFINED,
			    SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
  if (!window) {
    SDL_Log("Unable to create SDL window: %s", SDL_GetError());
    SDL_Quit();
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    SDL_Log("Unable to create SDL renderer: %s", SDL_GetError());
    SDL_DestroyWindow(ctx.window);
    SDL_Quit();
  }

  ctx.window = window;
  ctx.renderer = renderer;
  ctx.quit = 0;

  /* Init Audio */
  initAudio();
  /* Preload audio samples */
  //ctx.music = createAudio("assets/highlands.wav", 1, SDL_MIX_MAXVOLUME);
  ctx.sfx = createAudio("assets/bounce.wav", 0, SDL_MIX_MAXVOLUME / 2);
}

void cleanup(void)
{
  endAudio();
  freeAudio(ctx.sfx);
  //freeAudio(ctx.music);
  SDL_DestroyRenderer(ctx.renderer);
  SDL_DestroyWindow(ctx.window);
  SDL_Quit();
}


/**
 * Local Variables:
 * mode: c
 * indent-tabs-mode: nil
 * c-basic-offset: 3
 * End:
 */
