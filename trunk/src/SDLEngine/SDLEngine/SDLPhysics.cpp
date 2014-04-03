#include "SDLPhysics.h"

SDLPhysics* SDLPhysics::instance = nullptr;

SDLPhysics:: SDLPhysics(): world(b2Vec2(0.0f, 9.8f))
{
}

SDLPhysics::~SDLPhysics()
{
	bodies.clear();
}

b2Body* SDLPhysics::CreateBody(int x, int y, b2BodyType type)
{
	b2BodyDef def;

	// assign def position
	def.position.x = x;
	def.position.y = y;

	// assign def type
	def.type = type;

	// call the body factory witch allocates memory for the
	// given shape, the body is also added to the world
	return world.CreateBody(&def);
}

void SDLPhysics::DestroyBody(b2Body* body)
{
	std::vector<b2Body*>::iterator it=bodies.begin();
	while(it!=bodies.end())
	{
		if((*it) == body)
		{
			world.DestroyBody(body);
			it = bodies.erase(it);
			break;
		} it++;
	}
}