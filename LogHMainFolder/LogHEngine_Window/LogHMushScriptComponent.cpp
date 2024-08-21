#include "LogHMushScriptComponent.h"
#include "LogHAnimator.h"
#include "LogHInput.h"
#include "LogHTime.h"
#include "LogHTransformComponent.h"
#include "LogHShapeComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	MushScriptComponent::MushScriptComponent()
		: State(E_State::Idle)
		, Direction(E_Direction::Right)
		, MyAnimator(nullptr)
		, MyTransform(nullptr)
		, EndTime(Time::GetDeltaTime())
	{
	}

	MushScriptComponent::~MushScriptComponent()
	{
	}

	void MushScriptComponent::Initialize()
	{
		MyTransform = GetOwner()->GetComponent<TransformComponent>();
	}

	void MushScriptComponent::Update()
	{
		if (!MyAnimator)
		{
			MyAnimator = GetOwner()->GetComponent<Animator>();
			MyAnimator->PlayAnimation(L"Idle", false);
		}
		//FSM();
	}

	void MushScriptComponent::LateUpdate()
	{
	}

	void MushScriptComponent::Render(HDC Hdc)
	{
	}

	void MushScriptComponent::OnCollisionOnEnter(ShapeComponent* Other)
	{
	}

	void MushScriptComponent::OnCollisionOnStay(ShapeComponent* Other)
	{
	}

	void MushScriptComponent::OnCollisionOnExit(ShapeComponent* Other)
	{
	}

	void MushScriptComponent::IdleState()
	{
		EndTime += Time::GetDeltaTime();

		if (EndTime > 3.f)
		{
			int NewDirection = (rand() % 2);
			Direction = (E_Direction)NewDirection;

			State = E_State::Walk;
			MyAnimator->PlayAnimation(L"Walk");

			EndTime = 0.f;
		}
	}

	void MushScriptComponent::WalkState()
	{
		const int Speed = 100.f;
		const float DeltaTime = Time::GetDeltaTime();

		EndTime += Time::GetDeltaTime();

		if (EndTime > 2.f)
		{
			State = E_State::Idle;
			MyAnimator->PlayAnimation(L"Idle", false);
			EndTime = 0.f;
		}

		Vector2 Pos = MyTransform->GetPosition();

		switch (Direction)
		{
		case E_Direction::Left:
			Pos += Vector2::Left * (Speed * DeltaTime);
			break;
		case E_Direction::Right:
			Pos += Vector2::Right * (Speed * DeltaTime);
			break;
		default:
			break;
		}

		MyTransform->SetPosition(Pos);
	}

	void MushScriptComponent::DieState()
	{

	}

	void MushScriptComponent::AttackState()
	{

	}
	void MushScriptComponent::FSM()
	{

		switch (State)
		{
		case E_State::Idle:
			IdleState();
			break;
		case E_State::Walk:
			WalkState();
			break;
		case E_State::Die:
			DieState();
			break;
		case E_State::Attack:
			AttackState();
			break;
		default:
			break;
		}
	}
}