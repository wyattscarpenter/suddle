#include "SDL.h"
#include <stdio.h>

int main(int argc, char** argv){
	puts("Hello.");
	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("SDL_Init Error: %s", SDL_GetError());
		return 1;
	}
	//now we create the window, which I have cleverly set to take up my entire screen
	SDL_Window *window = SDL_CreateWindow("Hello World!", 0, 0, 1920, 1080, SDL_WINDOW_SHOWN);
	if (!window){
		printf("SDL_CreateWindow Error: %s", SDL_GetError());
		return 1;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer){
		printf("SDL_CreateRendererError: %s", SDL_GetError());
		return 1;
	}
	//Get window surface
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	//Fill the surface white
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0xFF));
	//Update the surface
	SDL_UpdateWindowSurface(window);
	//Wait second
	SDL_Delay(1000);
	SDL_Surface *testman = SDL_LoadBMP("test.bmp");
	if(!testman){
		printf("no testman :/ SDL_LoadBMP Error: %s", SDL_GetError());
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, testman);
	SDL_FreeSurface(testman);
	if(!texture){
		printf("SDL_CreateTextureFromSurface Error: %s", SDL_GetError());
	}
  
  //SDL_BlitSurface(testman, NULL, screenSurface, NULL );
  //SDL_UpdateWindowSurface( window );
  //SDL_Delay(5000);
	for (int i = 0; i < 3; ++i){
		//clear renderer
		SDL_RenderClear(renderer);

		//draw texture
        const SDL_Rect fillRect = { 500 / 4, 500 / 4, 500 / 2, 500 / 2 };

		SDL_RenderCopy(renderer, texture, NULL, &fillRect);
    
    //SDL_SetRenderDrawColor( renderer, 0x00, 0xFF, 0x00, 0xFF ); 
    //SDL_RenderFillRect( renderer, &fillRect );
    
		//update screen
		SDL_RenderPresent(renderer);
		SDL_Delay(1000);
	}
	puts("Goodbye.");
	return 0;
}
