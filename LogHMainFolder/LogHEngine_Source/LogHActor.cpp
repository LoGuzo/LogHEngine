#include "LogHActor.h"

namespace LogH
{
	Actor::Actor()
	{
	}

	Actor::~Actor()
	{
	}

	void Actor::Initialize()
	{
		GameObject::Initialize();
	}

	void Actor::Update()
	{
		GameObject::Update();
	}

	void Actor::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Actor::Render(HDC Hdc)
	{
		GameObject::Render(Hdc);
	}
}