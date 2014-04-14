#include "Collider.h"

Collider::Collider(): Component(), body(NULL)
{
}

Collider::~Collider()
{
	DeleteCollider();
}

void Collider::CreateCollider(ColliderType type, float mass)
{
	DeleteCollider();
	body = Physics::GetInstance()->CreateBody(rect.x, rect.y,
		(mass == 0.f) ? b2_staticBody : b2_dynamicBody
	);

	switch (type)
	{
		case SQUARE_COLLIDER:
		{
			polygonShape.SetAsBox(rect.w, rect.h);
		} break;

		case SPHERE_COLLIDER:
		{
		} break;

		default:
		{
		} break;
	}
}

void Collider::DeleteCollider()
{
	if (body != NULL)
	{
		Physics::GetInstance()->DestroyBody(body);
		body = NULL;
	}
}