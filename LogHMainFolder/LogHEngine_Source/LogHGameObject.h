#pragma once
#include "Define.h"
#include "LogHComponent.h"

class Component;

namespace LogH
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC Hdc);

		template<typename T>
		T* AddComponent();
		
		template<typename T>
		T* GetComponent();

	private:
		vector<Component*> MComponents;
	};


	template<typename T>
	T* GameObject::AddComponent()
	{
		T* Comp = new T();
		Comp->SetOwner(this);

		MComponents.push_back(Comp);

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