This is suddle, a basic thingum I have contrived to demonstrate SDL to myself. I'm pretty sure I followed the beginning of https://lazyfoo.net/tutorials/SDL/ because I found https://www.parallelrealities.co.uk/tutorials/ over-architected. Unfortunately, lazy foo is also overarchitected.

Things are pretty rough in this project because I just want to make games, man. However, because I don't waste your time building my own abstractions, this source file might be a passable SDL tutorial for a C programmer.

Unfortunately, the process to install SDL dependencies is pretty confusing: I guess it's just https://github.com/libsdl-org/SDL/blob/main/docs/README-linux.md#build-dependencies

sudo apt-get install build-essential git make cmake autoconf automake libtool pkg-config libasound2-dev libpulse-dev libaudio-dev libjack-dev libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxi-dev libxinerama-dev libxxf86vm-dev libxss-dev libgl1-mesa-dev libdbus-1-dev libudev-dev libgles2-mesa-dev libegl1-mesa-dev libibus-1.0-dev fcitx-libs-dev libsamplerate0-dev libsndio-dev libwayland-dev libxkbcommon-dev libdrm-dev libgbm-dev libsdl2-ttf-dev #libsdl2-ttf-dev is for the SDL_ttf extension.

on my WSL, but I still don't know how to make a static exe or elf out of them...

I place this project into the public domain. NOTE: SDL and its ilk are not in the public domain. I think they're under a zlib license, though, so that's cool.

All typefaces are public domain in the US. However, font files are possibly not public domain, and also countries other than the US exist, so I have selected the public domain font Black Chancery to serve as the example font for this project.