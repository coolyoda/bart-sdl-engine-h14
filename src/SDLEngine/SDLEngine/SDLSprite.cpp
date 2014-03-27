#include "SDLSprite.h"

SDLSprite::SDLSprite() 
	: SDLComponent()
	, tex(nullptr)
	, x(0)
	, y(0)
{
}

SDLSprite::SDLSprite(std::string fileName): SDLSprite(fileName, 0, 0){ }
SDLSprite::SDLSprite(std::string fileName, int x, int y)
	: SDLComponent()
	, tex(nullptr)
	, x(x)
	, y(y)
{
	tex = SDLResources::GetInstance()->GetTexture(fileName);
}

SDLSprite::SDLSprite(SDL_Texture* tex)
	: SDLComponent()
	, tex(tex)
	, x(0)
	, y(0)
{
}

SDLSprite::SDLSprite(SDL_Texture* tex, int x, int y)
: SDLComponent()
, tex(tex)
, x(x)
, y(y)
{
}

SDLSprite::~SDLSprite()
{
}

void SDLSprite::Start()
{
}

void SDLSprite::Update()
{
}

void SDLSprite::Draw()
{
	ApplySurface(this->x, this->y, tex, SDLEngine::GetInstance()->GetRenderer());
}

void SDLSprite::Stop()
{
}

void SDLSprite::ApplySurface(int x, int y, SDL_Texture* texture, SDL_Renderer* renderer)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	SDL_QueryTexture(texture, 0, 0, &rect.w, &rect.h);
	SDL_RenderCopy(renderer, texture, 0, &rect);
}
