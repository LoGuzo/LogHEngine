#include "LogHScene.h"
#include "LogHCollisionManager.h"

namespace LogH
{
	Scene::Scene()
		:Layers{}
	{
		CreateLayers();
	}

	Scene::~Scene()
	{
		for (Layer* layer : Layers)
			SAFE_DELETE(layer);
	}

	void Scene::Initialize()
	{
		CollisionManager::CollisionLayerCheck(E_LayerType::Player, E_LayerType::Enemy, true);

		for (Layer* layer : Layers)
		{
			if (layer == nullptr)
				continue;

			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer* layer : Layers)
		{
			if (layer == nullptr)
				continue;

			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : Layers)
		{
			if (layer == nullptr)
				continue;

			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC MHdc)
	{
		for (Layer* layer : Layers)
		{
			if (layer == nullptr)
				continue;

			layer->Render(MHdc);
		}
	}

	void Scene::Destroy()
	{
		for (Layer* layer : Layers)
		{
			if (layer == nullptr)
				continue;

			layer->Destory();
		}
	}

	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
	}

	void Scene::AddGameObject(GameObject* _GameObject, const E_LayerType Type)
	{
		Layers[(UINT)Type]->AddGameObject(_GameObject);
	}

	void Scene::CreateLayers()
	{
		Layers.resize((UINT)E_LayerType::Max);
		for (size_t i = 0; i < (UINT)E_LayerType::Max; i++)
		{
			Layers[i] = new Layer();
		}
	}

}