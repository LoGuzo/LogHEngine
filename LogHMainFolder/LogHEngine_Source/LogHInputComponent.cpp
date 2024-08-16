#include "LogHInputComponent.h"
#include "LogHInput.h"
#include "LogHTime.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	InputComponent::InputComponent()
		: Component(Enums::E_ComponentType::Input)
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
		const int Speed = 100.f;
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

		MyTransform->SetPosition(pos);
	}

	void InputComponent::LateUpdate()
	{
	}

	void InputComponent::Render(HDC Hdc)
	{
	}
}