#include "init.h"
#include "Simple-SDL2-Audio/src/audio.h"

#define WIDTH 640
#define HEIGHT 480

SDL_Rect ball;
int dx, dy;

void play_bounce(void)
{
   playSoundFromMemory(ctx.sfx, SDL_MIX_MAXVOLUME / 2);
}

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

   /* Initial speed */
   dx = 1;
   dy = 2;

   /* Start playing background music */
   //playMusicFromMemory(ctx.music, SDL_MIX_MAXVOLUME);

   /* Run main_loop. -1 = let browser decide framerate. */
   emscripten_set_main_loop(main_loop, -1, 1);

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
