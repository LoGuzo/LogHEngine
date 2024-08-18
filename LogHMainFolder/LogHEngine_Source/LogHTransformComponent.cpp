#include "LogHTransformComponent.h"

namespace LogH
{
	TransformComponent::TransformComponent()
		: Component(Enums::E_ComponentType::Transform)
		, MPosition(Vector2::One)
		, MScale(Vector2::One)
		, MRotation(0.f)
	{
	}

	TransformComponent::~TransformComponent()
	{
	}

	void TransformComponent::Initialize()
	{
	}

	void TransformComponent::Update()
	{

	}

	void TransformComponent::LateUpdate()
	{
	}

	void TransformComponent::Render(HDC Hdc)
	{
	}
}