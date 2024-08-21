#pragma once
#include "Define.h"

namespace LogH
{
	using namespace Enums;
	class ShapeComponent;

	union CollisionID
	{
		struct
		{
			UINT32 Left;
			UINT32 Right;
		};

		UINT64 ID;
	};

	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC MHdc);

		static void CollisionLayerCheck(E_LayerType Left, E_LayerType Right, bool Enable);
		static void LayerCollision(class Scene* _Scene, E_LayerType Left, E_LayerType Right);
		static void ColliderCollision(ShapeComponent* Left, ShapeComponent* Right);
		static bool Intersect(ShapeComponent* Left, ShapeComponent* Right);

	private:
		static bitset <(UINT)E_LayerType::Max> CollisionLayerMatrix[(UINT)E_LayerType::Max];
		static unordered_map<UINT64, bool> CollisionMap;
	};
}