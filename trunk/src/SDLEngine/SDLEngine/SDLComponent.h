#pragma once
#include <iostream>
#include <vector>

class SDLComponent
{
public:
	friend class SDLEngine;

	SDLComponent();
	virtual ~SDLComponent();

	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Stop();
private:
	static std::vector<SDLComponent*> allComponents;
};

