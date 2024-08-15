#include "LogHTitleScene.h"

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
		GameObject* GameObj = new GameObject();
		AddGameObject(GameObj);
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TitleScene::Render(HDC MHdc)
	{
		Scene::Render(MHdc);
	}
}