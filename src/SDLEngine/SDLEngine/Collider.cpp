#include "Collider.h"

Collider::Collider(): Component(), body(NULL)
{
}

Collider::~Collider()
{
	DeleteCollider();
}

void Collider::Update(unsigned int t)
{
	if (body != nullptr)
	{
		rect.x = (int) body->GetPosition().x;
		rect.y = (int) body->GetPosition().y;
	}
}

void Collider::Draw()
{
}

void Collider::Stop()
{
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
			b2PolygonShape s;
			s.SetAsBox
			(
				float(rect.w * 0.5f),
				float(rect.h * 0.5f)
			);

			body->CreateFixture(&s, 1.f);
		} break;

		case SPHERE_COLLIDER:
		{
			b2CircleShape s;
			s.m_radius = (rect.w > rect.h)
				? float(rect.w * 0.5f)
				: float(rect.h * 0.5f);

			body->CreateFixture(&s, 1.f);
		} break;

		default:
		{
		} break;
	}

	body->SetUserData(this);
}

void Collider::DeleteCollider()
{
	if (body != NULL)
	{
		Physics::GetInstance()->DestroyBody(body);
		body = NULL;
	}
}