#pragma once
#include "Define.h"
#include "LogHGameObject.h"

namespace LogH
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND Hwnd, UINT Width, UINT MHeight);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND MHwnd;
		HDC MHdc;

		HDC MBackHdc;
		HBITMAP MBackBuffer;

		UINT MWidth;
		UINT MHeight;

		GameObject MPlayer;
	};
}

