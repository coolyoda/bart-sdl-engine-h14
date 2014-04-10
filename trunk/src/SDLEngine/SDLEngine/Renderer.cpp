#include "Renderer.h"

Renderer::Renderer(SDL_Window* window)
{
	ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
	}
}

Renderer::~Renderer()
{
	if (ren)
	{
		SDL_DestroyRenderer(ren);
		ren = NULL;
	}
}

void Renderer::Clear(int r, int g, int b, int a)
{
	SDL_SetRenderDrawColor(ren, r, g, b, a);
	SDL_RenderClear(ren);
}

void Renderer::Display()
{
	SDL_RenderPresent(ren);
}