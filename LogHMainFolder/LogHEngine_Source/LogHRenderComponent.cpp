#include "LogHRenderComponent.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"
#include "LogHTexture.h"
#include "LogHRenderer.h"

namespace LogH
{
	RenderComponent::RenderComponent()
		: Component(Enums::E_ComponentType::Renderer)
		, MyTexture(nullptr)
		, TScale(Vector2::One)
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
		if (!MyTexture)
			assert(false);

		TransformComponent* MyTransform = GetOwner()->GetComponent<TransformComponent>();
		Vector2 Pos = MyTransform->GetPosition();
		Vector2 Scale = MyTransform->GetScale();
		float Rotation = MyTransform->GetRotation();

		if (Renderer::MainCamera)
			Pos = Renderer::MainCamera->CalculatePosition(Pos);

		if (MyTexture->GetTextureType() == Graphics::Texture::E_TextureType::Bmp)
		{
			TransparentBlt(Hdc, Pos.x, Pos.y
				, MyTexture->GetWidth() * TScale.x * Scale.x, MyTexture->GetHeight() * TScale.y * Scale.y
				, MyTexture->GetHdc(), 0, 0, MyTexture->GetWidth(), MyTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (MyTexture->GetTextureType() == Graphics::Texture::E_TextureType::Png)
		{
			Gdiplus::ImageAttributes ImgAttribute = {};
			ImgAttribute.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(Hdc);

			graphics.TranslateTransform(Pos.x,Pos.y);
			graphics.RotateTransform(Rotation);
			graphics.TranslateTransform(-Pos.x, Pos.y);

			graphics.DrawImage(MyTexture->GetImage(),
				Gdiplus::Rect
				(
					Pos.x, Pos.y
					, MyTexture->GetWidth() * TScale.x * Scale.x
					, MyTexture->GetHeight() * TScale.y * Scale.y
				)
				, 0, 0
				, MyTexture->GetWidth() * TScale.x * Scale.x
				, MyTexture->GetHeight() * TScale.y * Scale.y
				, Gdiplus::UnitPixel
				, nullptr
			);
		}
	}
}