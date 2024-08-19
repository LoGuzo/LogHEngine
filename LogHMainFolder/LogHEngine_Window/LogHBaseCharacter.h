#pragma once
#include "LogHCharacter.h"
#include "LogHAnimator.h"
#include "LogHTexture.h"

namespace LogH
{
    class BaseCharacter : public Character
    {
	public:
		BaseCharacter(Enums::E_CharacterType _Type);
		~BaseCharacter();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

	protected:
		virtual void AddIdleAnim();
		virtual void AddMoveAnim();
		virtual void AddAttackAnim();
		virtual void AddDieAnim();

	protected:
		Graphics::Texture* CharTexture;
		Graphics::Texture* FlipTexture;
		Animator* MyAnimator;

	private:
		Enums::E_CharacterType Type;
    };
}