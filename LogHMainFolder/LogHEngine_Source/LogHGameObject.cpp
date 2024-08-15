#include "LogHGameObject.h"
#include "LogHInput.h"
#include "LogHTime.h"

namespace LogH
{
	GameObject::GameObject()
	{

	}

	GameObject::~GameObject()
	{

	}
	void GameObject::Update()
	{
		const int Speed = 100.f;
		const float DeltaTime = Time::GetDeltaTime();
		if (Input::GetKeyPressed(E_KeyCode::Left))
		{
			Mx -= Speed * DeltaTime;
		}
		if (Input::GetKeyPressed(E_KeyCode::Right))
		{
			Mx += Speed * DeltaTime;
		}
		if (Input::GetKeyPressed(E_KeyCode::Up))
		{
			My -= Speed * DeltaTime;
		}
		if (Input::GetKeyPressed(E_KeyCode::Down))
		{
			My += Speed * DeltaTime;
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC Hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(Hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(Hdc, redPen);
		SelectObject(Hdc, oldPen);

		Rectangle(Hdc, 100 + Mx, 100 + My, 200 + Mx, 200 + My);

		SelectObject(Hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}
