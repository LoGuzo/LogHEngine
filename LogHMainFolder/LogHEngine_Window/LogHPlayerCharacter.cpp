#include "LogHPlayerCharacter.h"
#include "LogHResourceManager.h"
#include "LogHRigidbodyComponent.h"

namespace LogH
{
	PlayerCharacter::PlayerCharacter()
		: BaseCharacter(Enums::E_CharacterType::Player)
	{
		AddComponent<RigidbodyComponent>(L"Rigidbody");
	}

	PlayerCharacter::~PlayerCharacter()
	{
	}

	void PlayerCharacter::Initialize()
	{
		CharTexture = ResourceManager::Find<Graphics::Texture>(L"Mario");
		FlipTexture = ResourceManager::Find<Graphics::Texture>(L"MarioFlip");
		MyAnimator = AddComponent<Animator>(L"Animator");
		
		BaseCharacter::Initialize();
	}

	void PlayerCharacter::Update()
	{
		BaseCharacter::Update();
	}

	void PlayerCharacter::LateUpdate()
	{
		BaseCharacter::LateUpdate();
	}

	void PlayerCharacter::Render(HDC Hdc)
	{
		BaseCharacter::Render(Hdc);
	}

	void PlayerCharacter::AddIdleAnim()
	{
	}

	void PlayerCharacter::AddMoveAnim()
	{
	}

	void PlayerCharacter::AddAttackAnim()
	{
	}

	void PlayerCharacter::AddDieAnim()
	{
	}
}