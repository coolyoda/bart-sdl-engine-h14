#include "Resources.h"

Resources* Resources::instance = NULL;

Resources::Resources()
{
}

Resources::~Resources()
{
	{
		// cleanup textures resources
		std::map<std::string, SDL_Texture*>::iterator iter = loadedTextures.begin();
		while (iter != loadedTextures.end())
		{
			SDL_DestroyTexture(iter->second);
			iter++;
		}
	}

	{
		// cleanup fonts resources
		std::map<std::string, TTF_Font*>::iterator iter = loadedFonts.begin();
		while (iter != loadedFonts.end())
		{
			TTF_CloseFont(iter->second);
			iter++;
		}
	}

	loadedTextures.clear();
	loadedFonts.clear();
}

SDL_Texture* Resources::GetTexture(const std::string& path)
{
	if (loadedTextures[path] == NULL) {
		loadedTextures[path] = LoadImage(path, Engine::GetInstance()->GetRenderer());
	}

	return loadedTextures[path];
}

TTF_Font* Resources::GetFont(const std::string& path, int size)
{
	std::string abs = StringConcat() << path << size;

	if (loadedFonts[abs] == NULL) {
		loadedFonts[abs] = LoadFont(path, size, Engine::GetInstance()->GetRenderer());
	}

	return loadedFonts[abs];
}

SDL_Texture* Resources::LoadImage(const std::string& path, SDL_Renderer* renderer)
{
	SDL_Texture* loadedImage = NULL;
	loadedImage = IMG_LoadTexture(renderer, path.c_str());
	if (loadedImage == NULL)
	{
		std::cout << "Failed to load image '" + path + "' : " + IMG_GetError() << std::endl;
	}

	return loadedImage;
}

TTF_Font* Resources::LoadFont(const std::string& path, int size, SDL_Renderer* renderer)
{
	TTF_Font* loadedFont = NULL;
	loadedFont = TTF_OpenFont(path.c_str(), size);
	if (loadedFont == NULL)
	{
		std::cout << "Failed to load font '" + path + "' : " + TTF_GetError();
	}

	return loadedFont;
}