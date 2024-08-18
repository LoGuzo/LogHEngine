#pragma once
#include "LogHComponent.h"

namespace LogH
{
	using namespace Math;
	class TransformComponent : public Component
	{
	public:
		TransformComponent();
		~TransformComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		void SetPosition(Vector2 Position) { MPosition.x = Position.x; MPosition.y = Position.y; }
		Vector2 GetPosition() { return MPosition; }

		void SetScale(Vector2 Scale) { MScale.x = Scale.x; MScale.y = Scale.y; }
		Vector2 GetScale() { return MScale; }

		void SetRotation(float Rotation) { MRotation = Rotation; }
		float GetRotation() { return MRotation; }

	private:
		Vector2 MPosition;
		Vector2 MScale;
		float MRotation;
	};
}