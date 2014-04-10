#include "Resources.h"

Resources* Resources::instance = NULL;

Resources::Resources()
{
}

Resources::~Resources()
{
	std::map<std::string, SDL_Texture*>::iterator iter = loadedTextures.begin();
	while (iter != loadedTextures.end())
	{
		SDL_DestroyTexture(iter->second);
		iter++;
	}

	loadedTextures.clear();
}

SDL_Texture* Resources::GetTexture(std::string fileName)
{
	if (loadedTextures[fileName] == NULL) {
		loadedTextures[fileName] = LoadImage(fileName, Engine::GetInstance()->GetRenderer());
	}

	return loadedTextures[fileName];
}

SDL_Texture* Resources::LoadImage(std::string file, SDL_Renderer* renderer)
{
	SDL_Texture* loadedImage = NULL;
	loadedImage = IMG_LoadTexture(renderer, file.c_str());
	if (loadedImage == NULL)
	{
		std::cout << "Failed to load image '" + file + "' : " + IMG_GetError();
	}

	return loadedImage;
}