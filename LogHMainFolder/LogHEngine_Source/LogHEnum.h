#pragma once

namespace LogH :: Enums
{
	enum class E_ComponentType
	{
		Transform,
		Collider,
		Rigidbody,
		Input,
		Renderer,
		Animator,
		Camera,
		End,
	};

	enum class E_LayerType
	{
		None,
		BackGreound,
		Tile,
		//Tree,
		Player,
		Enemy,
		Particle,
		Max = 16,
	};

	enum class E_ResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};

	enum class E_CharacterType
	{
		Player,
		Enemy,
		Npc,
		End,
	};

	enum class E_ColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};
}