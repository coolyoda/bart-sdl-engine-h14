#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>

#include "InputEvent.h"

class SDLComponent
{
public:
	friend class SDLEngine;

	SDLComponent();
	virtual ~SDLComponent();

	virtual void Start();
	virtual void Notify(const InputEvent& event);
	virtual void Update();
	virtual void Draw();
	virtual void Stop();

private:
	static std::vector<SDLComponent*> allComponents;
};

