#include "LogHTitleScene.h"
//#include "LogHPlayScene.h"
#include "LogHInput.h"
#include "LogHSceneManager.h"

namespace LogH
{
	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(E_KeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void TitleScene::Render(HDC MHdc)
	{
		Scene::Render(MHdc);

		wchar_t str[50] = L"TitleScene";
		TextOut(MHdc, 0, 0, str, 10);
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}