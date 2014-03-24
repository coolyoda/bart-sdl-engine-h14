#pragma once

#include <map>
#include "SDLEngine.h"

class SDLResources
{
#pragma region SINGLETON
public:
	static SDLResources* GetInstance()
	{
		if (instance == nullptr)
			instance = new SDLResources();
		return instance;
	}
	static void Kill()
	{
		delete instance;
		instance = nullptr;
	}
private:
	static SDLResources* instance;
	SDLResources();
	SDLResources(const SDLResources& e);
	~SDLResources();
	SDLResources& operator= (const SDLResources& e);
#pragma endregion
public:
	SDL_Texture* GetTexture(std::string fileName);

private:
	std::map<std::string, SDL_Texture*> loadedTextures;
	SDL_Texture* LoadImage(std::string file, SDL_Renderer* renderer);
};

