#include "SDLEngine.h"

SDLEngine* SDLEngine::instance = nullptr;

SDLEngine::SDLEngine()
:isInitialized(false)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << SDL_GetError() << std::endl;
	}

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

	renderer = new SDLRenderer(window);
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
	SDL_Event e;
	bool isRunning = true;

	while (isRunning)
	{
		SDLInput::GetInstance()->Poll();

		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					isRunning = false;
					break;
				default:
					break;
				}
			default:
				break;
			}
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

	Kill();
}
