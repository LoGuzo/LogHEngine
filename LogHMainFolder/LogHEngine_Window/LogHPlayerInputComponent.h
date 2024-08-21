#pragma once
#include "LogHInputComponent.h"

namespace LogH
{
    class PlayerInputComponent : public InputComponent
    {
    public:
		enum class E_State
		{
			Idle,
			Walk,
			Die,
			Attack,
		};

		enum class E_Direction
		{
			Left,
			Right,
		};

		PlayerInputComponent();
		~PlayerInputComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		virtual void OnCollisionOnEnter(ShapeComponent* Other) override;
		virtual void OnCollisionOnStay(ShapeComponent* Other) override;
		virtual void OnCollisionOnExit(ShapeComponent* Other) override;

	private:
		void IdleState();
		void WalkState();
		void DieState();
		void AttackState();

	private:
		E_State State;
		E_Direction Direction;
		class Animator* MyAnimator;
    };
}