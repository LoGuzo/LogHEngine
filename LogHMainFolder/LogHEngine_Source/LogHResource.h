#pragma once
#include "LogHEntity.h"


namespace LogH
{
	class Resource : public Entity
	{
	public:
		Resource(Enums::E_ResourceType _Type);
		~Resource();

		virtual HRESULT Load(const wstring& _Path) = 0;

		const wstring& GetPath() { return Path; }
		void SetPath(const wstring& _Path) { Path = _Path; }

	private:
		Enums::E_ResourceType Type;
		wstring Path;
	};
}