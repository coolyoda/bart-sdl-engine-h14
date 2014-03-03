#include <iostream>

#include "SDLEngine.h"

using namespace std;

int main(int argc, char* argv[])
{
	SDLComponent* comp = new SDLComponent();

	SDLEngine::GetInstance()->Start();

	delete comp;
}