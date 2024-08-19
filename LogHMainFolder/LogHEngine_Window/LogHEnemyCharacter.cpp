#include "LogHEnemyCharacter.h"
#include "LogHResourceManager.h"

namespace LogH
{
	EnemyCharacter::EnemyCharacter()
		: BaseCharacter(Enums::E_CharacterType::Enemy)
	{
	}

	EnemyCharacter::~EnemyCharacter()
	{
	}

	void EnemyCharacter::Initialize()
	{
		CharTexture = ResourceManager::Find<Graphics::Texture>(L"Enemy");
		FlipTexture = ResourceManager::Find<Graphics::Texture>(L"EnemyFlip");
		MyAnimator = AddComponent<Animator>(L"Animator");

		BaseCharacter::Initialize();
	}

	void EnemyCharacter::Update()
	{
		BaseCharacter::Update();
	}

	void EnemyCharacter::LateUpdate()
	{
		BaseCharacter::LateUpdate();
	}

	void EnemyCharacter::Render(HDC Hdc)
	{
		BaseCharacter::Render(Hdc);
	}

	void EnemyCharacter::AddIdleAnim()
	{
	}

	void EnemyCharacter::AddMoveAnim()
	{
	}

	void EnemyCharacter::AddAttackAnim()
	{
	}

	void EnemyCharacter::AddDieAnim()
	{
	}
}