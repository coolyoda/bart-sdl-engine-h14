#include "SDLComponent.h"

std::vector<SDLComponent*> SDLComponent::allComponents;

using namespace std;

SDLComponent::SDLComponent()
{
	allComponents.push_back(this);
}

SDLComponent::~SDLComponent()
{

}

void SDLComponent::Start()
{
	//cout << "Component Start" << endl;
}

void SDLComponent::Notify(const InputEvent& event)
{
	//cout << "Component Notify" << endl;
}

void SDLComponent::Update()
{
	//cout << "Component Update" << endl;
}

void SDLComponent::Draw()
{
	//cout << "Component Draw" << endl;
}

void SDLComponent::Stop()
{
	//cout << "Component Stop" << endl;
}
