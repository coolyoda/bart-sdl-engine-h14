#include "Game.h"

Test:: Test(const std::string& path, int x, int y, float mass): Sprite(path, x, y) {
	CreateCollider(Collider::SPHERE_COLLIDER, mass);
}

Test::~Test()
{
}

void Test::OnCollisionEnter(b2Body* collider)
{
	std::cout << "COLLIDING ENTER" << std::endl;
}

void Test::OnCollisionLeave(b2Body* collider)
{
	std::cout << "COLLIDING LEAVE" << std::endl;
}

Game:: Game()
{
	// Create two sprites for testing purpose.
	test1 = new Test("firefox.png", 100, 100, 1.f);
	test2 = new Test("firefox.png", 200, 400, 0.f);
}

Game::~Game()
{
	if (test1)
	{
		delete test1;
		test1 = NULL;
	}

	if (test2)
	{
		delete test2;
		test2 = NULL;
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