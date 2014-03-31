#pragma once
#include <iostream>
#include "InputEvent.h"
#include "SDLSprite.h"

class Game :
	public SDLComponent
{
public:
	Game();
	~Game();

	void Notify(const InputEvent& event);
	void Update();

private:
	SDLSprite* texFireFox;
};

