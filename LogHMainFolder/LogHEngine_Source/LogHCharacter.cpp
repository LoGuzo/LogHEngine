#include "LogHCharacter.h"

namespace LogH
{
	Character::Character()
	{

	}

	Character::~Character()
	{
	}

	void Character::Initialize()
	{
		Pawn::Initialize();
	}

	void Character::Update()
	{
		Pawn::Update();
	}

	void Character::LateUpdate()
	{
		Pawn::LateUpdate();
	}

	void Character::Render(HDC Hdc)
	{
		Pawn::Render(Hdc);
	}
}