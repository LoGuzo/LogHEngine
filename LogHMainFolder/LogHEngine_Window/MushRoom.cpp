#include "MushRoom.h"
#include "LogHMushScriptComponent.h"
#include "LogHTransformComponent.h"
#include "LogHBoxComponent2D.h"

namespace LogH
{
	MushRoom::MushRoom()
	{
		AddComponent<MushScriptComponent>(L"ScriptComponent");

		TransformComponent* Transform = GetComponent<TransformComponent>();
		Transform->SetScale(Vector2(1.5f, 1.5f));

		Vector2 scale = Transform->GetScale();

		BoxComponent2D* Collision = GetComponent<BoxComponent2D>();
		Collision->SetRoot(Vector2(-15.f, -25.f));
		Collision->SetSize(Vector2(12.f, 12.f) * scale);
	}

	MushRoom::~MushRoom()
	{
	}

	void MushRoom::Initialize()
	{
		EnemyCharacter::Initialize();
	}

	void MushRoom::Update()
	{
		EnemyCharacter::Update();
	}

	void MushRoom::LateUpdate()
	{
		EnemyCharacter::LateUpdate();
	}

	void MushRoom::Render(HDC Hdc)
	{
		EnemyCharacter::Render(Hdc);
	}

	void MushRoom::AddIdleAnim()
	{
		MyAnimator->CreateAnimation(L"Idle", CharTexture
			, Vector2(1.f, 1.f), Vector2(16.f, 32.f), Vector2::Zero, 1, 0.1f);
	}

	void MushRoom::AddMoveAnim()
	{
		MyAnimator->CreateAnimation(L"Walk", CharTexture
			, Vector2(1.f, 1.f), Vector2(16.f, 32.f), Vector2::Zero, 2, 0.1f);

		MyAnimator->CreateAnimation(L"Jump", CharTexture
			, Vector2(39.f, 1.f), Vector2(16.f, 32.f), Vector2::Zero, 2, 0.1f);
	}

	void MushRoom::AddAttackAnim()
	{
	}

	void MushRoom::AddDieAnim()
	{
		MyAnimator->CreateAnimation(L"Die", CharTexture
			, Vector2(98.f, 1.f), Vector2(16.f, 32.f), Vector2::Zero, 1, 0.1f);
	}
}