#include "Game.h"

Test:: Test(const std::string& path, int x, int y): Sprite(path, x, y)
{
}

Test::~Test()
{
}

void Test::OnCollisionEnter(b2Fixture* fixture) {
	if (GetBody()->GetFixtureList()[0].GetFilterData().categoryBits !=
		fixture->GetFilterData().categoryBits)
	{
		switch (fixture->GetFilterData().categoryBits)
		{
			case TEST1_CATEGORY: {
				std::cout << "TEST1_CATEGORY" << std::endl;
			} break;

			case TEST2_CATEGORY: {
				std::cout << "TEST2_CATEGORY" << std::endl;
			} break;

			default:
			{
			} break;
		}
	}
}

void Test::OnCollisionLeave(b2Fixture* fixture)
{
}

Game::Game()
{
	{
		// create sprite object 'test1'
		test1 = new Test("firefox.png", 100, 100);
		test1->CreateCollider(Collider::SPHERE_COLLIDER, 1.f);

		b2Filter fd;
		fd.categoryBits = Test::TEST1_CATEGORY;
		test1->GetBody()->GetFixtureList()[0].SetFilterData(fd);
		std::cout << "Created 'test1' sprite" << std::endl;
	}
	{
		// create sprite object 'test2'
		test2 = new Test("firefox.png", 200, 400);
		test2->CreateCollider(Collider::SQUARE_COLLIDER, 0.f);

		b2Filter fd;
		fd.categoryBits = Test::TEST2_CATEGORY;
		test2->GetBody()->GetFixtureList()[0].SetFilterData(fd);
		std::cout << "Created 'test2' sprite" << std::endl;
	}
	{
		// create text object 'test3'
		test3 = new Text("arial.ttf", 16, 10, 10);
		test3->SetText("A Quick Brown Fox Jumps Over The Lazy Dog 0123456789", 255, 0, 0);
		std::cout << "Created 'test3' text" << std::endl;
	}
	{
		// create text object 'test4'
		test3 = new Text("arial.ttf", 18, 10, 30);
		test3->SetText("A Quick Brown Fox Jumps Over The Lazy Dog 0123456789", 0, 255, 0);
		std::cout << "Created 'test4' text" << std::endl;
	}
}

Game::~Game()
{
	if (test1) {
		delete test1;
		test1 = NULL;
	}
	if (test2) {
		delete test2;
		test2 = NULL;
	}
	if (test3) {
		delete test3;
		test3 = NULL;
	}
	if (test4) {
		delete test4;
		test4 = NULL;
	}
}

void Game::Notify(const InputEvent& event)
{
	// detect key pressed
	if (event.is_keyboard_key_pressed())
	{
		// filter the pressed key code
		if (event.get_keyboard_key() == InputEvent::KEY_RETURN) {
			std::cout << "Return Key Pressed" << std::endl;
			return;
		}
	}

	// detect key released
	if (event.is_keyboard_key_released())
	{
		// filter the released key code
		if (event.get_keyboard_key() == InputEvent::KEY_RETURN) {
			std::cout << "Return Key Released" << std::endl;
			return;
		}
	}
}

void Game::Update(unsigned int t)
{
	// continuous keyboard check
	if (InputEvent::is_key_down(InputEvent::KEY_RETURN)) {
		std::cout << "Return Key Held" << std::endl;
	}
}