#include "LogHApplication.h"
#include "LogHInput.h"
#include "LogHTime.h"
#include "LogHSceneManager.h"

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
		AdjustWindeowRect(Hwnd, Width, Height);
		CreateBuffer(Width, Height);
		InitializeEtc();
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
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		ClearRenderTarget();

		Time::Render(MBackHdc);
		SceneManager::Render(MBackHdc);

		CopyRenderTarget(MBackHdc, MHdc);
	}

	void Application::ClearRenderTarget()
	{
		Rectangle(MBackHdc, -1, -1, 1601, 901);
	}

	void Application::CopyRenderTarget(HDC Src, HDC Dest)
	{
		BitBlt(Dest, 0, 0, MWidth, MHeight, Src, 0, 0, SRCCOPY);
	}

	void Application::AdjustWindeowRect(HWND Hwnd, UINT Width, UINT Height)
	{
		MHwnd = Hwnd;
		MHdc = GetDC(Hwnd);

		RECT rect = { 0, 0, Width, Height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		MWidth = rect.right - rect.left;
		MHeight = rect.bottom - rect.top;

		SetWindowPos(Hwnd, nullptr, 0, 0, MWidth, MHeight, 0);
		ShowWindow(Hwnd, true);
	}

	void Application::CreateBuffer(UINT Width, UINT Height)
	{
		MBackBitMap = CreateCompatibleBitmap(MHdc, Width, Height);

		MBackHdc = CreateCompatibleDC(MHdc);

		HBITMAP oldBitMap = (HBITMAP)SelectObject(MBackHdc, MBackBitMap);
		DeleteObject(oldBitMap);

	}

	void Application::InitializeEtc()
	{
		Input::Initailize();
		Time::Initailize();
		SceneManager::Initialize();
	}
}