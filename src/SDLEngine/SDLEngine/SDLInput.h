#pragma once
#include "SDL.h"

class SDLInput
{
#pragma region SINGLETON
public:
	static SDLInput* GetInstance()
	{
		if (instance == nullptr)
			instance = new SDLInput();
		return instance;
	}
	static void Kill()
	{
		delete instance;
		instance = nullptr;
	}
private:
	static SDLInput* instance;
	SDLInput();
	SDLInput(const SDLInput& e);
	~SDLInput();
	SDLInput& operator= (const SDLInput& e);
#pragma endregion
public:

	void Poll();
	bool IsHeld(SDL_Keycode key)
	{
		return currKeys[key] != 0;
	}

	bool IsDown(SDL_Keycode key)
	{
		if (IsHeld(key))
		{
			return true;
		}

		return false;
	}

private:
	const Uint8* currKeys;
	const Uint8* prevKeys;
};