#pragma once

#include "..\\LogHEngine_Source\\LogHResourceManager.h"
#include "..\\LogHEngine_Source\\LogHTexture.h"

namespace LogH
{
	void LoadResources()
	{
		ResourceManager::Load<Graphics::Texture>(L"BackGround", L"..\\Resources\\Img\\map\\MonsterMap.png");
		ResourceManager::Load<Graphics::Texture>(L"Character", L"..\\Resources\\Img\\Pacman\\1.png");
		ResourceManager::Load<Graphics::Texture>(L"Title", L"..\\Resources\\Img\\Title\\Title.png");
	}
}