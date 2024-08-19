#pragma once
#include "LogHComponent.h"
#include "LogHAnimation.h"
#include "LogHTexture.h"

namespace LogH
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator=(function<void()> Func)
			{
				MyEvent = move(Func);
			}

			void operator()()
			{
				if (MyEvent)
					MyEvent;
			}

			function<void()> MyEvent;
		};

		struct Events
		{
			Event StartEvent;
			Event CompleteEvent;
			Event EndEvent;
		};

		Animator();
		~Animator();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		void CreateAnimation(const wstring& Name
			, Graphics::Texture* SpriteSheet
			, Vector2 LeftTop
			, Vector2 Size
			, Vector2 Root
			, UINT SpriteLen
			, float Duration);

		Animation* FindAnimation(const std::wstring& Name);
		void PlayAnimation(const wstring& Name, bool loop = true);

		Events* FindEvents(const wstring& Name);

		function<void()>& GetStartEvent(const wstring& Name);
		function<void()>& GetCompleteEvent(const wstring& Name);
		function<void()>& GetEndEvent(const wstring& Name);

		bool IsCompleteAnimation() { return CurActiveAnimation->IsComplete(); }

	private:
		map<wstring, Animation*> Animations;
		Animation* CurActiveAnimation;
		bool bLoop;

		map<wstring, Events*> MyEvents;
	};
}