#include "SDLEngine.h"

SDLEngine* SDLEngine::instance = nullptr;

SDLEngine::SDLEngine()
:isInitialized(false)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << SDL_GetError() << std::endl;
	}

	// window
	window = SDL_CreateWindow("Hello World"
		, SDL_WINDOWPOS_CENTERED
		, SDL_WINDOWPOS_CENTERED
		, SCREEN_WIDTH
		, SCREEN_HEIGHT
		, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
	if (window == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	// video
	renderer = new SDLRenderer(window);

	// input
	InputEvent::initialize();
}

SDLEngine::~SDLEngine()
{
	delete renderer;
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void SDLEngine::Start()
{
	std::vector<SDLComponent*>::iterator iter;
	for (iter = SDLComponent::allComponents.begin();
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
	bool isRunning = true;
	while (isRunning)
	{
		InputEvent* event = InputEvent::get_event();
		if (event != NULL)
		{
			// we have detected a new event
			if (event->is_window_closing())
			{
				isRunning = false;
			}

			// broadcast event to all components
			for (auto iter = SDLComponent::allComponents.begin();
				iter != SDLComponent::allComponents.end();
				iter++)
			{
				(*iter)->Notify(*event);
			}

			// clean event
			delete event;
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

	// step current world
	SDLPhysics::GetInstance()->Step();
}

void SDLEngine::Draw()
{
	renderer->Clear();

	for (auto iter = SDLComponent::allComponents.begin();
		iter != SDLComponent::allComponents.end();
		iter++)
	{
		(*iter)->Draw();
	}

	renderer->Present();
}

void SDLEngine::Stop()
{
	for (auto iter = SDLComponent::allComponents.begin();
		iter != SDLComponent::allComponents.end();
		iter++)
	{
		(*iter)->Stop();
	}

	SDLResources::Kill();
	SDLPhysics::Kill();
	Kill();
}