#pragma once
#include "LogHPlayerCharacter.h"

namespace LogH
{
	class Mario : public PlayerCharacter
	{
	public:
		Mario();
		~Mario();

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