#pragma once
#include "LogHCharacter.h"
#include "LogHAnimator.h"
#include "LogHTexture.h"

namespace LogH
{
    class PlayerCharacter : public Character
    {
	public:
		PlayerCharacter();
		~PlayerCharacter();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

	private:
		void AddIdleAnim();
		void AddMoveAnim();
		void AddAttackAnim();
		void AddDieAnim();

	private:
		Graphics::Texture* CharTexture;
		Graphics::Texture* FlipCharTexture;
		Animator* MyAnimator;
    };
}