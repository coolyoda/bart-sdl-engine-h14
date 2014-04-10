#include "Engine.h"

Engine* Engine::instance = NULL;

Engine:: Engine(): isInitialized(false)
{
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << SDL_GetError() << std::endl;
	}

	// Create a new render context. 
	window = SDL_CreateWindow
	(
		// window title
		  TITLE_PREFIX

		// window position (x,y)
		, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED

		// window dimention (w,h)
		, DEFAULT_WIN_W, DEFAULT_WIN_H

		// creation flags
		, SDL_WINDOW_SHOWN
	);

	// Initialize video.
	renderer = new Renderer(window);

	// Initialize input.
	InputEvent::initialize();
}

Engine::~Engine()
{
	if (renderer)
	{
		// delete renderer first
		delete renderer;
		renderer = NULL;
	}

	// destroy render context
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Engine::Start()
{
	for (unsigned int i = 0; i < Component::allComponents.size(); i++) {
		Component::allComponents[i]->Start();
	}

	isInitialized = true;
	Run();
}

void Engine::Run()
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
			for (unsigned int i = 0; i < Component::allComponents.size(); i++) {
				Component::allComponents[i]->Notify(*event);
			}

			// clean event
			delete event;
		}

		Update();
		Draw();
	}

	Stop();
}

void Engine::Update()
{
	for (unsigned int i = 0; i < Component::allComponents.size(); i++) {
		Component::allComponents[i]->Update();
	}

	// step current physical world
	Physics::GetInstance()->Step();
}

void Engine::Draw()
{
	renderer->Clear(101, 156, 239);
	for (unsigned int i = 0; i < Component::allComponents.size(); i++) {
		Component::allComponents[i]->Draw();
	}

	renderer->Display();
}

void Engine::Stop()
{
	for (unsigned int i = 0; i < Component::allComponents.size(); i++) {
		Component::allComponents[i]->Stop();
	}
	
	Component::allComponents.clear();
	Resources::Kill();
	Physics::Kill();
	Kill();
}