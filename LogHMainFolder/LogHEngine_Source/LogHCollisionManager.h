#pragma once
#include "Define.h"

namespace LogH
{
	using namespace Enums;
	class ShapeComponent;

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

	private:
		static bitset <(UINT)E_LayerType::Max> CollisionLayerMatrix[(UINT)E_LayerType::Max];
	};
}