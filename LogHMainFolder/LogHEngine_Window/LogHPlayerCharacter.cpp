#include "LogHPlayerCharacter.h"
#include "LogHPlayerInputComponent.h"
#include "LogHRenderer.h"
#include "LogHResourceManager.h"


namespace LogH
{
	PlayerCharacter::PlayerCharacter()
	{
		AddComponent<PlayerInputComponent>(L"InputComponent");
	}

	PlayerCharacter::~PlayerCharacter()
	{
		SAFE_DELETE(CharTexture);
		SAFE_DELETE(FlipCharTexture);
		SAFE_DELETE(MyAnimator);
	}

	void PlayerCharacter::Initialize()
	{
		Character::Initialize();

		CharTexture = ResourceManager::Find<Graphics::Texture>(L"Player");
		FlipCharTexture = ResourceManager::Find<Graphics::Texture>(L"FlipPlayer");
		MyAnimator = AddComponent<Animator>(L"Animator");

		AddIdleAnim();
		AddMoveAnim();
		AddAttackAnim();
		AddDieAnim();
		//MyAnimator->PlayAnimation(L"RightMove");
	}

	void PlayerCharacter::Update()
	{
		Character::Update();
	}

	void PlayerCharacter::LateUpdate()
	{
		Character::LateUpdate();
	}

	void PlayerCharacter::Render(HDC Hdc)
	{
		Character::Render(Hdc);
	}

	void PlayerCharacter::AddIdleAnim()
	{
		MyAnimator->CreateAnimation(L"RightIdle", CharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(134.8f, 0.f), Vector2(67.4f, 72.f), Vector2::Zero, 1, 0.1f);

		MyAnimator->CreateAnimation(L"LeftIdle", FlipCharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(134.8f, 0.f), Vector2(67.4f, 72.f), Vector2::Zero, 1, 0.1f);

		MyAnimator->CreateAnimation(L"DownIdle", CharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(269.6f, 0.f), Vector2(67.4f, 72.f), Vector2::Zero, 1, 0.1f);

		MyAnimator->CreateAnimation(L"UpIdle", CharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(0.f, 0.f), Vector2(67.4f, 72.f), Vector2::Zero, 1, 0.1f);
	}

	void PlayerCharacter::AddMoveAnim()
	{
		MyAnimator->CreateAnimation(L"RightMove", CharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(134.8f, 0.f), Vector2(67.4f, 72.f), Vector2::Zero, 5, 0.1f);

		MyAnimator->CreateAnimation(L"LeftMove", FlipCharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(134.8f, 0.f), Vector2(67.4f, 72.f), Vector2::Zero, 5, 0.1f);

		MyAnimator->CreateAnimation(L"DownMove", CharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(269.6f, 0.f), Vector2(67.4f, 72.f), Vector2::Zero, 5, 0.1f);

		MyAnimator->CreateAnimation(L"UpMove", CharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(0.f, 0.f), Vector2(67.4f, 72.f), Vector2::Zero, 5, 0.1f);
	}

	void PlayerCharacter::AddAttackAnim()
	{
		MyAnimator->CreateAnimation(L"RightAttack", CharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(134.8f, 350.f), Vector2(67.4f, 72.f), Vector2::Zero, 4, 0.1f);

		MyAnimator->CreateAnimation(L"LeftAttack", FlipCharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(134.8f, 350.f), Vector2(67.4f, 72.f), Vector2::Zero, 4, 0.1f);

		MyAnimator->CreateAnimation(L"DownAttack", CharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(269.6f, 350.f), Vector2(67.4f, 72.f), Vector2::Zero, 4, 0.1f);

		MyAnimator->CreateAnimation(L"UpAttack", CharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(0.f, 350.f), Vector2(67.4f, 72.f), Vector2::Zero, 4, 0.1f);
	}

	void PlayerCharacter::AddDieAnim()
	{
		MyAnimator->CreateAnimation(L"RightDie", CharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(134.8f, 630.f), Vector2(67.4f, 72.f), Vector2::Zero, 3, 0.5f);

		MyAnimator->CreateAnimation(L"LeftDie", FlipCharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(134.8f, 630.f), Vector2(67.4f, 72.f), Vector2::Zero, 3, 0.5f);

		MyAnimator->CreateAnimation(L"DownDie", CharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(269.6f, 630.f), Vector2(67.4f, 72.f), Vector2::Zero, 3, 0.5f);

		MyAnimator->CreateAnimation(L"UpDie", CharTexture
			, Enums::E_AnimDirectionType::UpDown
			, Vector2(0.f, 630.f), Vector2(67.4f, 72.f), Vector2::Zero, 3, 0.5f);
	}
}