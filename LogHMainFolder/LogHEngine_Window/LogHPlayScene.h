#pragma once
#include "..\\LogHEngine_Source\\LogHScene.h"

namespace LogH
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC MHdc) override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

		void Load();
	private:
		class GameObject* BackGroundObj;
		class PlayerCharacter* MyPlayerCharacter;
		class EnemyCharacter* EnemyMush;
	};
}