#include "LogHApplication.h"
#include "LogHInput.h"
#include "LogHTime.h"
#include "LogHSceneManager.h"
#include "LogHCollisionManager.h"

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

		CollisionManager::Initialize();
		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();

		Destroy();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();
		CollisionManager::Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		ClearRenderTarget();

		Time::Render(MBackHdc);
		CollisionManager::Render(MBackHdc);
		SceneManager::Render(MBackHdc);

		CopyRenderTarget(MBackHdc, MHdc);
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::Release()
	{
		SceneManager::Release();
	}

	void Application::ClearRenderTarget()
	{
		HBRUSH GrayBrush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH OldBrush = (HBRUSH)SelectObject(MBackHdc, GrayBrush);

		Rectangle(MBackHdc, -1, -1, 1601, 901);

		(HBRUSH)SelectObject(MBackHdc, OldBrush);
		DeleteObject(GrayBrush);
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