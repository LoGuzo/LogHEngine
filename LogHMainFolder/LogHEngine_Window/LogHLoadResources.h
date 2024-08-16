#pragma once

#include "..\\LogHEngine_Source\\LogHResourceManager.h"
#include "..\\LogHEngine_Source\\LogHTexture.h"

namespace LogH
{
	void LoadResources()
	{
		ResourceManager::Load<Graphics::Texture>(L"BackGround", L"..\\Resources\\CloudOcean.png");
	}
}