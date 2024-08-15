#include "LogHGameObject.h"
#include "LogHInput.h"

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
		if (Input::GetKeyPressed(E_KeyCode::A))
		{
			Mx -= 0.01f;
		}
		if (Input::GetKeyPressed(E_KeyCode::D))
		{
			Mx += 0.01f;
		}
		if (Input::GetKeyPressed(E_KeyCode::W))
		{
			My -= 0.01f;
		}
		if (Input::GetKeyPressed(E_KeyCode::S))
		{
			My += 0.01f;
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
