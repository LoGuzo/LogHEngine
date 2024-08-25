#include "LogHPlayerInputComponent.h"
#include "LogHAnimator.h"
#include "LogHInput.h"
#include "LogHTime.h"
#include "LogHTransformComponent.h"
#include "LogHRigidbodyComponent.h"
#include "LogHShapeComponent.h"
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

	void PlayerInputComponent::OnCollisionOnEnter(ShapeComponent* Other)
	{
	}

	void PlayerInputComponent::OnCollisionOnStay(ShapeComponent* Other)
	{
	}

	void PlayerInputComponent::OnCollisionOnExit(ShapeComponent* Other)
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
		Vector2 Pos = MyTransform->GetPosition();

		RigidbodyComponent* Rc = GetOwner()->GetComponent<RigidbodyComponent>();

		if (Input::GetKeyPressed(E_KeyCode::Left))
		{
			Rc->SetForce(Vector2(-100.f, 0.f));
		}
		else if (Input::GetKeyPressed(E_KeyCode::Right))
		{
			Rc->SetForce(Vector2(100.f, 0.f));
		}
		else if (Input::GetKeyPressed(E_KeyCode::Up))
		{
			Vector2 velocity = Rc->GetVelocity();
			velocity.y = -400.f;
			Rc->SetVelocity(velocity);

			Rc->SetIsGround(false);
		}
		/*else if (Input::GetKeyPressed(E_KeyCode::Down))
		{
			Rc->SetForce(Vector2(0.f, 100.f));
		}*/

		PlayerKeyUP();
	}

	void PlayerInputComponent::DieState()
	{

	}

	void PlayerInputComponent::AttackState()
	{
		//이벤트 사용방법
		//MyAnimator->GetCompleteEvent(L"Attack") = bind(&PlayerInputComponent::Attack, this);
	}

	void PlayerInputComponent::PlayerKeyUP()
	{
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
}