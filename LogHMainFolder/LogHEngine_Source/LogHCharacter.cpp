#include "LogHCharacter.h"
#include "LogHBoxComponent2D.h"

namespace LogH
{
	Character::Character()
	{
		AddComponent<BoxComponent2D>(L"Collision");
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