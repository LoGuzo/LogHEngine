#include "LogHTilemapRender.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"
#include "LogHTexture.h"
#include "LogHRenderer.h"

namespace LogH
{
	TilemapRender::TilemapRender()
		: Component(Enums::E_ComponentType::Renderer)
		, MyTexture(nullptr)
		, TScale(Vector2::One)
		, Index(Vector2::Zero)
		, TileSize(Vector2(16.f, 16.f))
	{
	}

	TilemapRender::~TilemapRender()
	{
	}

	void TilemapRender::Initialize()
	{
	}

	void TilemapRender::Update()
	{
	}

	void TilemapRender::LateUpdate()
	{
	}

	void TilemapRender::Render(HDC Hdc)
	{
		if (!MyTexture)
			assert(false);

		TransformComponent* MyTransform = GetOwner()->GetComponent<TransformComponent>();
		Vector2 Pos = MyTransform->GetPosition();
		Vector2 Scale = MyTransform->GetScale();
		float Rotation = MyTransform->GetRotation();

		if (Renderer::MainCamera)
			Pos = Renderer::MainCamera->CaluatePosition(Pos);

		if (MyTexture->GetTextureType() == Graphics::Texture::E_TextureType::Bmp)
		{
			TransparentBlt(Hdc, Pos.x, Pos.y
				, TileSize.x * TScale.x * Scale.x, TileSize.x * TScale.y * Scale.y
				, MyTexture->GetHdc(), Index.x * TileSize.x + Index.x, Index.y * TileSize.y + Index.y, 16, 16
				, RGB(147, 187, 236));
		}
	}
}