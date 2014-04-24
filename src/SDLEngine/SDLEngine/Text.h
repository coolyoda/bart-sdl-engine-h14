#pragma once

/**
* @file Text.h
* @brief Todo
*/

#include "Common.h"

// Engine includes
#include "Resources.h"
#include "Component.h"

class Text : public Component
{
	public:
		Text();
		Text(const std::string& path, int size, int x, int y);
		virtual ~Text();

		void Update(unsigned int t);
		void Draw();
		void Stop();

		void SetFont(const std::string& path, int size);
		void SetText(const std::string& text,
			int r=255,
			int g=255,
			int b=255,
			int a=255
		);

	private:
		void ApplySurface(SDL_Texture* texture, SDL_Renderer* renderer);
		SDL_Texture* tex;

	protected:
		TTF_Font* fon;
};