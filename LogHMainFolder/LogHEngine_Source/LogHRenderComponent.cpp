#include "LogHRenderComponent.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	RenderComponent::RenderComponent()
		: MImg(nullptr)
		, MWidth(0)
		, MHeight(0)
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
		TransformComponent * MyTransform = GetOwner()->GetComponent<TransformComponent>();
		Vector2 pos = MyTransform->GetPosition();

		Gdiplus::Graphics graphcis(Hdc);
		graphcis.DrawImage(MImg, Gdiplus::Rect(pos.x, pos.y, MWidth, MHeight));
	}

	void RenderComponent::ImageLoad(const wstring& path)
	{
		MImg = Gdiplus::Image::FromFile(path.c_str());
		if (MImg)
		{
			MWidth = MImg->GetWidth();
			MHeight = MImg->GetHeight();
		}
	}
}