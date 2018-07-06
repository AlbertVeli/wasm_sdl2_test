# Small test of WebAssembly with SDL2

A ball is bouncing around the canvas while background music is played. A sound effect played when the ball hits a wall.

Checkout the [Demo](https://albertveli.github.io/wasm_sdl2_test/).

## Requirements
* [Emscripten SDK](https://webassembly.org/getting-started/developers-guide/)
* git

## Build
* Checkout project: `git clone --recursive https://github.com/AlbertVeli/wasm_sdl2_test`
* `cd wasm_sdl2_test`
* `make`

## Test locally on port 8080
* `python -m SimpleHTTPServer 8080`
* or `emrun --no_browser --port 8080 .` (add --emrun to linker flags to run this way)
* Visit http://localhost:8080/

## Resources
* [Audio API](https://www.libsdl.org/projects/SDL_mixer/release-1.2.html) - Emscripten only supports SDL\_mixer 1. Can be used together with SDL2.
*  https://github.com/timhutton/sdl-canvas-wasm - Even more minimal example than this

## Notes
* I only got file loading to work together with emscripten by adding --preload-file to CFLAGS. This in turn only works with the `_RW` versions of the load files. Like `Mix_LoadWAV_RW(SDL_RWFromFile("assets/bounce.ogg", "rb"), 1);`.
* To preload all files in the assets directory `--preload-file assets` is added to CFLAGS (in Makefile).
* Ogg vorbis support is added automatically to SDL\_mixer by adding `-s USE_OGG=1 -s USE_VORBIS=1` to CFLAGS.

[//]: # (Discordian version of the MIT license)
## License

    ~~=) All Rights Reversed - No Rights Reserved (=~~

Boomtime, the 41st day of Confusion in the YOLD 3184

Albert Veli
