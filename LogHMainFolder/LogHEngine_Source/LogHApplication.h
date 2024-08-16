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

		HDC GetHdc() { return MHdc; }
		UINT GetWidth() { return MWidth; }
		UINT GetHeight() { return MHeight; }

	private:
		void ClearRenderTarget();
		void CopyRenderTarget(HDC Src, HDC Dest);
		void AdjustWindeowRect(HWND Hwnd, UINT Width, UINT Height);
		void CreateBuffer(UINT Width, UINT Height);
		void InitializeEtc();

	private:
		HWND MHwnd;
		HDC MHdc;

		HDC MBackHdc;
		HBITMAP MBackBitMap;

		UINT MWidth;
		UINT MHeight;
	};
}

