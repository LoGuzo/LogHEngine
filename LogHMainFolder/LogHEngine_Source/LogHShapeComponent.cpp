#include "LogHShapeComponent.h"
#include "LogHInputComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	UINT32 ShapeComponent::CollisionID = 1;

	ShapeComponent::ShapeComponent(Enums::E_ColliderType _Type)
		: Component(Enums::E_ComponentType::Collider)
		, Type(_Type)
		, ID(ID++)
		, Size(Vector2::One)
	{
	}

	ShapeComponent::~ShapeComponent()
	{
	}

	void ShapeComponent::Initialize()
	{
	}

	void ShapeComponent::Update()
	{
	}

	void ShapeComponent::LateUpdate()
	{
	}

	void ShapeComponent::Render(HDC Hdc)
	{
	}

	void ShapeComponent::OnCollisionOnEnter(ShapeComponent* Other)
	{
		InputComponent* IC = GetOwner()->GetComponent<InputComponent>();
		IC->OnCollisionOnEnter(Other);
	}

	void ShapeComponent::OnCollisionOnStay(ShapeComponent* Other)
	{
		InputComponent* IC = GetOwner()->GetComponent<InputComponent>();
		IC->OnCollisionOnStay(Other);
	}

	void ShapeComponent::OnCollisionOnExit(ShapeComponent* Other)
	{
		InputComponent* IC = GetOwner()->GetComponent<InputComponent>();
		IC->OnCollisionOnExit(Other);
	}
}