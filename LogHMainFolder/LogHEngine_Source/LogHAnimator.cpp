#include "LogHAnimator.h"
#include "LogHResourceManager.h"

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
		for (auto& iter : MyEvents)
			SAFE_DELETE(iter.second);
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

	void Animator::CreateAnimationByFolder(const wstring& Name, const wstring& Path, Vector2 Root, float Duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(Name);

		if (animation)
			return;

		int FileCount = 0;

		filesystem::path fs(Path);
		vector<Graphics::Texture*> Imgs = {};
		for (auto& p : filesystem::recursive_directory_iterator(fs))
		{
			wstring FileName = p.path().filename();
			wstring FullName = p.path();

			Graphics::Texture* texture = ResourceManager::Load<Graphics::Texture>(FileName, FullName);
			Imgs.push_back(texture);
			FileCount++;
		}

		UINT SheetWidth = Imgs[0]->GetWidth() * FileCount;
		UINT SheetHeight = Imgs[0]->GetHeight();

		Graphics::Texture* SpriteSheet = Graphics::Texture::Create(Name, SheetWidth, SheetHeight);

		UINT ImgWidth = Imgs[0]->GetWidth();
		UINT ImgHeight = Imgs[0]->GetHeight();

		for (size_t i = 0; i < Imgs.size(); i++)
		{
			BitBlt(SpriteSheet->GetHdc(), i * ImgWidth, 0
				, ImgWidth, ImgHeight
				, Imgs[i]->GetHdc(), 0, 0, SRCCOPY);
		}

		CreateAnimation(Name, SpriteSheet, Vector2::Zero, Vector2(ImgWidth, ImgHeight), Root, FileCount, Duration);
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

		if (CurActiveAnimation)
		{
			Events* PreEvents = FindEvents(CurActiveAnimation->GetName());
			if (PreEvents)
				PreEvents->EndEvent();
		}

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
		Events* events = FindEvents(Name);
		return events->CompleteEvent.MyEvent;
	}

	function<void()>& Animator::GetEndEvent(const wstring& Name)
	{
		Events* events = FindEvents(Name);
		return events->EndEvent.MyEvent;
	}
}