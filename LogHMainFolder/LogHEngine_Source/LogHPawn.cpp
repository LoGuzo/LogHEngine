#include "LogHPawn.h"
#include "LogHInputComponent.h"

namespace LogH
{
	Pawn::Pawn()
	{
	}

	Pawn::~Pawn()
	{
	}

	void Pawn::Initialize()
	{
		Actor::Initialize();
	}

	void Pawn::Update()
	{
		Actor::Update();
	}

	void Pawn::LateUpdate()
	{
		Actor::LateUpdate();
	}

	void Pawn::Render(HDC Hdc)
	{
		Actor::Render(Hdc);
	}
}