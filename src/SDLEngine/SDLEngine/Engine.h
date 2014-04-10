#pragma once

/**
* @file Engine.h
* @brief Todo
*/

#include "Common.h"

// Engine includes
#include "InputEvent.h"
#include "Component.h"
#include "Resources.h"
#include "Renderer.h"
#include "Physics.h"

class Engine
{
	public:
		#pragma region SINGLETON
		static Engine* GetInstance()
		{
			if (instance == NULL)
			{
				instance = new Engine();
			}

			return instance;
		}

		static void Kill()
		{
			if (instance)
			{
				delete instance;
				instance = NULL;
			}
		}

	private:
		 Engine();
		 Engine(const Engine& other);
		~Engine();
		 
		Engine& operator= (const Engine& other);
		static Engine* instance;
		#pragma endregion

	public:
		void SetWindowTitle(const char* title) {
			SDL_SetWindowTitle(window, (StringConcat() << TITLE_PREFIX << title).c_str());
		}

		void SetWindowSize(int w, int h) {
			SDL_SetWindowSize(window, w, h);
		}

		SDL_Renderer* GetRenderer() {
			return renderer->GetRenderer();
		}

		void Start();

	private:
		// Variables
		SDL_Window* window;
		Renderer* renderer;
		bool isInitialized;

		// Services
		void Run();
		void Update(unsigned int t);
		void Draw();
		void Stop();
};