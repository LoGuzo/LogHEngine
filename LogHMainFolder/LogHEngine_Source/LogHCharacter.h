#pragma once
#include "LogHPawn.h"

namespace LogH
{
	class Character : public Pawn
	{
	public:
		Character();
		~Character();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

	private:
	};
}