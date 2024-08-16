#include "LogHCameraComponent.h"
#include "LogHGameObject.h"
#include "LogHTransformComponent.h"
#include "LogHApplication.h"

extern LogH::Application App;

namespace LogH
{
	CameraComponent::CameraComponent()
		: Component(Enums::E_ComponentType::Camera)
		, Distance(Vector2::Zero)
		, Resolution(Vector2::Zero)
		, LookPosition(Vector2::Zero)
		, Target(nullptr)
	{
	}

	CameraComponent::~CameraComponent()
	{
		SAFE_DELETE(Target);
	}

	void CameraComponent::Initialize()
	{
		Resolution.x = App.GetWidth();
		Resolution.y = App.GetHeight();
	}

	void CameraComponent::Update()
	{
		if (Target)
		{
			TransformComponent* tc = Target->GetComponent<TransformComponent>();
			LookPosition = tc->GetPosition();
		}
		else
		{
			TransformComponent* CameraTc = GetOwner()->GetComponent<TransformComponent>();
			LookPosition = CameraTc->GetPosition();
		}
		
		Distance = LookPosition - (Resolution / 2.f);
	}

	void CameraComponent::LateUpdate()
	{
	}

	void CameraComponent::Render(HDC Hdc)
	{
	}
}