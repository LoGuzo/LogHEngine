#include "LogHTileScriptComponent.h"
#include "LogHRigidbodyComponent.h"
#include "LogHTransformComponent.h"
#include "LogHShapeComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	TileScriptComponent::TileScriptComponent()
	{
	}

	TileScriptComponent::~TileScriptComponent()
	{
	}

	void TileScriptComponent::Initialize()
	{
	}

	void TileScriptComponent::Update()
	{
	}

	void TileScriptComponent::LateUpdate()
	{
	}

	void TileScriptComponent::Render(HDC Hdc)
	{
	}

	void TileScriptComponent::OnCollisionOnEnter(ShapeComponent* Other)
	{
		RigidbodyComponent* PlayerRc = Other->GetOwner()->GetComponent<RigidbodyComponent>();
		TransformComponent* PlayerTc = Other->GetOwner()->GetComponent<TransformComponent>();
		ShapeComponent* PlayerCol = Other;

		RigidbodyComponent* TileRc = this->GetOwner()->GetComponent<RigidbodyComponent>();
		TransformComponent* TileTc = this->GetOwner()->GetComponent<TransformComponent>();
		ShapeComponent* TileCol = this->GetOwner()->GetComponent<ShapeComponent>();

		float Len = fabs(PlayerTc->GetPosition().y - TileTc->GetPosition().y);
		float Scale = fabs(PlayerCol->GetSize().y * 2.f - TileCol->GetSize().y * 2.f) + 1.f;

		if (Len < Scale)
		{
			Vector2 PlayerPos = PlayerTc->GetPosition();
			PlayerPos.y -= (Scale - Len) + 1.f;

			PlayerTc->SetPosition(PlayerPos);
		}

		PlayerRc->SetIsGround(true);
	}

	void TileScriptComponent::OnCollisionOnStay(ShapeComponent* Other)
	{
	}

	void TileScriptComponent::OnCollisionOnExit(ShapeComponent* Other)
	{
	}
}