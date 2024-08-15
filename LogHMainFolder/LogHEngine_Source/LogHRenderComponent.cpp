#include "LogHRenderComponent.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	RenderComponent::RenderComponent()
	{
	}

	RenderComponent::~RenderComponent()
	{
	}

	void RenderComponent::Initialize()
	{
	}

	void RenderComponent::Update()
	{
	}

	void RenderComponent::LateUpdate()
	{
	}

	void RenderComponent::Render(HDC Hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(Hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(Hdc, redPen);
		SelectObject(Hdc, oldPen);

		TransformComponent* MyTransform = GetOwner()->GetComponent<TransformComponent>();
		Rectangle(Hdc, 100 + MyTransform->GetPositionX(), 
			100 + MyTransform->GetPositionY(), 
			200 + MyTransform->GetPositionX(), 
			200 + MyTransform->GetPositionY());

		SelectObject(Hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}