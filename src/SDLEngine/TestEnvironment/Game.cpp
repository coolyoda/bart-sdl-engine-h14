#include "Game.h"

Game::Game()
{
	Engine::GetInstance()->SetWindowTitle("Test Environment");
	Engine::GetInstance()->SetWindowSize(320, 240);

	image = new Sprite("firefox.png", 0, 0);
	image->CreateCollider(Collider::SQUARE_COLLIDER, 1.0f);
	image->SetW(100);
	image->SetH(100);
}

Game::~Game()
{
	if (image)
	{
		delete image;
		image = NULL;
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