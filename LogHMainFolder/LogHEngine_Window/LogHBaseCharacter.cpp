#include "LogHBaseCharacter.h"

namespace LogH
{
	BaseCharacter::BaseCharacter(Enums::E_CharacterType _Type)
		: CharTexture(nullptr)
		, FlipTexture(nullptr)
		, MyAnimator(nullptr)
	{
	}

	BaseCharacter::~BaseCharacter()
	{
		SAFE_DELETE(CharTexture);
		SAFE_DELETE(FlipTexture);
		SAFE_DELETE(MyAnimator);
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