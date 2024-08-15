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
		Left, Right, Down, Up,
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

		static bool GetKeyDown(E_KeyCode KeyCode) { return Keys[(UINT)KeyCode].State == E_KeyState::Down; }
		static bool GetKeyUp(E_KeyCode KeyCode) { return Keys[(UINT)KeyCode].State == E_KeyState::Up; }
		static bool GetKeyPressed(E_KeyCode KeyCode) { return Keys[(UINT)KeyCode].State == E_KeyState::Pressed; }
	
	private:
		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(Key& _Key);
		static bool IsKeyDown(E_KeyCode _KeyCode);
		static void UpdateKeyDown(Key& _Key);
		static void UpdateKeyUp(Key& _Key);

	private:
		static vector<Key> Keys;
	};
}


