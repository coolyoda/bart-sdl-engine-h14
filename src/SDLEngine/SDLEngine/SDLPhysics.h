#pragma once

#include "Box2D/Box2D.h"

#include <map>
#include "SDLEngine.h"

class SDLPhysics
{
#pragma region SINGLETON
public:
	static SDLPhysics* GetInstance()
	{
		if (instance == nullptr)
			instance = new SDLPhysics();
		return instance;
	}

	static void Kill()
	{
		delete instance;
		instance = nullptr;
	}

private:
	static SDLPhysics* instance;

	 SDLPhysics();
	 SDLPhysics(const SDLPhysics& e);
	~SDLPhysics();

	 SDLPhysics& operator=(const SDLPhysics& e);
#pragma endregion

public:
	void Step(float step = 1.0f/60.0f, int vit = 6, int pit = 2)
	{
		world.Step(step, vit, pit);
		world.Step(step, vit, pit);
		world.Step(step, vit, pit);
		world.Step(step, vit, pit);
	}

	b2Body* CreateBody(int x, int y, b2BodyType type);
	void DestroyBody(b2Body* body);

private:
	std::vector<b2Body*> bodies;
	b2World world;
};