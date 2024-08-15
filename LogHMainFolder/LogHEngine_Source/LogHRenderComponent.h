#pragma once
#include "LogHComponent.h"

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

	private:

    };
}