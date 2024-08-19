#pragma once
#include "LogHBaseCharacter.h"
#include "LogHAnimator.h"
#include "LogHTexture.h"

namespace LogH
{
    class PlayerCharacter : public BaseCharacter
    {
	public:
		PlayerCharacter();
		~PlayerCharacter();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

	protected:
		virtual void AddIdleAnim() override;
		virtual void AddMoveAnim() override;
		virtual void AddAttackAnim() override;
		virtual void AddDieAnim() override;
    };
}