#pragma once

#include "..\\LogHEngine_Source\\LogHSceneManager.h"
#include "LogHPlayScene.h"
#include "LogHEndScene.h"
#include "LogHTitleScene.h"
#include "LogHToolScene.h"

namespace LogH
{
	void LoadScenes()
	{
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<ToolScene>(L"ToolScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}