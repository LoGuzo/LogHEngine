#include "LogHApplication.h"
#include "LogHInput.h"

namespace LogH
{
	Application::Application()
		:MHwnd(nullptr)
		, MHdc(nullptr)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND Hwnd)
	{
		MHwnd = Hwnd;
		MHdc = GetDC(Hwnd);

		MPlayer.SetPosition(0.f, 0.f);

		Input::Initailize();
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

		MPlayer.Update();
	}

	void Application::LateUpdate()
	{
		MPlayer.LateUpdate();
	}

	void Application::Render()
	{
		MPlayer.Render(MHdc);
	}
}