#pragma once

#include "SDLComponent.h"

class SDLSprite :
	public SDLComponent
{
public:
	SDLSprite();
	virtual ~SDLSprite();

	void Start();
	void Update();
	void Draw();
	void Stop();
};

