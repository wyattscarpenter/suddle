#include "SDL.h"
#include <stdio.h>

int main(int argc, char** argv){
	puts("Hello.");
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("SDL_Init Error: %s", SDL_GetError());
		return 1;
	}
	SDL_Window *window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (!window){
		printf("SDL_CreateWindow Error: %s", SDL_GetError());
		return 1;
	}
	//Get window surface
            SDL_Surface* screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds
            SDL_Delay( 20000 );
	puts("Goodbye.");
	return 0;
}
