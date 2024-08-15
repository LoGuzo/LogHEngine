#include "LogHPlayerCharacter.h"


namespace LogH
{
	PlayerCharacter::PlayerCharacter()
	{
	}

	PlayerCharacter::~PlayerCharacter()
	{
	}

	void PlayerCharacter::Initialize()
	{
		Character::Initialize();
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
}