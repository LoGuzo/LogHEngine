#include "LogHTransformComponent.h"

namespace LogH
{
	TransformComponent::TransformComponent()
		: Component(Enums::E_ComponentType::Transform)
		, MPosition()
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