#include "Mario.h"
#include "LogHPlayerInputComponent.h"
#include "LogHBoxComponent2D.h"

namespace LogH
{
	Mario::Mario()
	{
		AddComponent<PlayerInputComponent>(L"InputComponent");

		BoxComponent2D* Collision = GetComponent<BoxComponent2D>();
		Collision->SetRoot(Vector2(-10.f, -18.f));
		Collision->SetSize(Vector2(22.f, 36.f));
	}

	Mario::~Mario()
	{
	}

	void Mario::Initialize()
	{
		PlayerCharacter::Initialize();
	}

	void Mario::Update()
	{
		PlayerCharacter::Update();
	}

	void Mario::LateUpdate()
	{
		PlayerCharacter::LateUpdate();
	}

	void Mario::Render(HDC Hdc)
	{
		PlayerCharacter::Render(Hdc);
	}

	void Mario::AddIdleAnim()
	{
		MyAnimator->CreateAnimation(L"RightIdle", CharTexture
			, Vector2(1.f, 52.f), Vector2(32.f, 32.f), Vector2::Zero, 1, 0.1f);
		MyAnimator->CreateAnimation(L"LeftIdle", FlipTexture
			, Vector2(1.f, 52.f), Vector2(32.f, 32.f), Vector2::Zero, 1, 0.1f);
	}

	void Mario::AddMoveAnim()
	{
		MyAnimator->CreateAnimation(L"RightMove", CharTexture
			, Vector2(75.f, 52.f), Vector2(32.f, 32.f), Vector2::Zero, 3, 0.1f);
		MyAnimator->CreateAnimation(L"LeftMove", FlipTexture
			, Vector2(75.f, 52.f), Vector2(32.f, 32.f), Vector2::Zero, 3, 0.1f);

		MyAnimator->CreateAnimation(L"RightJump", CharTexture
			, Vector2(215.f, 52.f), Vector2(32.f, 32.f), Vector2::Zero, 2, 0.1f);
		MyAnimator->CreateAnimation(L"LeftJump", FlipTexture
			, Vector2(215.f, 52.f), Vector2(32.f, 32.f), Vector2::Zero, 2, 0.1f);

		MyAnimator->CreateAnimation(L"RightCrounch", CharTexture
			, Vector2(38.f, 52.f), Vector2(32.f, 32.f), Vector2::Zero, 1, 0.1f);
		MyAnimator->CreateAnimation(L"LeftCrounch", FlipTexture
			, Vector2(38.f, 52.f), Vector2(32.f, 32.f), Vector2::Zero, 1, 0.1f);
	}

	void Mario::AddAttackAnim()
	{

	}
	void Mario::AddDieAnim()
	{
	}
}