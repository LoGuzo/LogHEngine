#include "LogHGameObject.h"
#include "LogHTransformComponent.h"
#include "LogHRenderComponent.h"

namespace LogH::object
{
	void Destroy(GameObject* _GameObject)
	{
		if (_GameObject != nullptr)
			_GameObject->Death();
	}
}

namespace LogH
{
	GameObject::GameObject()
		: State(E_State::Active)
		, MComponents{}
	{
		MComponents.resize((UINT)Enums::E_ComponentType::End);
		//AddComponent<RenderComponent>(L"Render");
		AddComponent<TransformComponent>(L"Transform");
	}

	GameObject::~GameObject()
	{
		for (Component* Comp : MComponents)
			SAFE_DELETE(Comp);
	}

	void GameObject::Initialize()
	{
		for (Component* Comp : MComponents)
		{
			if (!Comp)
				continue;

			Comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* Comp : MComponents)
		{
			if (!Comp)
				continue;

			Comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* Comp : MComponents)
		{
			if (!Comp)
				continue;

			Comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC Hdc)
	{
		for (Component* Comp : MComponents)
		{
			if (!Comp)
				continue;

			Comp->Render(Hdc);
		}
	}
	void GameObject::SetActive(bool Power)
	{
		if (Power) State = E_State::Active;
		if (Power) State = E_State::Paused;
	}
}
