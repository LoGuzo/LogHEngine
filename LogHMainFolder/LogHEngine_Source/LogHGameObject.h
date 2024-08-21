#pragma once
#include "Define.h"
#include "LogHComponent.h"

class Component;

namespace LogH::object
{
	void Destroy(GameObject* _GameObject);
}

namespace LogH
{
	class GameObject
	{
	public:
		friend void object::Destroy(GameObject* Obj);

		enum class E_State
		{
			Active,
			Paused,
			Dead,
			End,
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC Hdc);

		template<typename T>
		T* AddComponent(wstring Name);
		
		template<typename T>
		T* GetComponent();

		E_State GetActive() { return State; }
		void SetActive(bool Power);
		bool IsActive() { return State == E_State::Active; }

		bool IsDead() { return State == E_State::Dead; }
		
	private:
		void Death() { State = E_State::Dead; }

	private:
		vector<Component*> MComponents;
		E_State State;
	};


	template<typename T>
	T* GameObject::AddComponent(wstring Name)
	{
		T* Comp = new T();
		Comp->SetOwner(this);
		Comp->Initialize();
		Comp->SetName(Name);

		MComponents[(UINT)Comp->GetType()] = Comp;

		return Comp;
	}

	template<typename T>
	T* GameObject::GetComponent()
	{
		T* MyComponent = nullptr;
		for (Component* Comp : MComponents)
		{
			MyComponent = dynamic_cast<T*>(Comp);
			if (MyComponent)
				break;
		}

		return MyComponent;
	}
}