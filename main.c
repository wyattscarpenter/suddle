#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <stdio.h>

int SCREEN_WIDTH  = 1920;
int SCREEN_HEIGHT = 1080;


int main(int argc, char** argv){
	puts("Hello. Initiating...");
	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("SDL_Init Error: %s", SDL_GetError());
		return 1;
	}
	//now we create the window, which I have cleverly set to take up my entire screen
	SDL_Window *window = SDL_CreateWindow("Hello World!", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
  
  //input / render loop
  SDL_Event e;
  int manr = 0;
  int mand = 0;
  while( SDL_PollEvent( &e ), 1 ){
    //User requests quit. I guess this is from Xing out, which I've never seen in my setup, but it's here.
    if( e.type == SDL_QUIT ) {
      return 0;
    }
    //User presses a key
    else if( e.type == SDL_KEYDOWN ){
      //Select surfaces based on key press
      switch( e.key.keysym.sym )
      {
        case SDLK_ESCAPE:
        puts("ESC");
        return 0;
        break;

        case SDLK_UP:
        puts("U");
        break;

        case SDLK_DOWN:
        puts("D");
        mand++;
        break;

        case SDLK_LEFT:
        puts("L");
        break;

        case SDLK_RIGHT:
        puts("R");
        manr++;
        break;

        default:
        puts("!");
        break;
      }
    }
		//clear renderer
		SDL_RenderClear(renderer);

		//draw texture
    const SDL_Rect fillRect = { 500 / 4, 500 / 4, 500 / 2 + manr, 500 / 2 + mand}; //can stretch image right and down, as you might expect from this line.
		SDL_RenderCopy(renderer, texture, NULL, &fillRect);
    
    //draw text
    if( TTF_Init() == -1 ){
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        return 1;
    }
    TTF_Font *font = TTF_OpenFont("fonts/BLKCHCRY.TTF", 24 );
    if(!font){
      printf( "Unable to open font! SDL_ttf Error: %s\n", TTF_GetError() );
      return 1;
    }
    SDL_Color textColor = {100,100,100,100};
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, "foo", textColor );
    if( textSurface == NULL )
    {
      printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    } else {
      SDL_Texture *ttexture = SDL_CreateTextureFromSurface( renderer, textSurface );
      if(!ttexture){
        printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
      } else {
        //center print it using text-rendered w and h
        SDL_RenderCopy(renderer, ttexture, NULL, &(SDL_Rect){ (SCREEN_WIDTH - textSurface->w )/2, (SCREEN_HEIGHT - textSurface->h )/2, textSurface->w, textSurface->h});
      }
      //Get rid of old surface
      SDL_FreeSurface(textSurface);
    }
    
		//update screen
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
  }
	puts("Goodbye.");
	return 0;
}
