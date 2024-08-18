#pragma once

#include "..\\LogHEngine_Source\\LogHResourceManager.h"
#include "..\\LogHEngine_Source\\LogHTexture.h"

namespace LogH
{
	void LoadResources()
	{
		ResourceManager::Load<Graphics::Texture>(L"BackGround", L"..\\Resources\\Img\\map\\MonsterMap.png");
		ResourceManager::Load<Graphics::Texture>(L"Player", L"..\\Resources\\Img\\Character\\Player\\Player.png");
		ResourceManager::Load<Graphics::Texture>(L"FlipPlayer", L"..\\Resources\\Img\\Character\\Player\\FilpPlayer.png");
		ResourceManager::Load<Graphics::Texture>(L"Title", L"..\\Resources\\Img\\Title\\Title.png");
	}
}