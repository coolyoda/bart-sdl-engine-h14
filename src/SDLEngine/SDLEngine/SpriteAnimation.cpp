#include "SpriteAnimation.h"

SpriteAnimation:: SpriteAnimation(const std::string& path, int x, int y)
	: Sprite(path, x, y), currentDirection(DOWN), delay(200), frame(1), isLooping(true)
{
}

SpriteAnimation::~SpriteAnimation()
{
}

void SpriteAnimation::AddAnimationFrame(Directions dir, const SDL_Rect& rect)
{
	SDL_Rect size;
	SDL_QueryTexture(tex, 0, 0, &size.w, &size.h);
	if (rect.x + rect.w < size.w &&
		rect.y + rect.h < size.h)
	{
		frames[dir].push_back(rect);
	}
}

void SpriteAnimation::Start()
{
	Sprite::Start();
}

void SpriteAnimation::Update(unsigned int t)
{
	Sprite::Update(t);
}

void SpriteAnimation::Draw()
{
	if (frames[currentDirection].size() > 0) {
		int index = (SDL_GetTicks() / delay) % frame;

		SDL_Rect src;
		src.x = frames[currentDirection][index].x;
		src.y = frames[currentDirection][index].y;
		src.w = frames[currentDirection][index].w;
		src.h = frames[currentDirection][index].h;

		SetW(src.w);
		SetH(src.h);

		SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(),
			tex, &src, &rect, angle, 0, SDL_FLIP_NONE
		);
	}
}

void SpriteAnimation::Stop()
{
	Sprite::Stop();
}