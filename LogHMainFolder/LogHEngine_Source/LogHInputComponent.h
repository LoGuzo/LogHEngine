#pragma once
#include "LogHComponent.h"

namespace LogH
{
    class InputComponent : public Component
    {
	public:
		InputComponent();
		virtual ~InputComponent();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC Hdc);

	private:
    };
}