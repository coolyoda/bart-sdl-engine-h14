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
	{
		// create text object 'test5'
		test5 = new SpriteAnimation("fighter.png", 100, 100);

		int offsetX = 0;
		int offsetY = 2;
		for (int i = 0; i < 4; i++)
		{
			SDL_Rect frame;
			frame.x = offsetX;
			frame.y = offsetY;
			frame.w = 25;
			frame.h = 45;

			test5->AddAnimationFrame(SpriteAnimation::DOWN, frame);
			frame.y += 48;

			test5->AddAnimationFrame(SpriteAnimation::LEFT, frame);
			frame.y += 48;

			test5->AddAnimationFrame(SpriteAnimation::RIGHT, frame);
			frame.y += 48;

			test5->AddAnimationFrame(SpriteAnimation::UP, frame);
			offsetX += 32;
		}
	}

	{
		//Load sfx and music
		Audio::GetInstance()->PlaySound("test.wav", 100, 0.5, -1);
		//Audio::GetInstance()->PlayMusic("testsong.mp3", 100);

		Audio::GetInstance()->ChangeSFXVolume(50);
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

		switch (event.get_keyboard_key())
		{
			case InputEvent::KEY_DOWN: {
				test5->SetCurrentDirection(SpriteAnimation::DOWN);
				test5->SetNumberOfFrame(4);
			} break;

			case InputEvent::KEY_LEFT: {
				test5->SetCurrentDirection(SpriteAnimation::LEFT);
				test5->SetNumberOfFrame(4);
			} break;

			case InputEvent::KEY_RIGHT: {
				test5->SetCurrentDirection(SpriteAnimation::RIGHT);
				test5->SetNumberOfFrame(4);
			} break;

			case InputEvent::KEY_UP: {
				test5->SetCurrentDirection(SpriteAnimation::UP);
				test5->SetNumberOfFrame(4);
			} break;

			case InputEvent::KEY_DELETE: {
				Audio::GetInstance()->PlaySoundFocus("testfocus.wav");
			} break;
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

		test5->SetNumberOfFrame(1);
	}
}

void Game::Update(unsigned int t)
{
	// continuous keyboard check
	if (InputEvent::is_key_down(InputEvent::KEY_RETURN)) {
		std::cout << "Return Key Held" << std::endl;
	}
}