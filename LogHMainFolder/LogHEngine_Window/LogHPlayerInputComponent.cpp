#include "LogHPlayerInputComponent.h"
#include "LogHAnimator.h"
#include "LogHInput.h"
#include "LogHTime.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	PlayerInputComponent::PlayerInputComponent()
		: State(E_State::Idle)
		, Direction(E_Direction::Right)
		, MyAnimator(nullptr)
	{
	}

	PlayerInputComponent::~PlayerInputComponent()
	{
		SAFE_DELETE(MyAnimator);
	}

	void PlayerInputComponent::Initialize()
	{
	}

	void PlayerInputComponent::Update()
	{
		if (!MyAnimator)
		{
			MyAnimator = GetOwner()->GetComponent<Animator>();
			MyAnimator->PlayAnimation(L"RightIdle", false);
		}

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

	void PlayerInputComponent::LateUpdate()
	{
	}

	void PlayerInputComponent::Render(HDC Hdc)
	{
	}

	void PlayerInputComponent::IdleState()
	{
		if (Input::GetKeyPressed(E_KeyCode::Left))
		{
			State = E_State::Walk;
			Direction = E_Direction::Left;
			MyAnimator->PlayAnimation(L"LeftMove");
		}
		if (Input::GetKeyPressed(E_KeyCode::Right))
		{
			State = E_State::Walk;
			Direction = E_Direction::Right;
			MyAnimator->PlayAnimation(L"RightMove");
		}
		if (Input::GetKeyPressed(E_KeyCode::Up))
		{
			State = E_State::Walk;
			if(Direction == E_Direction::Right)
				MyAnimator->PlayAnimation(L"RightJump");
			else
				MyAnimator->PlayAnimation(L"LeftJump");
		}
		if (Input::GetKeyPressed(E_KeyCode::Down))
		{
			State = E_State::Walk;
			if (Direction == E_Direction::Right)
				MyAnimator->PlayAnimation(L"RightCrounch", false);
			else
				MyAnimator->PlayAnimation(L"LeftCrounch", false);
		}
	}

	void PlayerInputComponent::WalkState()
	{
		const int Speed = 100.f;
		const float DeltaTime = Time::GetDeltaTime();

		TransformComponent* MyTransform = GetOwner()->GetComponent<TransformComponent>();
		Vector2 pos = MyTransform->GetPosition();

		if (Input::GetKeyPressed(E_KeyCode::Left))
		{
			pos.x -= Speed * DeltaTime;
		}
		else if (Input::GetKeyPressed(E_KeyCode::Right))
		{
			pos.x += Speed * DeltaTime;
		}
		else if (Input::GetKeyPressed(E_KeyCode::Up))
		{
			pos.y -= Speed * DeltaTime;
		}
		else if (Input::GetKeyPressed(E_KeyCode::Down))
		{
			pos.y += Speed * DeltaTime;
		}

		MyTransform->SetPosition(pos);

		if (Input::GetKeyUp(E_KeyCode::Left))
		{
			State = E_State::Idle;
			Direction = E_Direction::Left;
			MyAnimator->PlayAnimation(L"LeftIdle", false);
		}
		else if (Input::GetKeyUp(E_KeyCode::Right))
		{
			State = E_State::Idle;
			Direction = E_Direction::Right;
			MyAnimator->PlayAnimation(L"RightIdle", false);
		}
		else if (Input::GetKeyUp(E_KeyCode::Up))
		{
			State = E_State::Idle;
			if (Direction == E_Direction::Right)
				MyAnimator->PlayAnimation(L"RightIdle", false);
			else
				MyAnimator->PlayAnimation(L"LeftIdle", false);
		}
		else if (Input::GetKeyUp(E_KeyCode::Down))
		{
			State = E_State::Idle;
			if (Direction == E_Direction::Right)
				MyAnimator->PlayAnimation(L"RightIdle", false);
			else
				MyAnimator->PlayAnimation(L"LeftIdle", false);
		}
	}

	void PlayerInputComponent::DieState()
	{

	}

	void PlayerInputComponent::AttackState()
	{
		//이벤트 사용방법
		//MyAnimator->GetCompleteEvent(L"Attack") = bind(&PlayerInputComponent::Attack, this);
	}
}