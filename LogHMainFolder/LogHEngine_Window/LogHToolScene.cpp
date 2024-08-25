#include "LogHToolScene.h"
#include "LogHCameraComponent.h"
#include "LogHCameraScriptComponent.h"
#include "LogHObject.h"
#include "LogHTile.h"
#include "LogHTilemapRender.h"
#include "LogHResourceManager.h"
#include "LogHTexture.h"
#include "LogHInput.h"
#include "LogHRenderer.h"

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
			(E_LayerType::Particle, Vector2(256.f, 256.f));

		CameraComponent* CameraComp = CameraObj->AddComponent<CameraComponent>(L"Camera");
		CameraObj->AddComponent<CameraScriptComponent>(L"CameraScript");

		Renderer::MainCamera = CameraComp;

		Scene::Initialize();
	}

	void ToolScene::Update()
	{
		Scene::Update();
	}

	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(E_KeyCode::LButton))
		{
			Vector2 Pos = Input::GetMousePosition();
			
			if (Pos.x >= 0.f && Pos.y >= 0.f)
			{
				Pos = Renderer::MainCamera->CalculateTilePosition(Pos);

				int IdxX = Pos.x / TilemapRender::FinalTileSize.x;
				int IdxY = Pos.y / TilemapRender::FinalTileSize.y;

				Tile* tile = Object::Instantiate<Tile>(E_LayerType::Tile);
				TilemapRender* Tmr = tile->AddComponent<TilemapRender>(L"TileMapRender");
				Tmr->SetTexture(ResourceManager::Find<Graphics::Texture>(L"TileMap"));
				Tmr->SetIndex(TilemapRender::SelectedIndex);
				
				int CurX = IdxX * TilemapRender::FinalTileSize.x;
				int CurY = IdxY * TilemapRender::FinalTileSize.y;

				tile->SetIndexPosition(CurX, CurY);
				Tiles.push_back(tile);
			}
		}

		if (Input::GetKeyDown(E_KeyCode::S))
		{
			Save();
		}

		if (Input::GetKeyDown(E_KeyCode::L))
		{
			Load();
		}
	}

	void ToolScene::Render(HDC MHdc)
	{
		Scene::Render(MHdc);

		for (size_t i = 0; i < 100; i++)
		{
			Vector2 Pos = Renderer::MainCamera->CalculatePosition(
				Vector2(TilemapRender::FinalTileSize.x * i, 0.f));

			MoveToEx(MHdc, Pos.x, 0, NULL);
			LineTo(MHdc, Pos.x, 1000);
		}

		for (size_t i = 0; i < 21; i++)
		{

			Vector2 Pos = Renderer::MainCamera->CalculatePosition(
				Vector2(0.f, TilemapRender::FinalTileSize.y * i));

			MoveToEx(MHdc, 0, Pos.y, NULL);
			LineTo(MHdc, 1000, Pos.y);
		}
	}

	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}

	void ToolScene::Save()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetSaveFileName(&ofn))
			return;


		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"wb");

		for (Tile* tile : Tiles)
		{
			TilemapRender* Tmr = tile->GetComponent<TilemapRender>();
			TransformComponent* Tc = tile->GetComponent<TransformComponent>();

			Vector2 sourceIndex = Tmr->GetIndex();
			Vector2 position = Tc->GetPosition();

			if (sourceIndex.x == -1 || sourceIndex.y == -1)
				continue;

			int x = sourceIndex.x;
			fwrite(&x, sizeof(int), 1, pFile);
			int y = sourceIndex.y;
			fwrite(&y, sizeof(int), 1, pFile);

			x = position.x;
			fwrite(&x, sizeof(int), 1, pFile);
			y = position.y;
			fwrite(&y, sizeof(int), 1, pFile);
		}

		fclose(pFile);
	}

	void ToolScene::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;


		if (false == GetOpenFileName(&ofn))
			return;

		Tiles.clear();

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");

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

			if (IdxX == -1 || IdxY == -1)
				continue;

			Tile* tile = Object::Instantiate<Tile>(E_LayerType::Tile, Vector2(PosX, PosY));
			TilemapRender* Tmr = tile->AddComponent<TilemapRender>(L"TileMapRender");
			Tmr->SetTexture(ResourceManager::Find<Graphics::Texture>(L"TileMap"));
			Tmr->SetIndex(Vector2(IdxX, IdxY));

			Tiles.push_back(tile);
		}

		fclose(pFile);
	}
}

LRESULT CALLBACK WndTileMapProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);
		LogH::Math::Vector2 mousePosition;
		mousePosition.x = mousePos.x;
		mousePosition.y = mousePos.y;
		int idxX = mousePosition.x / 17.f / 3.f;
		int idxY = mousePosition.y / 17.f / 3.f;
		LogH::TilemapRender::SelectedIndex = LogH::Math::Vector2(idxX, idxY);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		LogH::Graphics::Texture* texture
			= LogH::ResourceManager::Find<LogH::Graphics::Texture>(L"TileMap");

		TransparentBlt(hdc, 0, 0
			, texture->GetWidth() * 3
			, texture->GetHeight() * 3
			, texture->GetHdc(), 0, 0, texture->GetWidth(), texture->GetHeight()
			, RGB(255, 0, 255));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
