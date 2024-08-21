#include "LogHBoxComponent2D.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	BoxComponent2D::BoxComponent2D()
		:ShapeComponent(Enums::E_ColliderType::Rect2D)
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

		Vector2 root = GetRoot();

		HBRUSH TransparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH OldBrush = (HBRUSH)SelectObject(Hdc, TransparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(Hdc, greenPen);

		Rectangle(Hdc, Pos.x + root.x, Pos.y + root.y, Pos.x + root.x + GetSize().x, Pos.y + root.y + GetSize().y);

		SelectObject(Hdc, OldBrush);
		SelectObject(Hdc, oldPen);
		DeleteObject(greenPen);
	}
}