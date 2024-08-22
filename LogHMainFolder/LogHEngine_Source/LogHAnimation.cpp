#include "LogHAnimation.h"
#include "LogHAnimator.h"
#include "LogHTime.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"
#include "LogHRenderer.h"

namespace LogH
{
	Animation::Animation()
		: Resource(Enums::E_ResourceType::Animation)
		, MyAnimator(nullptr)
		, MyTexture(nullptr)
		, MyAnimation{}
		, Index(-1)
		, CycleTime(0.f)
		, bComplete(false)
	{
	}

	Animation::~Animation()
	{
	}

	HRESULT Animation::Load(const wstring& _Path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if (bComplete)
			return;
		
		CycleTime += Time::GetDeltaTime();

		if (MyAnimation[Index].Duration < CycleTime)
		{
			CycleTime = 0.f;
			if (Index < MyAnimation.size() - 1)
				Index++;
			else
				bComplete = true;
		}
	}

	void Animation::Render(HDC Hdc)
	{
		if (!MyTexture)
			return;

		GameObject* GameObj = MyAnimator->GetOwner();
		TransformComponent* Tc = GameObj->GetComponent<TransformComponent>();
		Vector2 Pos = Tc->GetPosition();
		Vector2 Scale = Tc->GetScale();
		float Rotation = Tc->GetRotation();

		Texture::E_TextureType type = MyTexture->GetTextureType();
		Sprite sprite = MyAnimation[Index];

		if (type == Texture::E_TextureType::Bmp)
		{
			HDC ImgHdc = MyTexture->GetHdc();

			if (MyTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255;

				AlphaBlend(Hdc, Pos.x - (sprite.Size.x / 2.f) + sprite.Root.x
					, Pos.y - (sprite.Size.y / 2.f) + sprite.Root.y
					, sprite.Size.x * Scale.x, sprite.Size.y * Scale.y
					, ImgHdc, sprite.LeftTop.x, sprite.LeftTop.y
					, sprite.Size.x, sprite.Size.y
					, func);
			}
			else
			{
				TransparentBlt(Hdc, Pos.x - (sprite.Size.x / 2.f) + sprite.Root.x
					, Pos.y - (sprite.Size.y / 2.f) + sprite.Root.y
					, sprite.Size.x * Scale.x, sprite.Size.y * Scale.y
					, ImgHdc, sprite.LeftTop.x, sprite.LeftTop.y
					, sprite.Size.x, sprite.Size.y
					, RGB(255, 0, 255));
			}

		}
		else if (type == Texture::E_TextureType::Png)
		{
			Gdiplus::ImageAttributes ImgAttribute = {};
			ImgAttribute.SetColorKey(Gdiplus::Color(147, 187, 236), Gdiplus::Color(147, 187, 236));

			Gdiplus::Graphics graphics(Hdc);

			//graphics.TranslateTransform(Pos.x,Pos.y);
			//graphics.RotateTransform(Rotation);
			//graphics.TranslateTransform(-Pos.x, Pos.y);

			graphics.DrawImage(MyTexture->GetImage()
				,Gdiplus::Rect
				{
					(INT)(Pos.x - (sprite.Size.x / 2.f)), (INT)(Pos.y - (sprite.Size.y / 2.f))
					, (INT)(sprite.Size.x * Scale.x), (INT)(sprite.Size.y * Scale.y)
				}
				, sprite.LeftTop.x
				, sprite.LeftTop.y
				, sprite.Size.x
				, sprite.Size.y
				, Gdiplus::UnitPixel
				, &ImgAttribute
			);
		}
	}

	void Animation::CreateAnimation(const wstring& Name
		, Texture* SpriteSheet
		, Vector2 LeftTop
		, Vector2 Size, Vector2 Root
		, UINT SpriteLen, float Duration)
	{
		MyTexture = SpriteSheet;
		for (size_t i = 0; i < SpriteLen; i++)
		{
			Sprite sprite = {};
			sprite.LeftTop.x = LeftTop.x + (Size.x * i) + i;
			sprite.LeftTop.y = LeftTop.y;
			sprite.Size = Size;
			sprite.Root = Root;
			sprite.Duration = Duration;

			MyAnimation.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		CycleTime = 0.f;
		Index = 0;
		bComplete = false;
	}
}