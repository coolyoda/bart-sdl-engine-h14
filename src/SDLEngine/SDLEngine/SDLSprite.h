#pragma once
#include "SDLComponent.h"
#include "SDLResources.h"

class SDLSprite :
	public SDLComponent
{
public:
	SDLSprite();
	SDLSprite(std::string fileName);
	SDLSprite(std::string fileName, int x, int y);
	SDLSprite(SDL_Texture* tex);
	SDLSprite(SDL_Texture* tex, int x, int y);

	virtual ~SDLSprite();

	void Start();
	void Update();
	void Draw();
	void Stop();

private:

	void ApplySurface(int x, int y, SDL_Texture* texture, SDL_Renderer* renderer);

	SDL_Texture* tex;
	int x, y;
};

