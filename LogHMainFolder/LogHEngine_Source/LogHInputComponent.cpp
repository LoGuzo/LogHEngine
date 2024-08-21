#include "LogHInputComponent.h"


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
		
	}

	void InputComponent::LateUpdate()
	{
	}

	void InputComponent::Render(HDC Hdc)
	{
	}
	void InputComponent::OnCollisionOnEnter(ShapeComponent* Other)
	{
	}
	void InputComponent::OnCollisionOnStay(ShapeComponent* Other)
	{
	}
	void InputComponent::OnCollisionOnExit(ShapeComponent* Other)
	{
	}
}