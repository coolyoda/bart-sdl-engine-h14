#include "Component.h"

std::vector<Component*> Component::allComponents;

Component::Component()
{
	allComponents.push_back(this);

	rect.x = 0;
	rect.y = 0;
	rect.w = 0;
	rect.h = 0;
}

Component::~Component()
{
	std::vector<Component*>::iterator it = allComponents.begin();
	while (it != allComponents.end())
	{
		if ((*it) == this)
		{
			it = allComponents.erase(it);
			break;
		} it++;
	}
}

void Component::Start()
{
}

void Component::Notify(const InputEvent& event)
{
}

void Component::Update()
{
}

void Component::Draw()
{
}

void Component::Stop()
{
}