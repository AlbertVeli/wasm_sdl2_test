#ifndef __AUDIO_H
#define __AUDIO_H

/************************************************************
 *                                                        ***
 *   ~~=) All Rights Reversed - No Rights Reserved (=~~   ***
 *                                                        ***
 *  Boomtime, the 41st day of Confusion in the YOLD 3184  ***
 *                                                        ***
 * Albert Veli                                            ***
 ************************************************************/

#include <emscripten.h>
#include <SDL2/SDL.h>
#include <SDL/SDL_mixer.h>

void play_bounce(void);
void play_bgmusic(void);
int init_audio(void);
void cleanup_audio(void);

/**
 * Local Variables:
 * mode: c
 * indent-tabs-mode: nil
 * c-basic-offset: 3
 * End:
 */

#endif /* __AUDIO_H */
