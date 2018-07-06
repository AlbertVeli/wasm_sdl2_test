/************************************************************
 *                                                        ***
 *   ~~=) All Rights Reversed - No Rights Reserved (=~~   ***
 *                                                        ***
 * Sweetmorn, the 40th day of Confusion in the YOLD 3184  ***
 *                                                        ***
 * Albert Veli                                            ***
 ************************************************************/

/* Initialization and cleanup routines. */

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

   if (SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer)) {
      SDL_Log("Unable to create SDL window/renderer: %s", SDL_GetError());
      SDL_Quit();
   }

   ctx.window = window;
   ctx.renderer = renderer;
   ctx.quit = 0;

   /* Init Audio */
   ctx.audio_on = init_audio();
}

void cleanup(void)
{
   cleanup_audio();
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
