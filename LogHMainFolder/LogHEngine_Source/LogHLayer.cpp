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

			GameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* GameObj : GameObjects)
		{
			if (GameObj == nullptr)
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

			GameObj->Render(MHdc);
		}
	}

	void Layer::AddGameObject(GameObject* _GameObject)
	{
		if (_GameObject == nullptr)
			return;

		GameObjects.push_back(_GameObject);
	}
}