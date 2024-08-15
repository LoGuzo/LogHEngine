#pragma once
#include "LogHComponent.h"

namespace LogH
{
	class TransformComponent : public Component
	{
	public:
		TransformComponent();
		virtual ~TransformComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		void SetPosition(float x, float y) { Mx = x; My = y; }

		float GetPositionX() { return Mx; }
		float GetPositionY() { return My; }

	private:
		float Mx;
		float My;
	};
}