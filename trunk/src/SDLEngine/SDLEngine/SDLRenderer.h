#pragma once
#include <iostream>
#include "SDL.h"

class SDLRenderer
{
public:
	// Ctor / Dtor
	
	SDLRenderer::SDLRenderer(SDL_Window* win);
	~SDLRenderer();

	// Setters
	void SetResolution(int width, int height)
	{
		this->width = width;
		this->height = height;
	}

	// Getters
	SDL_Renderer* GetRenderer() const { return ren; }
	int GetWidth() const { return width; }
	int GetHeight() const { return height; }

	// Methods
	void Clear();
	void Present();

private:
	SDLRenderer();
	int width, height;
	SDL_Renderer* ren = nullptr;
};