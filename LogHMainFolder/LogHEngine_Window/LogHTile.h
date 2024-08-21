#pragma once
#include "..\\LogHEngine_Source\\LogHGameObject.h"

namespace LogH
{
	class Tile : public GameObject
	{
	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;
	
	private:

	};
}