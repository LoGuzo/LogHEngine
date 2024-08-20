#include "LogHLayer.h"

namespace LogH
{
	Layer::Layer()
		:GameObjects{}
	{
	}

	Layer::~Layer()
	{
		for (GameObject* GameObj : GameObjects)
			SAFE_DELETE(GameObj);
	}

	void Layer::Initialize()
	{
		for (GameObject* GameObj : GameObjects)
		{
			if (GameObj == nullptr)
				continue;


			GameObj->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* GameObj : GameObjects)
		{
			if (GameObj == nullptr)
				continue;

			GameObject::E_State state = GameObj->GetActive();
			if (state == GameObject::E_State::Paused
				|| state == GameObject::E_State::Dead)
				continue;

			GameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* GameObj : GameObjects)
		{
			if (GameObj == nullptr)
				continue;

			GameObject::E_State state = GameObj->GetActive();
			if (state == GameObject::E_State::Paused
				|| state == GameObject::E_State::Dead)
				continue;

			GameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC MHdc)
	{
		for (GameObject* GameObj : GameObjects)
		{
			if (GameObj == nullptr)
				continue;

			GameObject::E_State state = GameObj->GetActive();
			if (state == GameObject::E_State::Paused
				|| state == GameObject::E_State::Dead)
				continue;

			GameObj->Render(MHdc);
		}
	}

	void Layer::Destory()
	{
		for (GameObjectIter iter = GameObjects.begin()
			; iter != GameObjects.end()
			; )
		{
			GameObject::E_State Active = (*iter)->GetActive();
			if (Active == GameObject::E_State::Dead)
			{
				GameObject* DeathObj = (*iter);
				iter = GameObjects.erase(iter);

				SAFE_DELETE(DeathObj);

				continue;
			}
			iter++;
		}
	}

	void Layer::AddGameObject(GameObject* _GameObject)
	{
		if (_GameObject == nullptr)
			return;

		GameObjects.push_back(_GameObject);
	}
}