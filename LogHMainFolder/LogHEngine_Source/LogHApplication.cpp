#include "LogHApplication.h"
#include "LogHInput.h"
#include "LogHTime.h"

namespace LogH
{
	Application::Application()
		:MHwnd(nullptr)
		, MHdc(nullptr)
		, MWidth(0)
		, MHeight(0)
		, MBackHdc(nullptr)
		, MBackBitMap(nullptr)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND Hwnd, UINT Width, UINT Height)
	{
		MHwnd = Hwnd;
		MHdc = GetDC(Hwnd);

		RECT rect = { 0,0,Width,Height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		MWidth = rect.right - rect.left;
		MHeight = rect.bottom - rect.top;

		SetWindowPos(MHwnd, nullptr, 0, 0, MWidth, MHeight, 0);
		ShowWindow(MHwnd, true);

		MBackBitMap = CreateCompatibleBitmap(MHdc, Width, Height);

		MBackHdc = CreateCompatibleDC(MHdc);

		HBITMAP oldBitMap = (HBITMAP)SelectObject(MBackHdc, MBackBitMap);
		DeleteObject(oldBitMap);

		MPlayer.SetPosition(0.f, 0.f);

		Input::Initailize();
		Time::Initailize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		MPlayer.Update();
	}

	void Application::LateUpdate()
	{
		MPlayer.LateUpdate();
	}

	void Application::Render()
	{
		Rectangle(MBackHdc, 0, 0, 1600, 900);

		Time::Render(MBackHdc);
		MPlayer.Render(MBackHdc);

		BitBlt(MHdc, 0, 0, MWidth, MHeight, MBackHdc, 0, 0, SRCCOPY);
	}
}