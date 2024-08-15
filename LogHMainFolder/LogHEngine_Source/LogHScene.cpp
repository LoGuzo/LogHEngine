#include "LogHScene.h"

namespace LogH
{
	Scene::Scene()
		:MGameObjects{}
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
	}

	void Scene::Update()
	{
		for (GameObject* GameObj : MGameObjects)
		{
			GameObj->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* GameObj : MGameObjects)
		{
			GameObj->LateUpdate();
		}
	}

	void Scene::Render(HDC MHdc)
	{
		for (GameObject* GameObj : MGameObjects)
		{
			GameObj->Render(MHdc);
		}
	}
	void Scene::AddGameObject(GameObject* gameObject)
	{
		MGameObjects.push_back(gameObject);
	}
}