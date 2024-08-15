#pragma once
#include "LogHEntity.h"
#include "LogHGameObject.h"

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

		void AddGameObject(GameObject* gameObject);
	private:
		vector<GameObject*> MGameObjects;
	};
}
