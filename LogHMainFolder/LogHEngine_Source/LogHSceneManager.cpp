#include "LogHSceneManager.h"
namespace LogH
{
	map<wstring, Scene*> SceneManager::MScene = {};
	Scene* SceneManager::MActiveScene = nullptr;

	Scene* SceneManager::LoadScene(const wstring& Name)
	{
		if(MActiveScene)
			MActiveScene->OnExit();
		map<wstring, Scene*>::iterator iter = MScene.find(Name);

		if (iter == MScene.end())
			return nullptr;

		MActiveScene = iter->second;
		if (MActiveScene)
			MActiveScene->OnEnter();

		return iter->second;
	};

	void SceneManager::Initialize()
	{
	}

	void SceneManager::Update()
	{
		MActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		MActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC MHdc)
	{
		MActiveScene->Render(MHdc);
	}

	void SceneManager::Release()
	{
		for (auto& iter : MScene)
			SAFE_DELETE(iter.second);

		SAFE_DELETE(MActiveScene);
	}
}