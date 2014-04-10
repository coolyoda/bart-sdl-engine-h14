#pragma once

/**
* @file Sprite.h
* @brief Todo
*/

#include "Common.h"

// Engine includes
#include "Resources.h"
#include "Collider.h"

class Sprite: public Collider
{
	public:
		Sprite();
		Sprite(std::string fileName);
		Sprite(std::string fileName, int x, int y);
		Sprite(std::string fileName, int x, int y, int w, int h);
		Sprite(std::string fileName, const SDL_Rect& rect);

		Sprite(SDL_Texture* tex);
		Sprite(SDL_Texture* tex, int x, int y);
		Sprite(SDL_Texture* tex, int x, int y, int w, int h);
		Sprite(SDL_Texture* tex, const SDL_Rect& rect);
		
		virtual ~Sprite();

		void Start();
		void Update();
		void Draw();
		void Stop();

	private:
		void ApplySurface(SDL_Texture* texture, SDL_Renderer* renderer);
		SDL_Texture* tex;
};