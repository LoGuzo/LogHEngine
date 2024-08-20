#pragma once
#include "LogHResource.h"

namespace LogH
{
	class ResourceManager
	{
	public:
		template<typename T>
		static T* Find(const wstring& Key);

		template<typename T>
		static T* Load(const wstring& Key, const wstring& Path);

		static void Insert(const wstring& Key, Resource* _Resource);

	private:
		static map<wstring, Resource*> Resources;
	};

	template<typename T>
	static T* ResourceManager::Find(const wstring& Key)
	{
		auto iter = Resources.find(Key);

		if (iter == Resources.end())
			return nullptr;

		return dynamic_cast<T*>(iter->second);
	}

	template<typename T>
	static T* ResourceManager::Load(const wstring& Key, const wstring& Path)
	{
		T* resource = ResourceManager::Find<T>(Key);
		if (resource)
			return resource;

		resource = new T();
		if (FAILED(resource->Load(Path)))
			assert(false);

		resource->SetName(Key);
		resource->SetPath(Path);

		Resources.insert(make_pair(Key, resource));

		return resource;
	}

}