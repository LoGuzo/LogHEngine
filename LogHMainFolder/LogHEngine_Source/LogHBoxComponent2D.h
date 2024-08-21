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

		Vector2 GetSize() { return Size; }
		void SetSize(Vector2 _Size) { Size = _Size; }

	private:
		Vector2 Size;
	};
}