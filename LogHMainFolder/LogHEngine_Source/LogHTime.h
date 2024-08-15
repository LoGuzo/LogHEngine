#pragma once
#include "Define.h";

namespace LogH
{
	class Time
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC Hdc);

		static float GetDeltaTime() { return DeltaTime; }

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PreFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTime;
	};
}

