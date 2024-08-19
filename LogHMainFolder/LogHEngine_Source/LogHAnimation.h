#pragma once
#include "LogHResource.h"
#include "LogHTexture.h"

namespace LogH
{
	using namespace Graphics;
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 LeftTop;
			Vector2 Size;
			Vector2 Root;
			float Duration;

			Sprite()
				: LeftTop(Vector2::Zero)
				, Size(Vector2::Zero)
				, Root(Vector2::Zero)
				, Duration(0.f)
			{

			}
		};

		Animation();
		~Animation();

		virtual HRESULT Load(const wstring& _Path) override;

		void Update();
		void Render(HDC Hdc);

		void CreateAnimation(const wstring& Name
			, Texture* SpriteSheet
			, Vector2 LeftTop
			, Vector2 Size
			, Vector2 Root
			, UINT SpriteLen
			, float Duration);

		void Reset();

		bool IsComplete() { return bComplete; }
		void SetAnimator(class Animator* _MyAniamtor) { MyAnimator = _MyAniamtor; }

	private:
		class Animator* MyAnimator;
		Texture* MyTexture;

		vector<Sprite> MyAnimation;
		UINT Index;
		float CycleTime;
		bool bComplete;
	};
}