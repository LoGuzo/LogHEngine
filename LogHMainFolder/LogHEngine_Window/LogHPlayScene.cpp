#include "LogHPlayScene.h"
//#include "LogHTitleScene.h"
#include "LogHInput.h"
#include "LogHSceneManager.h"
#include "LogHPlayerCharacter.h"
#include "LogHRenderComponent.h"
#include "LogHTransformComponent.h"
#include "LogHObject.h"

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
		MyPlayerCharacter = Object::Instantiate<PlayerCharacter>
			(E_LayerType::BackGreound, Vector2(100.f, 100.f));

		RenderComponent* rc = MyPlayerCharacter->GetComponent<RenderComponent>();
		rc->ImageLoad(L"..\\Resources\\CloudOcean.png");
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(E_KeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC MHdc)
	{
		Scene::Render(MHdc);

		wchar_t str[50] = L"PlayScene";
		TextOut(MHdc, 0, 0, str, 9);
	}
	void PlayScene::OnEnter()
	{

	}
	void PlayScene::OnExit()
	{
		TransformComponent* tr = MyPlayerCharacter->GetComponent<TransformComponent>();
		tr->SetPosition(Vector2(0, 0));
	}
}