#pragma once
#include "LogHComponent.h"
#include "LogHAnimation.h"
#include "LogHTexture.h"

namespace LogH
{
	class Animator : public Component
	{
	public:
		Animator();
		~Animator();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		void CreateAnimation(const wstring& Name
			, Graphics::Texture* SpriteSheet
			, Enums::E_AnimDirectionType Type
			, Vector2 LeftTop
			, Vector2 Size
			, Vector2 Root
			, UINT SpriteLen
			, float Duration);

		Animation* FindAnimation(const std::wstring& Name);
		void PlayAnimation(const wstring& Name, bool loop = true);

	private:
		map<wstring, Animation*> Animations;
		Animation* CurActiveAnimation;
		bool bLoop;
	};
}