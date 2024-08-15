#pragma once
#include "..\\LogHEngine_Source\\LogHScene.h"

namespace LogH
{
	class EndScene : public Scene
	{
	public:
		EndScene();
		~EndScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC MHdc) override;

	private:

	};
}