#include "Physics.h"

Physics* Physics::instance = NULL;

Physics:: Physics() : world(b2Vec2(0.0f, 9.8f))
{
}

Physics::~Physics()
{
	bodies.clear();
}

b2Body* Physics::CreateBody(int x, int y, b2BodyType type)
{
	b2BodyDef def;

	// assign body def position
	def.position.x = (float) x;
	def.position.y = (float) y;

	// assign body def type
	def.type = type;

	// call the body factory witch allocates memory for the
	// given shape, the body is also added to the world
	return world.CreateBody(&def);
}

void Physics::DestroyBody(b2Body* body)
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