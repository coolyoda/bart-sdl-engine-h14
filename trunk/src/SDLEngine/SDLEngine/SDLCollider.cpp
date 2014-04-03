#include "SDLCollider.h"

SDLCollider:: SDLCollider()
	: SDLComponent()
	, body(nullptr)
{
}

SDLCollider::~SDLCollider()
{
	DeleteCollider();
}

void SDLCollider::CreateCollider(ColliderType type, float mass)
{
	if (body != nullptr)
	{
		DeleteCollider();
	}

	body = SDLPhysics::GetInstance()->CreateBody(rect.x, rect.y,
		(mass == 0.f) ? b2_staticBody : b2_dynamicBody
	);

	switch (type)
	{
		case SQUARE_COLLIDER:
		case SPHERE_COLLIDER:
		default:
		{
		}
	}
}

void SDLCollider::DeleteCollider()
{
	if (body != nullptr)
	{
		SDLPhysics::GetInstance()->DestroyBody(body);
		body = nullptr;
	}
}