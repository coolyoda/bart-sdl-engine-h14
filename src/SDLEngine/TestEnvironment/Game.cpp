#include "Game.h"
#include "SDLInput.h"

#include <iostream>

Game::Game()
{
}

Game::~Game()
{
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