#pragma once
#include "LogHEntity.h"
#include "LogHGameObject.h"
#include "LogHLayer.h"

namespace LogH
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC MHdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* _GameObject, const E_LayerType Type);

	private:
		void CreateLayers();

	private:
		vector<Layer*> Layers;
	};
}
