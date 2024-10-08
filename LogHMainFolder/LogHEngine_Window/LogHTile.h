#pragma once
#include "..\\LogHEngine_Source\\LogHGameObject.h"

namespace LogH
{
	class Tile : public GameObject
	{
	public:
		Tile();
		~Tile();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		void SetIndexPosition(int x, int y);

	private:

	};
}