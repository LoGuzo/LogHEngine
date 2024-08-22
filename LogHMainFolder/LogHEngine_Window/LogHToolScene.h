#pragma once
#include "..\\LogHEngine_Source\\LogHScene.h"

namespace LogH
{
    class ToolScene : public Scene
    {
	public:
		ToolScene();
		~ToolScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC MHdc) override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
		
		void Save();
		void Load();

	private:
		vector<class Tile*> Tiles;
    };
}

LRESULT CALLBACK WndTileMapProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);