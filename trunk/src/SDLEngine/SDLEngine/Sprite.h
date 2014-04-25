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
		Sprite(const std::string& path);
		Sprite(const std::string& path, int x, int y);
		Sprite(const std::string& path, int x, int y, int w, int h);
		Sprite(const std::string& path, const SDL_Rect& rect);

		Sprite(SDL_Texture* tex);
		Sprite(SDL_Texture* tex, int x, int y);
		Sprite(SDL_Texture* tex, int x, int y, int w, int h);
		Sprite(SDL_Texture* tex, const SDL_Rect& rect);
		
		virtual ~Sprite();

		void SetTexture(const std::string& path)
		{
			tex = Resources::GetInstance()->GetTexture(path);
		}

		void Start();
		void Update(unsigned int t);
		void Draw();
		void Stop();

	protected:
		void ApplySurface(SDL_Texture* texture, SDL_Renderer* renderer);
		SDL_Texture* tex;
};