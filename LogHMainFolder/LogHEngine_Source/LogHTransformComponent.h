#pragma once
#include "LogHComponent.h"

namespace LogH
{
	using namespace Math;
	class TransformComponent : public Component
	{
	public:
		TransformComponent();
		virtual ~TransformComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		void SetPosition(Vector2 Position) { MPosition.x = Position.x; MPosition.y = Position.y; }

		Vector2 GetPosition() { return MPosition; }

	private:
		Vector2 MPosition;
	};
}