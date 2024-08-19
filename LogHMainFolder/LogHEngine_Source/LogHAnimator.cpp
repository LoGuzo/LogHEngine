#include "LogHAnimator.h"

namespace LogH
{
	Animator::Animator()
		: Component(Enums::E_ComponentType::Animator)
		, Animations{}
		, MyEvents{}
		, CurActiveAnimation(nullptr)
		, bLoop(false)
	{
	}

	Animator::~Animator()
	{
		for (auto& iter : MyEvents)
			SAFE_DELETE(iter.second);

		for (auto& iter : Animations)
			SAFE_DELETE(iter.second);

		SAFE_DELETE(CurActiveAnimation);
	}

	void Animator::Initialize()
	{
	}

	void Animator::Update()
	{
		if (CurActiveAnimation)
		{
			CurActiveAnimation->Update();

			Events* events = FindEvents(CurActiveAnimation->GetName());
			if (CurActiveAnimation->IsComplete())
			{
				if(events)
					events->CompleteEvent();

				if(bLoop)
					CurActiveAnimation->Reset();
			}
		}
	}

	void Animator::LateUpdate()
	{
	}

	void Animator::Render(HDC Hdc)
	{
		if (CurActiveAnimation)
			CurActiveAnimation->Render(Hdc);
	}

	void Animator::CreateAnimation(const wstring& Name
		, Graphics::Texture* SpriteSheet
		, Vector2 LeftTop
		, Vector2 Size, Vector2 Root
		, UINT SpriteLen, float Duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(Name);

		if (animation)
			return;

		animation = new Animation();
		animation->CreateAnimation(Name, SpriteSheet
			, LeftTop, Size, Root, SpriteLen, Duration);

		animation->SetAnimator(this);

		Events* events = new Events();
		if (events)
			MyEvents.insert(make_pair(Name, events));

		Animations.insert(make_pair(Name, animation));
	}

	Animation* Animator::FindAnimation(const std::wstring& Name)
	{
		auto iter = Animations.find(Name);
		if (iter == Animations.end())
			return nullptr;
		return iter->second;
	}

	void Animator::PlayAnimation(const wstring& Name, bool loop)
	{
		Animation* animation = FindAnimation(Name);
		if (!animation)
			return;

		Events* PreEvents = FindEvents(CurActiveAnimation->GetName());
		if(PreEvents)
			PreEvents->EndEvent();
		
		Events* NextEvents = FindEvents(animation->GetName());
		if(NextEvents)
			NextEvents->StartEvent();

		CurActiveAnimation = animation;
		CurActiveAnimation->Reset();

		bLoop = loop;
	}

	Animator::Events* Animator::FindEvents(const wstring& Name)
	{
		auto iter = MyEvents.find(Name);
		if (iter == MyEvents.end())
			return nullptr;

		return iter->second;
	}

	function<void()>& Animator::GetStartEvent(const wstring& Name)
	{
		Events* events = FindEvents(Name);
		return events->StartEvent.MyEvent;
	}

	function<void()>& Animator::GetCompleteEvent(const wstring& Name)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(Name);
		return events->CompleteEvent.MyEvent;
	}

	function<void()>& Animator::GetEndEvent(const wstring& Name)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(Name);
		return events->EndEvent.MyEvent;
	}
}