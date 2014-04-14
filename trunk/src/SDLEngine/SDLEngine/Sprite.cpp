#include "Sprite.h"

Sprite::Sprite()
	: Collider()
	, tex(NULL)
{
}

Sprite::Sprite(std::string fileName)
	: Collider()
	, tex(NULL)
{
	tex = Resources::GetInstance()->GetTexture(fileName);

	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;

	SDL_QueryTexture(tex, 0, 0, &rect.w, &rect.h);
	SetRect(rect);
}

Sprite::Sprite(std::string fileName, int x, int y)
	: Collider()
	, tex(NULL)
{
	tex = Resources::GetInstance()->GetTexture(fileName);

	SDL_Rect rect;
	rect.x = x;
	rect.y = y;

	SDL_QueryTexture(tex, 0, 0, &rect.w, &rect.h);
	SetRect(rect);
}

Sprite::Sprite(std::string fileName, int x, int y, int w, int h)
	: Collider()
	, tex(NULL)
{
	tex = Resources::GetInstance()->GetTexture(fileName);

	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SetRect(rect);
}

Sprite::Sprite(std::string fileName, const SDL_Rect& rect)
	: Collider()
	, tex(NULL)
{
	tex = Resources::GetInstance()->GetTexture(fileName);
	SetRect(rect);
}

Sprite::Sprite(SDL_Texture* tex)
	: Collider()
	, tex(tex)
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;

	SDL_QueryTexture(tex, 0, 0, &rect.w, &rect.h);
	SetRect(rect);
}

Sprite::Sprite(SDL_Texture* tex, int x, int y)
	: Collider()
	, tex(tex)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;

	SDL_QueryTexture(tex, 0, 0, &rect.w, &rect.h);
	SetRect(rect);
}

Sprite::Sprite(SDL_Texture* tex, int x, int y, int w, int h)
	: Collider()
	, tex(tex)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SetRect(rect);
}

Sprite::Sprite(SDL_Texture* tex, const SDL_Rect& rect)
	: Collider()
	, tex(tex)
{
	SetRect(rect);
}

Sprite::~Sprite()
{
}

void Sprite::Start()
{
}

void Sprite::Update(unsigned int t)
{
	Collider::Update(t);
}

void Sprite::Draw()
{
	ApplySurface(tex, Engine::GetInstance()->GetRenderer());
	Collider::Draw();
}

void Sprite::ApplySurface(SDL_Texture* texture, SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, 0, &rect);
}

void Sprite::Stop()
{
	Collider::Stop();
}