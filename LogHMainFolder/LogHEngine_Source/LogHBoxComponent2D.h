#pragma once
#include "LogHShapeComponent.h"

namespace LogH
{
	class BoxComponent2D : public ShapeComponent
	{
	public:
		BoxComponent2D();
		~BoxComponent2D();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

	private:

	};
}