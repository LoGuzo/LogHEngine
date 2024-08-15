#pragma once
#include "Define.h"
#include "LogHEntity.h"

namespace LogH
{
	class GameObject;

	class Component : public Entity
	{
	public:
		Component();
		virtual ~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC Hdc);

		void SetOwner(GameObject* _Owner);
		GameObject* GetOwner() { return Owner; }

	private:
		GameObject* Owner;
	};
}