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
		enum TestCategories
		{
			TEST1_CATEGORY = 0x0001,
			TEST2_CATEGORY = 0x0002
		};

		 Test(const std::string& path, int x, int y);
		~Test();

	protected:
		void OnCollisionEnter(b2Fixture* fixture);
		void OnCollisionLeave(b2Fixture* fixture);
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