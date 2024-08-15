#pragma once

#include "..\\LogHEngine_Source\\LogHSceneManager.h"
#include "LogHPlayScene.h"
#include "LogHEndScene.h"
#include "LogHTitleScene.h"

namespace LogH
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}