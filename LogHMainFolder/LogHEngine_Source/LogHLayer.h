#pragma once
#include "LogHEntity.h"
#include "LogHGameObject.h"

namespace LogH
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC MHdc);
		virtual void Destory();

		void AddGameObject(GameObject* _GameObject);

	private:
		vector<GameObject*> GameObjects;
	};

	typedef vector<GameObject*>::iterator GameObjectIter;
}