#include "LogHPlayScene.h"
#include "LogHCharacter.h"

namespace LogH
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		Character* GameObj = new Character();
		AddGameObject(GameObj);
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC MHdc)
	{
		Scene::Render(MHdc);
	}
}