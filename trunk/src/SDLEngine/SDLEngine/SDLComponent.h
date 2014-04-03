#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>

#include "InputEvent.h"

class SDLComponent
{
public:
	friend class SDLEngine;

	SDLComponent();
	virtual ~SDLComponent();

	virtual void Start();
	virtual void Notify(const InputEvent& event);
	virtual void Update();
	virtual void Draw();
	virtual void Stop();
	
	// POSITION ACCESSOR
	int GetX() const { return rect.x; }
	int GetY() const { return rect.y; }
	void SetX(int x) { rect.x = x; }
	void SetY(int y) { rect.y = y; }
	void GetPosition(int &x, int &y)
	{
		x = GetX();
		y = GetY();
	}
	void SetPosition(int x, int y)
	{
		SetX(x);
		SetY(y);
	}

	// SIZE ACCESSOR
	int GetW() const { return rect.w; }
	int GetH() const { return rect.h; }
	void SetW(int w) { rect.w = w; }
	void SetH(int h) { rect.h = h; }
	void GetSize(int &w, int &h)
	{
		w = GetW();
		h = GetH();
	}
	void SetSize(int w, int h)
	{
		SetW(w);
		SetH(h);
	}


	const SDL_Rect& GetRect() { return rect; }
	void SetRect(const SDL_Rect& rect) { this->rect = rect; }

private:
	static std::vector<SDLComponent*> allComponents;

protected:
	SDL_Rect rect;
};

