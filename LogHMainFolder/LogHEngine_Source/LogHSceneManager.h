#pragma once
#include "LogHScene.h"

namespace LogH
{
	class SceneManager
	{
	public:
		template<typename T>
		static Scene* CreateScene(const wstring& Name);

		static Scene* LoadScene(const wstring& Name);
		static Scene* GetActiveScene() { return MActiveScene; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC MHdc);
		static void Release();

	private:
		static map<wstring, Scene*> MScene;
		static Scene* MActiveScene;
	};

	template <typename T>
	static Scene* SceneManager::CreateScene(const wstring& Name)
	{
		T* MyScene = new T();
		MyScene->SetName(Name);
		MActiveScene = MyScene;
		MyScene->Initialize();

		MScene.insert(make_pair(Name, MyScene));

		return MyScene;
	};
}