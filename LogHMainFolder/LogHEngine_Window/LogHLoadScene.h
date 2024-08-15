#pragma once

#include "..\\LogHEngine_Source\\LogHSceneManager.h"
#include "LogHPlayScene.h"
#include "LogHEndScene.h"
#include "LogHTitleScene.h"

namespace LogH
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}