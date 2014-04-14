#pragma once

/**
* @file Game.h
* @brief Todo
*/

#include "Common.h"

// Engine includes
#include "Engine.h"
#include "Sprite.h"

class Test: public Sprite
{
	public:
		 Test(const std::string& path, int x, int y, float mass);
		~Test();

	protected:
		void OnCollisionEnter(b2Body* collider);
		void OnCollisionLeave(b2Body* collider);
};

class Game: public Component
{
	public:
		 Game();
		~Game();
		
		void Notify(const InputEvent& event);
		void Update(unsigned int t);

	private:
		Test* test1;
		Test* test2;
};