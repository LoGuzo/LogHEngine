#include "LogHCollisionManager.h"
#include "LogHScene.h"
#include "LogHSceneManager.h"
#include "LogHShapeComponent.h"

namespace LogH
{
	bitset <(UINT)E_LayerType::Max> CollisionManager::CollisionLayerMatrix[(UINT)E_LayerType::Max] = {};

	void CollisionManager::Initialize()
	{
	}

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)E_LayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)E_LayerType::Max; col++)
			{
				if (CollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (E_LayerType)row, (E_LayerType)col);
				}
			}
		}
	}

	void CollisionManager::LateUpdate()
	{
	}

	void CollisionManager::Render(HDC MHdc)
	{
	}

	void CollisionManager::CollisionLayerCheck(E_LayerType Left, E_LayerType Right, bool Enable)
	{
		int row = 0;
		int col = 0;

		if (Left <= Right)
		{
			row = (UINT)Left;
			col = (UINT)Right;
		}
		else
		{
			row = (UINT)Right;
			col = (UINT)Left;
		}

		CollisionLayerMatrix[row][col] = Enable;
	}

	void CollisionManager::LayerCollision(Scene* _Scene, E_LayerType Left, E_LayerType Right)
	{
		const vector<GameObject*>& Lefts = _Scene->GetLayer(Left)->GetGameObjects();
		const vector<GameObject*>& Rights = _Scene->GetLayer(Left)->GetGameObjects();

		for (GameObject* Left : Lefts)
		{
			if (!Left->IsActive())
				continue;
			ShapeComponent* LeftColl = Left->GetComponent<ShapeComponent>();
			if (!LeftColl)
				continue;

			for (GameObject* Right : Rights)
			{
				if (!Right->IsActive())
					continue;
				ShapeComponent* RightColl = Right->GetComponent<ShapeComponent>();
				if (!RightColl)
					continue;
				if (Left == Right)
					continue;

				ColliderCollision(LeftColl, RightColl);
			}
		}
	}
	void CollisionManager::ColliderCollision(ShapeComponent* Left, ShapeComponent* Right)
	{
	}
}