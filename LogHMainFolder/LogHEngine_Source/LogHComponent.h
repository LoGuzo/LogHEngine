#pragma once
#include "Define.h"
#include "LogHEntity.h"

namespace LogH
{
	class GameObject;

	class Component : public Entity
	{
	public:
		Component(Enums::E_ComponentType _Type);
		virtual ~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC Hdc);

		void SetOwner(GameObject* _Owner);
		GameObject* GetOwner() { return Owner; }
		Enums::E_ComponentType GetType() { return Type; }

	private:
		Enums::E_ComponentType Type;

		GameObject* Owner;
	};
}