#pragma once
#include "LogHComponent.h"

namespace LogH
{
    class InputComponent : public Component
    {
	public:
		InputComponent();
		~InputComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

	private:
    };
}