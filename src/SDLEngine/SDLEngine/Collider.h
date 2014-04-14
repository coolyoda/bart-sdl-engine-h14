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

		void Update(unsigned int t);
		void Draw();
		void Stop();

		void CreateCollider(ColliderType type, float mass = 0.f);
		void DeleteCollider();

		// custom collider contact listener
		class CollisionListener: public b2ContactListener
		{
			void BeginContact(b2Contact* contact) {
				void* ud = contact->GetFixtureA()->GetBody()->GetUserData();
				if (ud)
				{
					// check fixtureA collision
					static_cast<Collider*>(ud)->OnCollisionEnter(
						contact->GetFixtureB()->GetBody()
					);
				}

				ud = contact->GetFixtureB()->GetBody()->GetUserData();
				if (ud)
				{
					// check fixtureB collision
					static_cast<Collider*>(ud)->OnCollisionEnter(
						contact->GetFixtureA()->GetBody()
					);
				}
			}

			void EndContact(b2Contact* contact) {
				void* ud = contact->GetFixtureA()->GetBody()->GetUserData();
				if (ud)
				{
					// check fixtureA collision
					static_cast<Collider*>(ud)->OnCollisionLeave(
						contact->GetFixtureB()->GetBody()
					);
				}

				ud = contact->GetFixtureB()->GetBody()->GetUserData();
				if (ud)
				{
					// check fixtureB collision
					static_cast<Collider*>(ud)->OnCollisionLeave(
						contact->GetFixtureA()->GetBody()
					);
				}
			}
		};

	protected:
		virtual void OnCollisionEnter(b2Body* collider) {}
		virtual void OnCollisionLeave(b2Body* collider) {}
		b2Body* body;
};