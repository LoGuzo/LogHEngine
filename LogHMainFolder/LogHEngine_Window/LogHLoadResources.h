#pragma once

#include "..\\LogHEngine_Source\\LogHResourceManager.h"
#include "..\\LogHEngine_Source\\LogHTexture.h"

namespace LogH
{
	void LoadResources()
	{
		ResourceManager::Load<Graphics::Texture>(L"BackGround", L"..\\Resources\\Img\\map\\MarioMap1.png");

		ResourceManager::Load<Graphics::Texture>(L"Mario", L"..\\Resources\\Img\\Character\\Mario1.bmp");
		ResourceManager::Load<Graphics::Texture>(L"MarioFlip", L"..\\Resources\\Img\\Character\\Flip_Mario1.bmp");

		ResourceManager::Load<Graphics::Texture>(L"Enemy", L"..\\Resources\\Img\\Character\\Enemy1.bmp");
		ResourceManager::Load<Graphics::Texture>(L"EnemyFlip", L"..\\Resources\\Img\\Character\\Flip_Enemy1.bmp");
		
		ResourceManager::Load<Graphics::Texture>(L"TileMap", L"..\\Resources\\Img\\TileMap\\TileMap.bmp");

		ResourceManager::Load<Graphics::Texture>(L"Title", L"..\\Resources\\Img\\Title\\MarioMap1.png");
	}
}