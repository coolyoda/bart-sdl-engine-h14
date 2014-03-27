#include "Game.h"

Game::Game()
{
	texFireFox = new SDLSprite("firefox.png");
	texFireFox->SetPosition(100, 100);
}

Game::~Game()
{
	delete texFireFox;
}

void Game::Update()
{
	if (SDLInput::GetInstance()->IsHeld(SDL_SCANCODE_RETURN)) {
		std::cout << "Held" << std::endl;
	}

	if (SDLInput::GetInstance()->IsHeld(SDL_SCANCODE_RETURN)) {
		std::cout << "Down" << std::endl;
	}
}