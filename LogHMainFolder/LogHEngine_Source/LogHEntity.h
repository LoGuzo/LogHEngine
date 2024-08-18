#pragma once
#include "Define.h"

namespace LogH
{
	using namespace Math;
	class Entity
	{

	public:
		Entity();
		virtual ~Entity();

		void SetName(const wstring& Name) { MName = Name; }
		wstring GetName() { return MName; }

	private:
		wstring MName;
	};
}
