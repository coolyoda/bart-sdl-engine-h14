#pragma once
#include <iostream>
#include "SDLInput.h"
#include "SDLSprite.h"

class Game :
	public SDLComponent
{
public:
	Game();
	~Game();

	void Update();

private:
	SDLSprite* texFireFox;
};

