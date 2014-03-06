#pragma once

#include <stdexcept>
#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "SDLComponent.h"
#include "SDLRenderer.h"

class SDLEngine
{
#pragma region SINGLETON
public:
	static SDLEngine* GetInstance()
	{
		if (instance == nullptr)
			instance = new SDLEngine();
		return instance;
	}
	static void Kill()
	{
		delete instance;
		instance = nullptr;
	}
private:
	static SDLEngine* instance;
	SDLEngine();
	SDLEngine(const SDLEngine& e);
	~SDLEngine();
	SDLEngine& operator= (const SDLEngine& e);
#pragma endregion
public:
	void Start();

private:
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;

	bool isInitialized;

	void Run();
	void Update();
	void Draw();
	void Stop();

	SDLRenderer* renderer;
	SDL_Window* window;
};

