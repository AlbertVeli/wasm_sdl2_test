# Small test of WebAssembly with SDL2

A ball is bouncing on the canvas walls while background music is played. A sound is played when the ball hits a wall. Exit by closing the tab in the browser.

At the moment I disabled the background music because of some strange sound bug. The bounce sound effect kind of works but also sounds distorted.

## Requirements
* [Emscripten SDK](https://webassembly.org/getting-started/developers-guide/)
* git

## Build
* Checkout project: `git clone --recursive https://github.com/AlbertVeli/wasm_sdl2_test`
* `cd wasm_sdl2_test`
* `make`

## Test locally on port 8080
* `python -m SimpleHTTPServer 8080`
* or `emrun --no_browser --port 8080 .`
* Visit http://localhost:8080/

## Resources
* [Audio API](https://github.com/jakebesworth/Simple-SDL2-Audio) - Plays at most 1 music sample and 1 sound sample simultaneously, without SDL\_mixer.
*  https://github.com/timhutton/sdl-canvas-wasm - Even more minimal example than this

[//]: # (Discordian version of the MIT license)
## License

    ~~=) All Rights Reversed - No Rights Reserved (=~~

Sweetmorn, the 40th day of Confusion in the YOLD 3184

Albert Veli
