#pragma once

/**
* @file Collider.h
* @brief Todo
*/

#include "Common.h"

// Engine includes
#include "Component.h"
#include "Physics.h"

class Collider: public Component
{
	public:
		enum ColliderType
		{
			SQUARE_COLLIDER = 0,
			SPHERE_COLLIDER = 1,
			TYPE_NUM
		};
		
		Collider();
		virtual ~Collider();
		
		void CreateCollider(ColliderType type, float mass = 0.f);
		void DeleteCollider();

	protected:
		b2Body* body;
};