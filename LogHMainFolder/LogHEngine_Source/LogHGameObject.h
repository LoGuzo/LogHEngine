#pragma once
#include "Define.h"

namespace LogH
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC Hdc);

		void SetPosition(float x, float y)
		{
			Mx = x;
			My = y;
		}

		float GetPositionX() { return Mx; }
		float GetPositionY() { return My; }

	private:
		float Mx;
		float My;
	};
}