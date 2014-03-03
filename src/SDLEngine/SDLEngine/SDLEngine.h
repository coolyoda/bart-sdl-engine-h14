#pragma once

#include "SDLComponent.h"
#include <Windows.h>

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
	bool isInitialized;
	void Run();
	void Update();
	void Draw();
	void Stop();
};

