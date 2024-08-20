#include "LogHResourceManager.h"

namespace LogH
{
	map<wstring, Resource*> ResourceManager::Resources = {};

	void ResourceManager::Insert(const wstring& Key, Resource* _Resource)
	{
		if (Key == L"")
			return;
		if (!_Resource)
			return;

		Resources.insert(make_pair(Key, _Resource));
	}

}