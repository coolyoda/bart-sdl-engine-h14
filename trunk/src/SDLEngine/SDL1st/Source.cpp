#include <iostream>
#include <stdexcept>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Texture* LoadImage(std::string file, SDL_Renderer* renderer);
void ApplySurface(int x, int y, SDL_Texture* texture, SDL_Renderer* renderer);

int main(int argc, char* argv[])
{
	SDL_Window* win = nullptr;
	SDL_Renderer* ren = nullptr;
	SDL_Texture* helloTex = nullptr;

	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	win = SDL_CreateWindow("Hello World"
		, SDL_WINDOWPOS_CENTERED
		, SDL_WINDOWPOS_CENTERED
		, SCREEN_WIDTH
		, SCREEN_HEIGHT
		, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
	if (win == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;
		return 2;
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;
		return 3;
	}

	helloTex = LoadImage("firefox.png", ren);

	SDL_RenderClear(ren);

	ApplySurface(0, 0, helloTex, ren);

	SDL_RenderPresent(ren);

	SDL_Delay(2000);

	SDL_DestroyTexture(helloTex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	SDL_Quit();
	return 0;
}

SDL_Texture* LoadImage(std::string file, SDL_Renderer* renderer)
{
	SDL_Texture* loadedImage = nullptr;
	loadedImage = IMG_LoadTexture(renderer, file.c_str());
	if (loadedImage == nullptr)
	{
		throw std::runtime_error("Failed to load image: " + file + IMG_GetError());
	}
	return loadedImage;
}
void ApplySurface(int x, int y, SDL_Texture* texture, SDL_Renderer* renderer)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	SDL_QueryTexture(texture, 0, 0, &rect.w, &rect.h);
	SDL_RenderCopy(renderer, texture, 0, &rect);
}