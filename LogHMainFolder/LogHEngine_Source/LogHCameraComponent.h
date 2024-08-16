#pragma once
#include "LogHComponent.h"

namespace LogH
{
	using namespace Math;
    class CameraComponent : public Component
    {
	public:
		Vector2 CaluatePosition(Vector2 pos) { return pos - Distance; }

		CameraComponent();
		~CameraComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

	private:
		Vector2 Distance;
		Vector2 Resolution;
		Vector2 LookPosition;

		class GameObject* Target;
    };
}