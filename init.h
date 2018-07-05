#ifndef __INIT_H
#define __INIT_H

#include <SDL2/SDL.h>
#include <emscripten.h>
#include "Simple-SDL2-Audio/src/audio.h"

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
  #include "Simple-SDL2-Audio/src/audio.h"
  Audio *music;
  Audio *sfx;
  int quit;
} context;

extern context ctx;

void init(int w, int h);
void cleanup(void);

#endif /* __INIT_H */
