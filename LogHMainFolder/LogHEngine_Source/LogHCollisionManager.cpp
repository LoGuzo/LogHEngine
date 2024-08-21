#include "LogHCollisionManager.h"
#include "LogHScene.h"
#include "LogHSceneManager.h"
#include "LogHShapeComponent.h"
#include "LogHTransformComponent.h"

namespace LogH
{
	bitset <(UINT)E_LayerType::Max> CollisionManager::CollisionLayerMatrix[(UINT)E_LayerType::Max] = {};
	unordered_map<UINT64, bool> CollisionManager::CollisionMap = {};

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
		const vector<GameObject*>& Rights = _Scene->GetLayer(Right)->GetGameObjects();

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
		CollisionID id = {};
		id.Left = Left->GetID();
		id.Right = Right->GetID();

		auto iter = CollisionMap.find(id.ID);
		if (iter == CollisionMap.end())
		{
			CollisionMap.insert(make_pair(id.ID, false));
			iter = CollisionMap.find(id.ID);
		}

		if (Intersect(Left, Right))
		{
			// 최초 충돌
			if (!iter->second)
			{
				Left->OnCollisionOnEnter(Right);
				Right->OnCollisionOnEnter(Left);
				iter->second = true;
			}
			else // 이미 충돌
			{
				Left->OnCollisionOnStay(Right);
				Right->OnCollisionOnStay(Left);
			}
		}
		else
		{
			if (iter->second) // 충돌 종료
			{
				Left->OnCollisionOnExit(Right);
				Right->OnCollisionOnExit(Left);
				iter->second = false;
			}
		}
	}

	bool CollisionManager::Intersect(ShapeComponent* Left, ShapeComponent* Right)
	{
		TransformComponent* LeftTc = Left->GetOwner()->GetComponent<TransformComponent>();
		TransformComponent* RightTc = Right->GetOwner()->GetComponent<TransformComponent>();

		Vector2 LeftPos = LeftTc->GetPosition() + Left->GetRoot();
		Vector2 RightPos = RightTc->GetPosition() + Right->GetRoot();

		Vector2 LeftSize = Left->GetSize();
		Vector2 RightSize = Right->GetSize();

		Enums::E_ColliderType LeftType = Left->GetType();
		Enums::E_ColliderType RightType = Left->GetType();

		if (LeftType == Enums::E_ColliderType::Rect2D 
			&& RightType == Enums::E_ColliderType::Rect2D)
		{
			//AABB 충돌
			if (fabs(LeftPos.x - RightPos.x) < fabs(LeftSize.x / 2.f + RightSize.x / 2.f)
				&& fabs(LeftPos.y - RightPos.y) < fabs(LeftSize.y / 2.f + RightSize.y / 2.f))
			{
				return true;
			}
		}

		if (LeftType == Enums::E_ColliderType::Circle2D
			&& RightType == Enums::E_ColliderType::Circle2D)
		{
			Vector2 LeftCirclePos = LeftPos + (LeftSize / 2.f);
			Vector2 RightCirclePos = RightPos + (RightSize / 2.f);

			float Distance = (LeftCirclePos - RightCirclePos).Length();
			if (Distance <= (LeftSize.x / 2.f + RightSize.x / 2.f))
			{
				return true;
			}
		}

		return false;
	}
}