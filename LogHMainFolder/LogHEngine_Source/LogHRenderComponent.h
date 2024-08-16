#pragma once
#include "LogHComponent.h"
#include "LogHTexture.h"

namespace LogH
{
    class RenderComponent : public Component
    {
	public:
		RenderComponent();
		~RenderComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		void SetTexture(Graphics::Texture* _Texture) { MTexture = _Texture; }
		void SetSize(Math::Vector2 _TScale) { TScale = _TScale; }

	private:
		Graphics::Texture* MTexture;
		Math::Vector2 TScale;
    };
}