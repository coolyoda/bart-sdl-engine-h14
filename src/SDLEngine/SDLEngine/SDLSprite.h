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
	
	int GetX(){ return x; }
	int GetY(){ return y; }
	void GetPosition(int &x, int &y){ x = GetX(); y = GetY(); }
	void SetPosition(int x, int y)	{ SetX(x); SetY(y); }
	void SetX(int x){ this->x = x; }
	void SetY(int y){ this->y = y; }

	void Start();
	void Update();
	void Draw();
	void Stop();

private:
	void ApplySurface(int x, int y, SDL_Texture* texture, SDL_Renderer* renderer);
	SDL_Texture* tex;

protected:
	int x, y;
};

