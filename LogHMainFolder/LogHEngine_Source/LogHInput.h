#pragma once
#include "Define.h"

namespace LogH
{
	enum class E_KeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class E_KeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			E_KeyCode KeyCode;
			E_KeyState State;
			bool bPressed;
		};

		static void Initailize();
		static void Update();

		static bool GetKeyDown(E_KeyCode KeyCode) { return mKeys[(UINT)KeyCode].State == E_KeyState::Down; }
		static bool GetKeyUp(E_KeyCode KeyCode) { return mKeys[(UINT)KeyCode].State == E_KeyState::Up; }
		static bool GetKeyPressed(E_KeyCode KeyCode) { return mKeys[(UINT)KeyCode].State == E_KeyState::Pressed; }

	private:
		static vector<Key> mKeys;
	};
}


