#include <iostream>

#include "SDLEngine.h"
#include "Game.h"

using namespace std;

int main(int argc, char* argv[])
{
	SDLComponent* comp = new SDLComponent();
	Game* g = new Game();

	SDLEngine::GetInstance()->Start();

	delete comp;
	delete g;
	return 0;
}