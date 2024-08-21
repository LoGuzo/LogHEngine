#include "LogHToolScene.h"
#include "LogHCameraComponent.h"
#include "LogHObject.h"
#include "LogHTile.h"
#include "LogHTilemapRender.h"
#include "LogHResourceManager.h"
#include "LogHTexture.h"

namespace LogH
{
	ToolScene::ToolScene()
	{
	}

	ToolScene::~ToolScene()
	{
	}

	void ToolScene::Initialize()
	{
		GameObject* CameraObj = Object::Instantiate<GameObject>
			(E_LayerType::None, Vector2(256.f, 256.f));

		CameraComponent* CameraComp = CameraObj->AddComponent<CameraComponent>(L"Camera");
		//Renderer::MainCamera = CameraComp;

		Tile* tile = Object::Instantiate<Tile>(E_LayerType::Tile);
		TilemapRender* Tmr = tile->AddComponent<TilemapRender>(L"TileMapRender");

		Tmr->SetTexture(ResourceManager::Find<Graphics::Texture>(L"TileMap"));

		Scene::Initialize();
	}

	void ToolScene::Update()
	{
		Scene::Update();
	}

	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void ToolScene::Render(HDC MHdc)
	{
		Scene::Render(MHdc);

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(MHdc, 16 * i, 0, NULL);
			LineTo(MHdc, 16 * i, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(MHdc, 0, 16 * i, NULL);
			LineTo(MHdc, 1000, 16 * i);
		}
	}

	void ToolScene::OnEnter()
	{
	}

	void ToolScene::OnExit()
	{
	}
}