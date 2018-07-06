/************************************************************
 *                                                        ***
 *   ~~=) All Rights Reversed - No Rights Reserved (=~~   ***
 *                                                        ***
 *  Boomtime, the 41st day of Confusion in the YOLD 3184  ***
 *                                                        ***
 * Albert Veli                                            ***
 ************************************************************/

/* Audio API. Uses SDL_mixer. */

#include "audio.h"

typedef enum {
   SFX_BOUNCE,
   MAX_SFX_INDEX
} SfxIndex;


static Mix_Chunk *g_sfx[MAX_SFX_INDEX] = { NULL };

typedef enum {
   MUSIC_HIGHLANDS,
   MAX_MUSIC_INDEX
} MusicIndex;

static Mix_Music *g_music[MAX_MUSIC_INDEX] = { NULL };

static Mix_Chunk *load_sfx(char *filename)
{
   Mix_Chunk *sfx = Mix_LoadWAV_RW(SDL_RWFromFile(filename, "rb"), 1);
   if (!sfx) {
      SDL_Log("Mix_LoadWAV_RW: %s", Mix_GetError());
      return NULL;
   }

   return sfx;
}

static Mix_Music *load_music(char *filename)
{
   Mix_Music *music = Mix_LoadMUS_RW(SDL_RWFromFile(filename, "rb"));
   if (!music) {
      SDL_Log("Mix_LoadMUS: %s", Mix_GetError());
      return NULL;
   }

   return music;
}

static void play_sfx(Mix_Chunk *sfx)
{
   Mix_PlayChannel(-1, sfx, 0);
}

static void play_music(Mix_Music *music)
{
   if (Mix_PlayMusic(music, -1) == -1) {
      SDL_Log("Mix_PlayMusic: %s\n", Mix_GetError());
   }
}

/* --- Exported functions -- */

void play_bounce(void)
{
   if (g_sfx[SFX_BOUNCE]) {
      play_sfx(g_sfx[SFX_BOUNCE]);
   }
}

void play_bgmusic(void)
{
   if (g_music[MUSIC_HIGHLANDS]) {
      play_music(g_music[MUSIC_HIGHLANDS]);
   }
}

/* Return 0 ok, 1 not ok */
int init_audio(void)
{
   /* Init SDL_Mixer */
   if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
      SDL_Log("SDL_mixer init error %s", Mix_GetError());
      return 0;
   }

   /* Load sound assets */
   g_sfx[SFX_BOUNCE] = load_sfx("assets/bounce.ogg");
   if (!g_sfx[SFX_BOUNCE]) {
      Mix_CloseAudio();
      return 0;
   }
   /* 50% volume */
   /* Mix_VolumeChunk not implemented */
   /* Mix_VolumeChunk(g_sfx[SFX_BOUNCE], MIX_MAX_VOLUME / 2); */

   g_music[MUSIC_HIGHLANDS] = load_music("assets/highlands.ogg");
   /* Ignore if bgmusic doesn't load */

   return 1;
}

void cleanup_audio(void)
{
   int i;

   for (i = 0; i < MAX_SFX_INDEX; i++) {
      if (g_sfx[i]) {
         Mix_FreeChunk(g_sfx[i]);
         g_sfx[i] = NULL;
      }
   }

   for (i = 0; i < MAX_MUSIC_INDEX; i++) {
      if (g_music[i]) {
         Mix_FreeMusic(g_music[i]);
         g_music[i] = NULL;
      }
   }

   Mix_CloseAudio();
}


/**
 * Local Variables:
 * mode: c
 * indent-tabs-mode: nil
 * c-basic-offset: 3
 * End:
 */
