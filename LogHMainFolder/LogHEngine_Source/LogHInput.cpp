#include "LogHInput.h"
#include "LogHApplication.h"

extern LogH::Application App;

namespace LogH
{
	vector<Input::Key> Input::Keys = {};
	Math::Vector2 MousePosition = Math::Vector2::One;

	int ASCII[(int)E_KeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON, VK_RBUTTON,
	};

	void Input::Initailize()
	{
		CreateKeys();
	}

	void Input::Update()
	{
		UpdateKeys();
	}

	void Input::CreateKeys()
	{
		for (size_t i = 0; i < (UINT)E_KeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.State = E_KeyState::None;
			key.KeyCode = (E_KeyCode)i;

			Keys.push_back(key);
		}
	}

	void Input::UpdateKeys()
	{
		for_each(Keys.begin(), Keys.end(),
			[](Key& _Key) -> void
			{
				UpdateKey(_Key);
			});
	}

	void Input::UpdateKey(Input::Key& _Key)
	{
		if (GetFocus())
		{
			if (IsKeyDown(_Key.KeyCode))
				UpdateKeyDown(_Key);
			else
				UpdateKeyUp(_Key);

			GetMousePositionByWindow();
		}
		else
		{
			ClearKeys();
		}
	}

	bool Input::IsKeyDown(E_KeyCode _KeyCode)
	{
		return GetAsyncKeyState(ASCII[(UINT)_KeyCode]) & 0x8000;
	}

	void Input::UpdateKeyDown(Key& _Key)
	{
		if (_Key.bPressed == true)
			_Key.State = E_KeyState::Pressed;
		else
			_Key.State = E_KeyState::Down;
		_Key.bPressed = true;
	}

	void Input::UpdateKeyUp(Key& _Key)
	{
		if (_Key.bPressed == true)
			_Key.State = E_KeyState::Up;
		else
			_Key.State = E_KeyState::None;
		_Key.bPressed = false;
	}
	void Input::GetMousePositionByWindow()
	{
		POINT MousePos = {};
		GetCursorPos(&MousePos);

		ScreenToClient(App.GetHwnd(), &MousePos);

		MousePosition.x = MousePos.x;
		MousePosition.y = MousePos.y;
	}

	void Input::ClearKeys()
	{
		for (Key& key : Keys)
		{
			if (key.State == E_KeyState::Down || key.State == E_KeyState::Down)
				key.State = E_KeyState::Up;
			else if (key.State == E_KeyState::Up)
				key.State = E_KeyState::None;

			key.bPressed = false;
		}
	}
}