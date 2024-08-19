#pragma once
#include "LogHEnemyCharacter.h"

namespace LogH
{
    class MushRoom : public EnemyCharacter
    {
	public:
		MushRoom();
		~MushRoom();

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