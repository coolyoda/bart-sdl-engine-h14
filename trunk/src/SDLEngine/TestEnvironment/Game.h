#pragma once

/**
* @file Game.h
* @brief Todo
*/

#include "Common.h"

// Engine includes
#include "Engine.h"
#include "Sprite.h"

class Game: public Component
{
	public:
		 Game();
		~Game();
		
		void Notify(const InputEvent& event);
		void Update(unsigned int t);

	private:
		Sprite* image;
};