#include "LogHTitleScene.h"
//#include "LogHPlayScene.h"
#include "LogHInput.h"
#include "LogHObject.h"
#include "LogHSceneManager.h"
#include "LogHRenderComponent.h"
#include "LogHResourceManager.h"
#include "LogHTransformComponent.h"
#include "LogHTexture.h"
#include "LogHRenderer.h"

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
		GameObject* BackGroundObj = Object::Instantiate<GameObject>
			(E_LayerType::BackGreound, Vector2(0.f, 0.f));

		RenderComponent* BackRc = BackGroundObj->AddComponent<RenderComponent>(L"Render");

		Graphics::Texture* bg = ResourceManager::Find<Graphics::Texture>(L"Title");
		BackRc->SetTexture(bg);

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
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}