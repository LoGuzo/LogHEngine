#include "LogHRenderComponent.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"
#include "LogHTexture.h"
#include "LogHRenderer.h"

namespace LogH
{
	RenderComponent::RenderComponent()
		: Component(Enums::E_ComponentType::Renderer)
		, MTexture(nullptr)
		, TScale(Vector2::One)
	{
	}

	RenderComponent::~RenderComponent()
	{
		SAFE_DELETE(MTexture);
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
		if (!MTexture)
			assert(false);

		TransformComponent* MyTransform = GetOwner()->GetComponent<TransformComponent>();
		Vector2 pos = MyTransform->GetPosition();

		if(Renderer::MainCamera)
			pos = Renderer::MainCamera->CaluatePosition(pos);

		if (MTexture->GetTextureType() == Graphics::Texture::E_TextureType::Bmp)
		{
			TransparentBlt(Hdc, pos.x, pos.y
				, MTexture->GetWidth(), MTexture->GetHeight()
				, MTexture->GetHdc(), 0, 0, MTexture->GetWidth(), MTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (MTexture->GetTextureType() == Graphics::Texture::E_TextureType::Png)
		{
			Gdiplus::Graphics graphcis(Hdc);
			graphcis.DrawImage(MTexture->GetImage(),
				Gdiplus::Rect(pos.x, pos.y, MTexture->GetWidth() * TScale.x, MTexture->GetHeight() * TScale.y));
		}
	}
}