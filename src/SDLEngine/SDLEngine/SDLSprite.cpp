#include "SDLSprite.h"

SDLSprite::SDLSprite() 
	: SDLCollider()
	, tex(nullptr)
{
}

SDLSprite::SDLSprite(std::string fileName)
	: SDLCollider()
	, tex(nullptr)
{
	tex = SDLResources::GetInstance()->GetTexture(fileName);
}

SDLSprite::SDLSprite(std::string fileName, int x, int y, int w, int h)
	: SDLCollider()
	, tex(nullptr)
{
	tex = SDLResources::GetInstance()->GetTexture(fileName);

	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SetRect(rect);
}

SDLSprite::SDLSprite(std::string fileName, const SDL_Rect& rect)
	: SDLCollider()
	, tex(nullptr)
{
	tex = SDLResources::GetInstance()->GetTexture(fileName);
	SetRect(rect);
}

SDLSprite::SDLSprite(SDL_Texture* tex)
	: SDLCollider()
	, tex(tex)
{
}

SDLSprite::SDLSprite(SDL_Texture* tex, int x, int y, int w, int h)
	: SDLCollider()
	, tex(tex)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SetRect(rect);
}

SDLSprite::SDLSprite(SDL_Texture* tex, const SDL_Rect& rect)
	: SDLCollider()
	, tex(tex)
{
	SetRect(rect);
}

SDLSprite::~SDLSprite()
{
}

void SDLSprite::Start()
{
}

void SDLSprite::Update()
{
	if (body != nullptr)
	{
		rect.x = (int) body->GetPosition().x;
		rect.y = (int) body->GetPosition().y;
	}
}

void SDLSprite::Draw()
{
	ApplySurface(tex, SDLEngine::GetInstance()->GetRenderer());
}

void SDLSprite::Stop()
{
}

void SDLSprite::ApplySurface(SDL_Texture* texture, SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, 0, &rect);
}