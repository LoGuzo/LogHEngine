#pragma once

namespace LogH :: Enums
{
	enum class E_ComponentType
	{
		Transform,
		Colider,
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
	};
}