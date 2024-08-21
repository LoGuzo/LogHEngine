#pragma once
#include "LogHInputComponent.h"

namespace LogH
{
	class MushScriptComponent : public InputComponent
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

		MushScriptComponent();
		~MushScriptComponent();

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

		void FSM();

		void MoveByDirection();

	private:
		class TransformComponent* MyTransform;

		E_State State;
		E_Direction Direction;
		class Animator* MyAnimator;

		float EndTime;
	};
}