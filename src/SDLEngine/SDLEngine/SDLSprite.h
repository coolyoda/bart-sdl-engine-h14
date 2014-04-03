#pragma once
#include "SDLResources.h"
#include "SDLCollider.h"

class SDLSprite :
	public SDLCollider
{
public:
	SDLSprite();
	SDLSprite(std::string fileName);
	SDLSprite(std::string fileName, int x, int y, int w = 0, int h = 0);
	SDLSprite(std::string fileName, const SDL_Rect& rect);

	SDLSprite(SDL_Texture* tex);
	SDLSprite(SDL_Texture* tex, int x, int y, int w = 0, int h = 0);
	SDLSprite(SDL_Texture* tex, const SDL_Rect& rect);

	virtual ~SDLSprite();

	void Start();
	void Update();
	void Draw();
	void Stop();

private:
	void ApplySurface(SDL_Texture* texture, SDL_Renderer* renderer);
	SDL_Texture* tex;
};