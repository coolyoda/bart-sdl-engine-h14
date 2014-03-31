#include <iostream>
#include "SDLEngine.h"

#include "SDL.h"

using namespace std;

class Animal
{
public:
	Animal(){}
	~Animal(){}
	virtual void Parler(){ std::cout << "..." << std::endl; }
};

class Chien : public Animal
{
public:
	Chien(): Animal(){}
	~Chien(){}
	void Parler(){ std::cout << "Woof" << std::endl; }
};

int main(int argc, char* argv[])
{
	//Animal* a = new Chien();
	//a->Parler();
	//delete a;

	SDLEngine::GetInstance()->Start();

	return 0;
}