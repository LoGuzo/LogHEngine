#include "LogHTile.h"
#include "LogHTransformComponent.h"
#include "LogHTileScriptComponent.h"
#include "LogHBoxComponent2D.h"
#include "LogHRenderer.h"

namespace LogH
{
	Tile::Tile()
	{
		AddComponent<TileScriptComponent>(L"Script");

		BoxComponent2D* Collision = AddComponent<BoxComponent2D>(L"Collider");
		Collision->SetRoot(Vector2(0.f, 0.f));
		Collision->SetSize(Vector2(24.f, 24.f));
	}

	Tile::~Tile()
	{

	}

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