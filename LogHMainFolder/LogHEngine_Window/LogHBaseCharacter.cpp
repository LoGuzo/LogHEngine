#include "LogHBaseCharacter.h"
#include "LogHRigidbodyComponent.h"

namespace LogH
{
	BaseCharacter::BaseCharacter(Enums::E_CharacterType _Type)
		: CharTexture(nullptr)
		, FlipTexture(nullptr)
		, MyAnimator(nullptr)
	{
		AddComponent<RigidbodyComponent>(L"Rigidbody");
	}

	BaseCharacter::~BaseCharacter()
	{
	}

	void BaseCharacter::Initialize()
	{
		Character::Initialize();

		AddIdleAnim();
		AddMoveAnim();
		AddAttackAnim();
		AddDieAnim();
	}

	void BaseCharacter::Update()
	{
		Character::Update();
	}

	void BaseCharacter::LateUpdate()
	{
		Character::LateUpdate();
	}

	void BaseCharacter::Render(HDC Hdc)
	{
		Character::Render(Hdc);
	}

	void BaseCharacter::AddIdleAnim()
	{
	}

	void BaseCharacter::AddMoveAnim()
	{
	}

	void BaseCharacter::AddAttackAnim()
	{
	}

	void BaseCharacter::AddDieAnim()
	{
	}
}