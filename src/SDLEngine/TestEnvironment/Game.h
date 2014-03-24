#pragma once
#include "SDLComponent.h"
class Game :
	public SDLComponent
{
public:
	Game();
	~Game();

	void Update();
};

