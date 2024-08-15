#pragma once
#include "LogHGameObject.h"

namespace LogH
{
	class Actor : public GameObject
	{
	public:
		Actor();
		~Actor();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;
	private:

	};
}
