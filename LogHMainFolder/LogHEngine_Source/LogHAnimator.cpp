#include "LogHAnimator.h"

namespace LogH
{
	Animator::Animator()
		: Component(Enums::E_ComponentType::Animator)
		, Animations{}
		, CurActiveAnimation(nullptr)
		, bLoop(false)
	{
	}

	Animator::~Animator()
	{
	}

	void Animator::Initialize()
	{
	}

	void Animator::Update()
	{
		if (CurActiveAnimation)
		{
			CurActiveAnimation->Update();
			if (CurActiveAnimation->IsComplete()
				&& bLoop)
			{
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

		CurActiveAnimation = animation;
		CurActiveAnimation->Reset();
		bLoop = loop;
	}
}