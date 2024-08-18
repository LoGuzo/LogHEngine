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

		PlayerInputComponent();
		~PlayerInputComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

	private:
		void IdleState();
		void WalkState();
		void DieState();
		void AttackState();

	private:
		E_State State;
		class Animator* MyAnimator;
    };
}