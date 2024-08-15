#include "LogHInputComponent.h"
#include "LogHInput.h"
#include "LogHTime.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	InputComponent::InputComponent()
	{
	}

	InputComponent::~InputComponent()
	{
	}

	void InputComponent::Initialize()
	{
	}

	void InputComponent::Update()
	{
		TransformComponent* MyTransform = GetOwner()->GetComponent<TransformComponent>();

		const int Speed = 100.f;
		const float DeltaTime = Time::GetDeltaTime();

		int Mx = MyTransform->GetPositionX(), My = MyTransform->GetPositionY();

		if (Input::GetKeyPressed(E_KeyCode::Left))
		{
			Mx -= Speed * DeltaTime;
		}
		if (Input::GetKeyPressed(E_KeyCode::Right))
		{
			Mx += Speed * DeltaTime;
		}
		if (Input::GetKeyPressed(E_KeyCode::Up))
		{
			My -= Speed * DeltaTime;
		}
		if (Input::GetKeyPressed(E_KeyCode::Down))
		{
			My += Speed * DeltaTime;
		}

		MyTransform->SetPosition(Mx, My);
	}

	void InputComponent::LateUpdate()
	{
	}

	void InputComponent::Render(HDC Hdc)
	{
	}
}