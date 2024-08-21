#include "LogHCircleComponent2D.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	CircleComponent2D::CircleComponent2D()
		:ShapeComponent(Enums::E_ColliderType::Rect2D)
	{
	}

	CircleComponent2D::~CircleComponent2D()
	{
	}

	void CircleComponent2D::Initialize()
	{
	}

	void CircleComponent2D::Update()
	{
	}

	void CircleComponent2D::LateUpdate()
	{
	}

	void CircleComponent2D::Render(HDC Hdc)
	{
		TransformComponent* Tc = GetOwner()->GetComponent<TransformComponent>();
		Vector2 Pos = Tc->GetPosition();

		Vector2 root = GetRoot();

		HBRUSH TransparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH OldBrush = (HBRUSH)SelectObject(Hdc, TransparentBrush);

		HPEN GreenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN OldPen = (HPEN)SelectObject(Hdc, GreenPen);

		Vector2 RightBottom;
		RightBottom.x = Pos.x + root.x + GetSize().x;
		RightBottom.y = Pos.y + root.y + GetSize().y;

		Ellipse(Hdc, Pos.x + root.x
			, Pos.y + root.y
			, RightBottom.x
			, RightBottom.y);

		SelectObject(Hdc, OldBrush);
		SelectObject(Hdc, OldPen);
		DeleteObject(GreenPen);
	}
}