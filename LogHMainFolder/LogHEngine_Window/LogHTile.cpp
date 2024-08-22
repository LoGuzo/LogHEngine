#include "LogHTile.h"
#include "LogHTransformComponent.h"

namespace LogH
{
	void Tile::Initialize()
	{
		GameObject::Initialize();
	}

	void Tile::Update()
	{
		GameObject::Update();
	}

	void Tile::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Tile::Render(HDC Hdc)
	{
		GameObject::Render(Hdc);
	}

	void Tile::SetIndexPosition(int x, int y)
	{
		TransformComponent* Tc = GetComponent<TransformComponent>();
		Tc->SetPosition(Vector2(x, y));
	}
}