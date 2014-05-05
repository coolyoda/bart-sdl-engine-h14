#pragma once

/**
* @file Physics.h
* @brief Todo
*/

#include "Common.h"

class Physics
{
	public:
		#pragma region SINGLETON
		static Physics* GetInstance()
		{
			if (instance == NULL)
			{
				instance = new Physics();
			}

			return instance;
		}

		static void Kill()
		{
			if (instance)
			{
				delete instance;
				instance = NULL;
			}
		}

	private:
		 Physics();
		 Physics(const Physics& other);
		~Physics();

		Physics& operator= (const Physics& other);
		static Physics* instance;
		#pragma endregion

	public:
		void SetContactListener(b2ContactListener* listener) {
			world.SetContactListener(listener);
		}

		void Step(float step = 1.0f/60.0f, int vit = 6, int pit = 2)
		{
			world.Step(step, vit, pit);
			world.Step(step, vit, pit);
			world.Step(step, vit, pit);
			world.Step(step, vit, pit);
			world.ClearForces();
		}

		b2Body* CreateBody(int x, int y, b2BodyType type);
		void DestroyBody(b2Body* body);

	private:
		std::vector<b2Body*> bodies;
		b2World world;
};