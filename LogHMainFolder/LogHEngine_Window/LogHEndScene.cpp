#include "LogHEndScene.h"

namespace LogH
{
	EndScene::EndScene()
	{
	}

	EndScene::~EndScene()
	{
	}

	void EndScene::Initialize()
	{
		GameObject* GameObj = new GameObject();
		AddGameObject(GameObj);
	}

	void EndScene::Update()
	{
		Scene::Update();
	}

	void EndScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void EndScene::Render(HDC MHdc)
	{
		Scene::Render(MHdc);
	}
}