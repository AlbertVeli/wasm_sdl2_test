/************************************************************
 *                                                        ***
 *   ~~=) All Rights Reversed - No Rights Reserved (=~~   ***
 *                                                        ***
 * Sweetmorn, the 40th day of Confusion in the YOLD 3184  ***
 *                                                        ***
 * Albert Veli                                            ***
 ************************************************************/

/* Btw, here is the main functions for the project.
 * The other files have helper functions that are called from here.
 */

#include "init.h"
#include "audio.h"

#define WIDTH 640
#define HEIGHT 480

SDL_Rect ball;
int dx, dy;

/* Render each frame */
void render(void)
{
   SDL_Renderer *renderer = ctx.renderer;

   /* Clear to background */
   SDL_SetRenderDrawColor(renderer, 0x00, 0x80, 0x00, 0xff);
   SDL_RenderClear(renderer);

   SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
   SDL_RenderFillRect(renderer, &ball);

   SDL_RenderPresent(renderer);
}

/* Called as fast as the browser wants, typically at 60 Hz */
void main_loop(void)
{
   SDL_Event event;

   /* Check events */
   while (SDL_PollEvent(&event)) {
      switch (event.type) {

      case SDL_QUIT:
         /* No easy way to quit emscripten main loop */
         ctx.quit = 1;
         break;

      case SDL_KEYDOWN:
         /* Use arrow keys to change ball speed */
         switch (event.key.keysym.sym) {

         case SDLK_UP:
            dy -= 1;
            break;

         case SDLK_DOWN:
            dy += 1;
            break;

         case SDLK_LEFT:
            dx -= 1;
            break;

         case SDLK_RIGHT:
            dx += 1;
            break;
         }
         break;
      }
   }

   /* Calculate new ball position */
   ball.x += dx;
   if ((ball.x + ball.w >= WIDTH) || ball.x <= 0) {
      /* Reverse x direction and play sfx */
      dx = -dx;
      play_bounce();
   }

   ball.y += dy;
   if ((ball.y + ball.h >= HEIGHT) || ball.y <= 0){
      /* Reverse y direction and play sfx */
      dy = -dy;
      play_bounce();
   }

   /* Render */
   render();
}

int main(void)
{
   /* Init uglyness hidden away in init.c */
   init(WIDTH, HEIGHT);

   /* Initial ball position */
   ball.w = 50;
   ball.h = 50;
   ball.x = WIDTH / 2 - ball.w / 2;
   ball.y = HEIGHT / 2 - ball.h / 2;

   /* Initial ball speed */
   dx = 1;
   dy = 2;

   /* Start playing background music */
   play_bgmusic();

   /* Run main_loop. -1 = let browser decide framerate. */
   emscripten_set_main_loop(main_loop, -1, 1);

   /* Free memory etc. This will never be called when using emscripten.
    * Not sure what happens when user closes tab in web client.
    * But when compiling as a native SDL2 program this would cleanup everything.
    */
   cleanup();

   return 0;
}


/**
 * Local Variables:
 * mode: c
 * indent-tabs-mode: nil
 * c-basic-offset: 3
 * End:
 */
