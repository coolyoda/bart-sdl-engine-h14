#include "Game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	Engine::GetInstance()->SetWindowTitle("Test Environment");
	Engine::GetInstance()->Start();

	delete game;
	return 0;
}