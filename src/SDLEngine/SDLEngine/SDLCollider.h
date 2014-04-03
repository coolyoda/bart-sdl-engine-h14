#pragma once
#include "SDLComponent.h"
#include "SDLPhysics.h"

class SDLCollider :
	public SDLComponent
{
public:
	enum ColliderType
	{
		SQUARE_COLLIDER = 0,
		SPHERE_COLLIDER = 1,
		TYPE_NUM
	};

	SDLCollider();
	virtual ~SDLCollider();

	void CreateCollider(ColliderType type, float mass = 0.f);
	void DeleteCollider();

protected:
	b2Body* body;
};