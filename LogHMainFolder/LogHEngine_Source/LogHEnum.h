#pragma once

namespace LogH :: Enums
{
	enum class E_ComponentType
	{
		Input,
		Transform,
		Renderer,
		Camera,
		End,
	};

	enum class E_LayerType
	{
		None,
		BackGreound,
		//Tree,
		Character,
		Player,
		Max = 16,
	};

	enum class E_ResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}