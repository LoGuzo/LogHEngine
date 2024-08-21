#pragma once

#include "LogHComponent.h"
#include "LogHTexture.h"

namespace LogH
{
	class TilemapRender : public Component
	{
	public:
		TilemapRender();
		~TilemapRender();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		void SetTexture(Graphics::Texture* _Texture) { MyTexture = _Texture; }
		void SetSize(Vector2 _TScale) { TScale = _TScale; }

	private:
		Graphics::Texture* MyTexture;
		Vector2 TScale;

		Vector2 TileSize;
		Vector2 Index;
	};
}

