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
			TransformComponent* Tc = Target->GetComponent<TransformComponent>();
			TransformComponent* CameraTc = GetOwner()->GetComponent<TransformComponent>();

			LookPosition = Vector2(Tc->GetPosition().x, CameraTc->GetPosition().y);
			CameraTc->SetPosition(LookPosition);
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