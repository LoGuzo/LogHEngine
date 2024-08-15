#pragma once
#include "..\\LogHEngine_Source\\LogHScene.h"

namespace LogH
{
	class EndScene : public Scene
	{
	public:
		EndScene();
		~EndScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC MHdc) override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:

	};
}