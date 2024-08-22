#include "LogHTilemapRender.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"
#include "LogHTexture.h"
#include "LogHRenderer.h"

namespace LogH
{
	Vector2 TilemapRender::FinalTileSize = Vector2::One;
	Vector2 TilemapRender::OriginTileSize = Vector2::One;
	Vector2 TilemapRender::SelectedIndex = Vector2(-1.f,-1.f);

	TilemapRender::TilemapRender()
		: Component(Enums::E_ComponentType::Renderer)
		, MyTexture(nullptr)
		, TScale(Vector2::One)
		, Index(Vector2::One)
		, TileSize(Vector2(16.f, 16.f))
	{
		SetScale(Vector2(1.5f, 1.5f));
		FinalTileSize = TileSize * TScale;
		OriginTileSize = TileSize;
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
			Pos = Renderer::MainCamera->CalculatePosition(Pos);

		if (MyTexture->GetTextureType() == Graphics::Texture::E_TextureType::Bmp)
		{
			TransparentBlt(Hdc, Pos.x, Pos.y
				, FinalTileSize.x * Scale.x, FinalTileSize.y * Scale.y
				, MyTexture->GetHdc(), Index.x * TileSize.x + Index.x, Index.y * TileSize.y + Index.y, 16, 16
				, RGB(147, 187, 236));
		}
	}
}