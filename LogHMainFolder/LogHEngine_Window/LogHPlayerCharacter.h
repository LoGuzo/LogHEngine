#pragma once
#include "LogHCharacter.h"

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
    };
}