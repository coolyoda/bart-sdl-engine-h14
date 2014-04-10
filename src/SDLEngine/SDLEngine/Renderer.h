#pragma once

/**
* @file Renderer.h
* @brief Todo
*/

#include "Common.h"

class Renderer
{
	public:
		Renderer::Renderer(SDL_Window* window);
		~Renderer();

		void SetResolution(int w, int h)
		{
			this->w = w;
			this->h = h;
		}

		SDL_Renderer* GetRenderer() const { return ren; }
		int GetW() const { return w; }
		int GetH() const { return h; }

		// Services
		void Clear(int r=0, int g=0, int b=0, int a=255);
		void Display();

	private:
		SDL_Renderer* ren;
		int w, h;
};