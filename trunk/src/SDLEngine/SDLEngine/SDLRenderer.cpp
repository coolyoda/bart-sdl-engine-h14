#include "SDLRenderer.h"

using namespace std;

SDLRenderer::SDLRenderer(SDL_Window* win)
{
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;
	}
}

SDLRenderer::~SDLRenderer()
{
	SDL_DestroyRenderer(ren);
}

void SDLRenderer::Clear()
{
	SDL_RenderClear(ren);
}

void SDLRenderer::Present()
{
	SDL_RenderPresent(ren);
}