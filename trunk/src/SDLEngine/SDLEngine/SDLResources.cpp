#include "SDLResources.h"

SDLResources* SDLResources::instance = nullptr;

SDLResources::SDLResources()
{
	loadedTextures = std::map<std::string, SDL_Texture*>();
}

SDLResources::~SDLResources()
{
	std::map<std::string, SDL_Texture*>::iterator iter = loadedTextures.begin();
	while (iter != loadedTextures.end())
	{
		SDL_DestroyTexture( iter->second );
		iter++;
	}

	loadedTextures.clear();
}

SDL_Texture* SDLResources::GetTexture(std::string fileName)
{
	if (loadedTextures[fileName] == nullptr)
	{
		loadedTextures[fileName] = LoadImage(fileName, SDLEngine::GetInstance()->GetRenderer());
	}
	return loadedTextures[fileName];
}

SDL_Texture* SDLResources::LoadImage(std::string file, SDL_Renderer* renderer)
{
	SDL_Texture* loadedImage = nullptr;
	loadedImage = IMG_LoadTexture(renderer, file.c_str());
	if (loadedImage == nullptr)
	{
		throw std::runtime_error("Failed to load image: " + file + IMG_GetError());
	}
	return loadedImage;
}
