#include "LogHTime.h"

namespace LogH
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PreFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTime = 0.f;

	void Time::Initailize()
	{
		// Cpu Frequency;
		QueryPerformanceFrequency(&CpuFrequency);

		// Current Frequency Begin Program
		QueryPerformanceCounter(&PreFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float DiffFrequency = static_cast<float>(CurrentFrequency.QuadPart - PreFrequency.QuadPart);
		DeltaTime = DiffFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PreFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC Hdc)
	{
		static float time = 0.f;

		time += DeltaTime;
		float fps = 1.f / DeltaTime;

		wchar_t str[50] = L"";
		wchar_t fpsstr[50] = L"";

		swprintf_s(str, 50, L"Time : %f", (float)time);
		swprintf_s(fpsstr, 50, L"Fps : %f", (float)fps);
		int len = wcsnlen_s(str, 50);
		int fpslen = wcsnlen_s(fpsstr, 50);

		TextOut(Hdc, 0, 0, str, len);
		TextOut(Hdc, 0, 20, fpsstr, fpslen);
	}
}