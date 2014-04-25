#include "Text.h"

Text:: Text()
	: Component()
	, tex(NULL)
	, fon(NULL)
{
}

Text:: Text(const std::string& path, int size, int x, int y)
	: Component()
	, tex(NULL)
	, fon(NULL)
{
	SetFont(path, size);
	SetX(x);
	SetY(y);
}

Text::~Text()
{
}

void Text::SetFont(const std::string& path, int size)
{
	fon = Resources::GetInstance()->GetFont(path, size);
	if (fon == NULL)
	{
		std::cout << "Unable to set font " << path << std::endl;
	}
}

void Text::SetText(const std::string& text, int r, int g, int b, int a)
{
	SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;

	// build internal component texture
	tex = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(),
		TTF_RenderText_Blended(fon, text.c_str(), color)
	);

	// update component bounds
	SDL_QueryTexture(tex, 0, 0, &rect.w, &rect.h);
}

void Text::Update(unsigned int t)
{
}

void Text::Draw()
{
	if (tex && isVisible) {
		ApplySurface(tex, Engine::GetInstance()->GetRenderer());
	}
}

void Text::Stop()
{
}

void Text::ApplySurface(SDL_Texture* texture, SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, 0, &rect);
}