#pragma once

/**
* @file Resources.h
* @brief Todo
*/

#include "Common.h"

// Engine includes
#include "Engine.h"

class Resources
{
	public:
		#pragma region SINGLETON
		static Resources* GetInstance()
		{
			if (instance == NULL)
			{
				instance = new Resources();
			}

			return instance;
		}

		static void Kill()
		{
			if (instance)
			{
				delete instance;
				instance = NULL;
			}
		}

	private:
		 Resources();
		 Resources(const Resources& other);
		~Resources();

		Resources& operator= (const Resources& other);
		static Resources* instance;
		#pragma endregion

	public:
		SDL_Texture* GetTexture(std::string path);

	private:
		SDL_Texture* LoadImage(std::string path, SDL_Renderer* renderer);
		std::map<std::string, SDL_Texture*> loadedTextures;
};