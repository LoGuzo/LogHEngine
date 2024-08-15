#pragma once
#include "LogHScene.h"
#include "..\\LogHEngine_Source\\LogHScene.h"

namespace LogH
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC MHdc) override;

	private:

	};
}