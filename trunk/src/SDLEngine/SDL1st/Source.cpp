#include <iostream>
#include <stdexcept>
#include <string>
#include "SDL.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
	SDL_Window* win = nullptr;
	SDL_Renderer* ren = nullptr;
	SDL_Texture* helloTex = nullptr;

	SDL_Init(SDL_INIT_EVERYTHING);

	win = SDL_CreateWindow("Hello World"
		, SDL_WINDOWPOS_CENTERED
		, SDL_WINDOWPOS_CENTERED
		, SCREEN_WIDTH
		, SCREEN_HEIGHT
		, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);

	SDL_Delay(2000);

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	return 0;
}