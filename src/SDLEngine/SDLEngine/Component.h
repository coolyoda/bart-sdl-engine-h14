#pragma once

/**
* @file Component.h
* @brief Todo
*/

#include "Common.h"

// Engine includes
#include "InputEvent.h"

class Component
{
	public:
		friend class Engine;
		
		Component();
		virtual ~Component();

		virtual void Start();
		virtual void Notify(const InputEvent& event);
		virtual void Update(unsigned int t);
		virtual void Draw();
		virtual void Stop();
	
		// POSITION GETTERS
		int GetX() const { return rect.x; }
		int GetY() const { return rect.y; }
		void GetPosition(int &x, int &y)
		{
			x = GetX();
			y = GetY();
		}

		// POSITION SETTERS
		void SetX(int x) { rect.x = x; }
		void SetY(int y) { rect.y = y; }
		void SetPosition(int x, int y)
		{
			SetX(x);
			SetY(y);
		}

		// SIZE GETTERS
		int GetW() const { return rect.w; }
		int GetH() const { return rect.h; }
		void GetSize(int &w, int &h)
		{
			w = GetW();
			h = GetH();
		}

		// SIZE SETTERS
		void SetW(int w) { rect.w = w; }
		void SetH(int h) { rect.h = h; }
		void SetSize(int w, int h)
		{
			SetW(w);
			SetH(h);
		}

		// RECT ACCESSOR
		const SDL_Rect& GetRect() const { return rect; }
		void SetRect(const SDL_Rect& r)
		{
			this->rect = r;
		}

	private:
		static std::vector<Component*> allComponents;

	protected:
		SDL_Rect rect;
};