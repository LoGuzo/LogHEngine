#pragma once
#include "LogHInputComponent.h"

namespace LogH
{
	class CameraScriptComponent : public InputComponent
	{
	public:
		CameraScriptComponent();
		~CameraScriptComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

	private:

	};
}