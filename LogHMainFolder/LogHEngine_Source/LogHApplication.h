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

		void Initialize(HWND Hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND MHwnd;
		HDC MHdc;

		GameObject MPlayer;
	};
}

