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
			MyAnimator = GetOwner()->GetComponent<Animator>();

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
		/*const int Speed = 100.f;
		const float DeltaTime = Time::GetDeltaTime();

		TransformComponent* MyTransform = GetOwner()->GetComponent<TransformComponent>();
		Vector2 pos = MyTransform->GetPosition();

		if (Input::GetKeyPressed(E_KeyCode::Left))
		{
			pos.x -= Speed * DeltaTime;
		}
		if (Input::GetKeyPressed(E_KeyCode::Right))
		{
			pos.x += Speed * DeltaTime;
		}
		if (Input::GetKeyPressed(E_KeyCode::Up))
		{
			pos.y -= Speed * DeltaTime;
		}
		if (Input::GetKeyPressed(E_KeyCode::Down))
		{
			pos.y += Speed * DeltaTime;
		}

		MyTransform->SetPosition(pos);*/
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
			MyAnimator->PlayAnimation(L"LeftMove");
		}
		if (Input::GetKeyPressed(E_KeyCode::Right))
		{
			State = E_State::Walk;
			MyAnimator->PlayAnimation(L"RightMove");
		}
		if (Input::GetKeyPressed(E_KeyCode::Up))
		{
			State = E_State::Walk;
			MyAnimator->PlayAnimation(L"UpMove");
		}
		if (Input::GetKeyPressed(E_KeyCode::Down))
		{
			State = E_State::Walk;
			MyAnimator->PlayAnimation(L"DownMove");
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
			MyAnimator->PlayAnimation(L"LeftIdle", false);
		}
		else if (Input::GetKeyUp(E_KeyCode::Right))
		{
			State = E_State::Idle;
			MyAnimator->PlayAnimation(L"RightIdle", false);
		}
		else if (Input::GetKeyUp(E_KeyCode::Up))
		{
			State = E_State::Idle;
			MyAnimator->PlayAnimation(L"UpIdle", false);
		}
		else if (Input::GetKeyUp(E_KeyCode::Down))
		{
			State = E_State::Idle;
			MyAnimator->PlayAnimation(L"DownIdle", false);
		}
	}

	void PlayerInputComponent::DieState()
	{
		if (Input::GetKeyPressed(E_KeyCode::Left))
			State = E_State::Walk;
		if (Input::GetKeyPressed(E_KeyCode::Right))
			State = E_State::Walk;
		if (Input::GetKeyPressed(E_KeyCode::Up))
			State = E_State::Walk;
		if (Input::GetKeyPressed(E_KeyCode::Down))
			State = E_State::Walk;
	}

	void PlayerInputComponent::AttackState()
	{
		if (Input::GetKeyPressed(E_KeyCode::Left))
			State = E_State::Walk;
		if (Input::GetKeyPressed(E_KeyCode::Right))
			State = E_State::Walk;
		if (Input::GetKeyPressed(E_KeyCode::Up))
			State = E_State::Walk;
		if (Input::GetKeyPressed(E_KeyCode::Down))
			State = E_State::Walk;
	}
}