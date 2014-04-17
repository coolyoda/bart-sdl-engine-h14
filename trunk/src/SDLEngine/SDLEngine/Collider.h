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

		b2Body* GetBody() const {
			return body;
		}

		// custom collider contact listener
		class CollisionListener: public b2ContactListener
		{
			void BeginContact(b2Contact* contact) {
				void* ud = contact->GetFixtureA()->GetBody()->GetUserData();
				if (ud)
				{
					// check fixtureA collision
					static_cast<Collider*>(ud)->OnCollisionEnter(
						contact->GetFixtureB()
					);
				}

				ud = contact->GetFixtureB()->GetBody()->GetUserData();
				if (ud)
				{
					// check fixtureB collision
					static_cast<Collider*>(ud)->OnCollisionEnter(
						contact->GetFixtureA()
					);
				}
			}

			void EndContact(b2Contact* contact) {
				void* ud = contact->GetFixtureA()->GetBody()->GetUserData();
				if (ud)
				{
					// check fixtureA collision
					static_cast<Collider*>(ud)->OnCollisionLeave(
						contact->GetFixtureB()
					);
				}

				ud = contact->GetFixtureB()->GetBody()->GetUserData();
				if (ud)
				{
					// check fixtureB collision
					static_cast<Collider*>(ud)->OnCollisionLeave(
						contact->GetFixtureA()
					);
				}
			}
		};

	protected:
		virtual void OnCollisionEnter(b2Fixture* fixture) {}
		virtual void OnCollisionLeave(b2Fixture* fixture) {}
		b2Body* body;
};