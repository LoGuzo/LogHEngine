#include "LogHPlayScene.h"
#include "LogHAnimator.h"
#include "LogHCameraComponent.h"
#include "LogHInput.h"
#include "LogHSceneManager.h"
#include "LogHObject.h"
#include "LogHGameObject.h"
#include "LogHRenderComponent.h"
#include "LogHResourceManager.h"
#include "LogHTransformComponent.h"
#include "LogHTexture.h"
#include "LogHRenderer.h"
#include "LogHTile.h"
#include "LogHTilemapRender.h"
#include "Mario.h"
#include "MushRoom.h"

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
		//Load();

		GameObject* CameraObj = Object::Instantiate<GameObject>
			(E_LayerType::None, Vector2(256.f, 256.f));

		CameraComponent* CameraComp = CameraObj->AddComponent<CameraComponent>(L"Camera");
		//Renderer::MainCamera = CameraComp;

		MyPlayerCharacter = Object::Instantiate<Mario>
			(E_LayerType::Player, Vector2(50.f, 50.f));

		EnemyMush = Object::Instantiate<MushRoom>
			(E_LayerType::Enemy, Vector2(200.f, 200.f));

		BackGroundObj = Object::Instantiate<GameObject>
			(E_LayerType::BackGreound, Vector2(0.f, 0.f));
		
		RenderComponent* BackRc = BackGroundObj->AddComponent<RenderComponent>(L"Render");

		Graphics::Texture* bg = ResourceManager::Find<Graphics::Texture>(L"BackGround");
		BackRc->SetTexture(bg);

		Scene::Initialize();
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
	}
	void PlayScene::OnEnter()
	{

	}
	void PlayScene::OnExit()
	{
		TransformComponent* BackTr = BackGroundObj->GetComponent<TransformComponent>();
		BackTr->SetPosition(Vector2(0, 0));
	}

	void PlayScene::Load()
	{
		FILE* pFile = nullptr;
		_wfopen_s(&pFile, L"..\\Resources\\SaveMapData\\Test", L"rb");

		while (true)
		{
			int IdxX = 0;
			int IdxY = 0;

			int PosX = 0;
			int PosY = 0;


			if (fread(&IdxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&IdxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&PosX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&PosY, sizeof(int), 1, pFile) == NULL)
				break;

			Tile* tile = Object::Instantiate<Tile>(E_LayerType::Tile, Vector2(PosX, PosY));
			TilemapRender* Tmr = tile->AddComponent<TilemapRender>(L"TileMapRender");
			Tmr->SetTexture(ResourceManager::Find<Graphics::Texture>(L"TileMap"));
			Tmr->SetIndex(Vector2(IdxX, IdxY));

			//Tiles.push_back(tile);
		}

		fclose(pFile);
	}
}