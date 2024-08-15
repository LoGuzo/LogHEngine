#include "LogHPlayScene.h"
#include "LogHPlayerCharacter.h"
#include "LogHRenderComponent.h"

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
		PlayerCharacter* MyPlayerCharacter = new PlayerCharacter();

		RenderComponent* rc = MyPlayerCharacter->GetComponent<RenderComponent>();
		rc->ImageLoad(L"..\\Resources\\CloudOcean.png");
		AddGameObject(MyPlayerCharacter);
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