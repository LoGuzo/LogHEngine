#pragma once
#include "LogHComponent.h"
#include "LogHTexture.h"

namespace LogH
{
    class RenderComponent : public Component
    {
	public:
		RenderComponent();
		virtual ~RenderComponent();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC Hdc);

		void SetTexture(Graphics::Texture* _Texture) { MTexture = _Texture; }
		void SetSize(Math::Vector2 _TScale) { TScale = _TScale; }

	private:
		Graphics::Texture* MTexture;
		Math::Vector2 TScale;
    };
}