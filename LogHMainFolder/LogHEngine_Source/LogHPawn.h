#pragma once
#include "LogHActor.h"

namespace LogH
{
    class Pawn : public Actor
    {
	public:
		Pawn();
		~Pawn();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

	private:
    };
}