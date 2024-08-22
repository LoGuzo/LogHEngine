#include "LogHCameraScriptComponent.h"
#include "LogHAnimator.h"
#include "LogHInput.h"
#include "LogHTime.h"
#include "LogHTransformComponent.h"
#include "LogHShapeComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	CameraScriptComponent::CameraScriptComponent()
	{
	}
	CameraScriptComponent::~CameraScriptComponent()
	{
	}
	void CameraScriptComponent::Initialize()
	{
	}
	void CameraScriptComponent::Update()
	{
		const int Speed = 100.f;
		const float DeltaTime = Time::GetDeltaTime();

		TransformComponent* MyTransform = GetOwner()->GetComponent<TransformComponent>();
		Vector2 Pos = MyTransform->GetPosition();

		if (Input::GetKeyPressed(E_KeyCode::Left))
		{
			Pos += Vector2::Left * (Speed * DeltaTime);
		}
		else if (Input::GetKeyPressed(E_KeyCode::Right))
		{
			Pos += Vector2::Right * (Speed * DeltaTime);
		}
		else if (Input::GetKeyPressed(E_KeyCode::Up))
		{
			Pos += Vector2::Up * (Speed * DeltaTime);
		}
		else if (Input::GetKeyPressed(E_KeyCode::Down))
		{
			Pos += Vector2::Down * (Speed * DeltaTime);
		}

		MyTransform->SetPosition(Pos);
	}
	void CameraScriptComponent::LateUpdate()
	{
	}
	void CameraScriptComponent::Render(HDC Hdc)
	{
	}
}