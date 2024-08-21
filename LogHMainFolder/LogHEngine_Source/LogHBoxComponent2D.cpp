#include "LogHBoxComponent2D.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	BoxComponent2D::BoxComponent2D()
		:ShapeComponent()
	{
	}

	BoxComponent2D::~BoxComponent2D()
	{
	}

	void BoxComponent2D::Initialize()
	{
	}

	void BoxComponent2D::Update()
	{
	}

	void BoxComponent2D::LateUpdate()
	{
	}

	void BoxComponent2D::Render(HDC Hdc)
	{
		TransformComponent* Tc = GetOwner()->GetComponent<TransformComponent>();
		Vector2 Pos = Tc->GetPosition();

		Vector2 Root = GetRoot();

		HBRUSH TransparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH OldBrush = (HBRUSH)SelectObject(Hdc, TransparentBrush);

		Rectangle(Hdc, Pos.x + Root.x, Pos.y + Root.y, Pos.x + Root.x + Size.x, Pos.y + Root.y + Size.y);

		SelectObject(Hdc, OldBrush);
		DeleteObject(TransparentBrush);
	}
}