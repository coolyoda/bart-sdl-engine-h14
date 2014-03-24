#include "SDLInput.h"

SDLInput* SDLInput::instance = nullptr;

SDLInput::SDLInput() 
: currKeys(NULL)
, prevKeys(NULL)
{
}

SDLInput::~SDLInput()
{
}

void SDLInput::Poll()
{
	SDL_PumpEvents();
	currKeys = SDL_GetKeyboardState(NULL);
	prevKeys = currKeys;
}