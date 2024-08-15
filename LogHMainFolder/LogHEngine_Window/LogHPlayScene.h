#pragma once
#include "..\\LogHEngine_Source\\LogHScene.h"

namespace LogH
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC MHdc) override;

	private:

	};
}