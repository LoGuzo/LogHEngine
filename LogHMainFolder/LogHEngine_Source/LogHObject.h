#pragma once
#include "LogHComponent.h"
#include "LogHGameObject.h"
#include "LogHLayer.h"
#include "LogHScene.h"
#include "LogHSceneManager.h"
#include "LogHTransformComponent.h"

namespace LogH::Object
{
	template<typename T>
	static T* Instantiate(Enums::E_LayerType Type)
	{
		T* gameObject = new GameObject();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(Type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template<typename T>
	static T* Instantiate(Enums::E_LayerType Type, Math::Vector2 Position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(Type);
		layer->AddGameObject(gameObject);

		TransformComponent* tr = gameObject->GetComponent<TransformComponent>();
		tr->SetPosition(Position);

		return gameObject;
	}

	static void Destroy(GameObject* Object)
	{
		Object->Death();
	}
}