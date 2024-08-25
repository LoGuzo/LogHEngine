#pragma once
#include "LogHComponent.h"

namespace LogH
{
    class RigidbodyComponent : public Component
    {
	public:
		RigidbodyComponent();
		~RigidbodyComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;


		void SetIsGround(bool _IsGround) { bIsGround = _IsGround; }
		bool GetIsGround() { return bIsGround; }

		void SetMass(float _Mass) { Mass = _Mass; }
		void SetForce(Vector2 _Force) { Force = _Force; }
		void SetGravity(Vector2 _Gravity) { Gravity = _Gravity; }

		Vector2 GetVelocity() { return Velocity; }
		void SetVelocity(Vector2 _Velocity) { Velocity = _Velocity; }

	private:
		bool bIsGround;

		float Mass;
		float Friction;

		Vector2 Force;
		Vector2 Accelation;
		Vector2 Velocity;
		Vector2 LimitVelocity;
		Vector2 Gravity;
    };
}