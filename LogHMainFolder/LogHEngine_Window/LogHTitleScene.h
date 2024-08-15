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

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC MHdc) override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:

	};
}