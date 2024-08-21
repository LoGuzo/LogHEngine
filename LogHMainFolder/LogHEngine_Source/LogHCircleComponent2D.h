#pragma once
#include "LogHShapeComponent.h"

namespace LogH
{
	class CircleComponent2D : ShapeComponent
	{
	public:
		CircleComponent2D();
		~CircleComponent2D();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

	private:
		float Radius;
	};
}