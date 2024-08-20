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
		LButton, RButton,
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

		__forceinline static bool GetKeyDown(E_KeyCode KeyCode) { return Keys[(UINT)KeyCode].State == E_KeyState::Down; }
		__forceinline static bool GetKeyUp(E_KeyCode KeyCode) { return Keys[(UINT)KeyCode].State == E_KeyState::Up; }
		__forceinline static bool GetKeyPressed(E_KeyCode KeyCode) { return Keys[(UINT)KeyCode].State == E_KeyState::Pressed; }
		__forceinline static Math::Vector2 GetMousePosition() { return MousePosition; }

	private:
		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(Key& _Key);
		static bool IsKeyDown(E_KeyCode _KeyCode);
		static void UpdateKeyDown(Key& _Key);
		static void UpdateKeyUp(Key& _Key);
		static void GetMousePositionByWindow();
		static void ClearKeys();

	private:
		static vector<Key> Keys;
		static Math::Vector2 MousePosition;
	};
}


