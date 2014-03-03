#include "SDLEngine.h"

SDLEngine* SDLEngine::instance = nullptr;

SDLEngine::SDLEngine()
:isInitialized(false)
{

}

SDLEngine::~SDLEngine()
{

}

void SDLEngine::Start()
{
	for (auto iter = SDLComponent::allComponents.begin();
		iter != SDLComponent::allComponents.end();
		iter++)
	{
		(*iter)->Start();
	}

	isInitialized = true;

	Run();
}

void SDLEngine::Run()
{
	while (isInitialized)
	{
		if (GetAsyncKeyState(VK_RETURN))
		{
			break;
		}

		Update();
		Draw();
	}
	Stop();
}

void SDLEngine::Update()
{
	for (auto iter = SDLComponent::allComponents.begin();
		iter != SDLComponent::allComponents.end();
		iter++)
	{
		(*iter)->Update();
	}
}

void SDLEngine::Draw()
{
	for (auto iter = SDLComponent::allComponents.begin();
		iter != SDLComponent::allComponents.end();
		iter++)
	{
		(*iter)->Draw();
	}
}

void SDLEngine::Stop()
{
	for (auto iter = SDLComponent::allComponents.begin();
		iter != SDLComponent::allComponents.end();
		iter++)
	{
		(*iter)->Stop();
	}
}
